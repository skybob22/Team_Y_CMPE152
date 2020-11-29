#include <vector>
#include <set>

#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/Symtab.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/type/TypeChecker.h"
#include "intermediate/util/CrossReferencer.h"
#include "frontend/SemanticErrorHandler.h"
#include "frontend/Semantics.h"

namespace intermediate { namespace symtab {
        int Symtab::unnamedIndex = 0;
    }}

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;
using namespace intermediate::util;

int Semantics::typeCount(Typespec *type){
    int count = 0;

    if (type->getForm() == ENUMERATION){
        vector<SymtabEntry *> *constants = type->getEnumerationConstants();
        count = constants->size();
    }
    else{
        int minValue = type->getSubrangeMinValue();
        int maxValue = type->getSubrangeMaxValue();
        count = maxValue - minValue + 1;
    }

    return count;
}

void Semantics::checkCallArguments(
        CParser::ArgumentListContext *listCtx, vector<SymtabEntry *> *parms)
{
    int parmsCount = parms->size();
    int argsCount = listCtx != nullptr ? listCtx->argument().size() : 0;

    if (parmsCount != argsCount){
        error.flag(ARGUMENT_COUNT_MISMATCH, listCtx);
        return;
    }

    // Check each argument against the corresponding parameter.
    for (int i = 0; i < parmsCount; i++){
        CParser::ArgumentContext *argCtx = listCtx->argument()[i];
        CParser::ExpressionContext *exprCtx = argCtx->expression();
        visit(exprCtx);

        SymtabEntry *parmId = (*parms)[i];
        Typespec *parmType = parmId->getType();
        Typespec *argType  = exprCtx->type;

        // For a VAR parameter, the argument must be a variable
        // with the same datatype.
        if (parmId->getKind() == REFERENCE_PARAMETER){
            if (expressionIsVariable(exprCtx)){
                if (parmType != argType){
                    error.flag(TYPE_MISMATCH, exprCtx);
                }
            }
            else{
                error.flag(ARGUMENT_MUST_BE_VARIABLE, exprCtx);
            }
        }

            // For a value parameter, the argument type must be
            // assignment compatible with the parameter type.
        else if (!TypeChecker::areAssignmentCompatible(parmType, argType)){
            error.flag(TYPE_MISMATCH, exprCtx);
        }
    }
}

bool Semantics::expressionIsVariable(CParser::ExpressionContext *exprCtx){
    // Only a single simple expression?
    if (exprCtx->simpleExpression().size() == 1){
        CParser::SimpleExpressionContext *simpleCtx =
                exprCtx->simpleExpression()[0];
        // Only a single term?
        if (simpleCtx->term().size() == 1){
            CParser::TermContext *termCtx = simpleCtx->term()[0];

            // Only a single factor?
            if (termCtx->factor().size() == 1){
                return dynamic_cast<CParser::VariableFactorContext *>(
                               termCtx->factor()[0]) != nullptr;
            }
        }
    }

    return false;
}

Typespec *Semantics::variableDatatype(CParser::VariableContext *varCtx,
                                      Typespec *varType)
{
    Typespec *type = varType;

    // Subscripts.
    if (varCtx->modifier() != nullptr){
        CParser::IndexContext *indexCtx = varCtx->modifier()->index();
        // Get the subscript.
        if (type->getForm() == ARRAY){
            Typespec *indexType = type->getArrayIndexType();
            CParser::ExpressionContext *exprCtx =
                    indexCtx->expression();
            visit(exprCtx);

            if (indexType->baseType() != exprCtx->type->baseType()){
                error.flag(TYPE_MISMATCH, exprCtx);
            }

            // Datatype of the next dimension.
            type = type->getArrayElementType();
        }
        else{
            error.flag(TOO_MANY_SUBSCRIPTS, indexCtx);
        }
    }

    return type;
}
void Semantics::postErrorCheck(){
    //Need to do this at the end of parsing
    for(auto entry : symtabStack->getLocalSymtab()->sortedEntries()){
        if(entry->getKind() == FUNCTION || entry->getKind() == PROCEDURE){
            //Check if function or procedure do not have defined execuables (function body)
            bool exPresent = entry->getRoutineCode() == DEFINED;
            if(!exPresent){
                int lineNumber = entry->getLineNumbers()->front();
                string errorMessage = "Function '" + entry->getName() + "' is not defined";
                error.flag(Error::FUNCTION_NOT_DEFINED,lineNumber,errorMessage);
            }
        }
    }
}

int Semantics::getErrorCount() const{
    return error.getCount();
}


Object Semantics::visitProgram(CParser::ProgramContext *ctx){
    //C doesn't have a defined program name, pick so use input when creating the object to extract filename
    programId = symtabStack->enterLocal(programName, PROGRAM);
    programId->setRoutineSymtab(symtabStack->push());
    ctx->entry = programId;

    symtabStack->setProgramId(programId);
    symtabStack->getLocalSymtab()->setOwner(programId);

    visitChildren(ctx);

    CrossReferencer crossReferencer;
    crossReferencer.print(symtabStack);

    postErrorCheck();

    return nullptr;
}

Object Semantics::visitFunctionDeclaration(CParser::FunctionDeclarationContext *ctx){
    //TODO: Ideally should do parsing here instead of FunctionDefinition, move if time
    visit(ctx->typeIdentifier());

    CParser::FunctionIdentifierContext *idCtx = ctx->functionIdentifier();
    CParser::ParameterDeclarationsListContext *parameters = ctx->parameterDeclarationsList();

    int lineNumber = idCtx->getStart()->getLine();
    bool nonVoid = ctx->typeIdentifier()->type != Predefined::voidType;

    Typespec *returnType = nullptr;
    string routineName;

    routineName = idCtx->IDENTIFIER()->getText();
    SymtabEntry *routineId = symtabStack->lookupLocal(routineName);

    if (routineId != nullptr){
        error.flag(REDECLARED_IDENTIFIER,
                   ctx->getStart()->getLine(), routineName);
        return nullptr;
    }

    routineId = symtabStack->enterLocal(routineName, nonVoid ? FUNCTION : PROCEDURE);
    routineId->setRoutineCode(DECLARED);
    idCtx->entry = routineId;

    // Append to the parent routine's list of subroutines.
    SymtabEntry *parentId = symtabStack->getLocalSymtab()->getOwner();
    parentId->appendSubroutine(routineId);

    routineId->setRoutineSymtab(symtabStack->push());
    idCtx->entry = routineId;

    Symtab *symtab = symtabStack->getLocalSymtab();
    symtab->setOwner(routineId);


    if (parameters != nullptr){
        vector<SymtabEntry *> *parameterIds =
                visit(parameters).as<vector<SymtabEntry *>*>();
        routineId->setRoutineParameters(parameterIds);

        for (SymtabEntry *parmId : *parameterIds)
        {
            parmId->setSlotNumber(symtab->nextSlotNumber());
        }
    }

    if (nonVoid){
        CParser::TypeIdentifierContext *typeIdCtx = ctx->typeIdentifier();
        visit(typeIdCtx);
        returnType = typeIdCtx->type;

        //Removed due to causing problems with boolean
        /*if (returnType->getForm() != SCALAR)
        {
            error.flag(INVALID_RETURN_TYPE, typeIdCtx);
            returnType = Predefined::integerType;
        }*/

        routineId->setType(returnType);
        idCtx->type = returnType;
    }
    else{
        idCtx->type = Predefined::voidType;
    }
    idCtx->entry->appendLineNumber(lineNumber);

    // Enter the function's associated variable into its symbol table.
    // Removed due to using "return" can put back if want to change under-the-hood behavior
    /*if (nonVoid)
    {
        SymtabEntry *assocVarId =
                symtabStack->enterLocal(routineName, VARIABLE);
        assocVarId->setSlotNumber(symtab->nextSlotNumber());
        assocVarId->setType(returnType);
    }*/
    symtabStack->pop();
    return nullptr;
}

Object Semantics::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx){
    CParser::FunctionDeclarationContext *fdCtx = ctx->functionDeclaration();
    string routineName = fdCtx->functionIdentifier()->getText();
    SymtabEntry *routineId = symtabStack->lookupLocal(routineName);

    //Combined declaration and definition
    if (routineId == nullptr){
        visit(fdCtx);
        //Now that it has been visited, reload routineId
        routineId = symtabStack->lookupLocal(routineName);
    }
    else{
        //Update the identifier to have the Symtab and Type of the declaration
        ctx->functionDeclaration()->functionIdentifier()->entry = routineId;
        ctx->functionDeclaration()->functionIdentifier()->type = routineId->getType();
    }
    //Else, separate declaration and definition

    //Check if function is already defined
    if(routineId->getRoutineCode() == DEFINED){
        error.flag(REDEFINED_IDENTIFIER,
                   ctx->getStart()->getLine(), routineName);
        return nullptr;
    }

    //Push the proper symtab stack
    symtabStack->push(routineId->getRoutineSymtab());
    visit(ctx->controlScope());
    routineId->setExecutable(ctx->controlScope());
    routineId->setRoutineCode(DEFINED);

    symtabStack->pop();
    return nullptr;
}

Object Semantics::visitParameterDeclarationsList(CParser::ParameterDeclarationsListContext *ctx){
    vector<SymtabEntry *> *parameterList = new vector<SymtabEntry *>();

    // Loop over the parameter declarations.
    for (CParser::ParameterDeclarationContext *dclCtx : ctx->parameterDeclaration())
    {
        vector<SymtabEntry *> parameterSublist =
                visit(dclCtx).as<vector<SymtabEntry *>>();
        for (SymtabEntry *id : parameterSublist) parameterList->push_back(id);
    }

    return parameterList;
}

Object Semantics::visitParameterDeclaration(CParser::ParameterDeclarationContext *ctx){


    Kind kind = VALUE_PARAMETER;
    CParser::TypeIdentifierContext *typeCtx = ctx->typeIdentifier();

    visit(typeCtx);
    Typespec *parmType = typeCtx->type;

    vector<SymtabEntry *> parameterSublist;

    CParser::ParameterIdentifierContext *idCtx = ctx->parameterIdentifier();
    int lineNumber = idCtx->getStart()->getLine();
    string parmName = toLowerCase(idCtx->IDENTIFIER()->getText());
    SymtabEntry *parmId = symtabStack->lookupLocal(parmName);

    if (parmId == nullptr)
    {
        parmId = symtabStack->enterLocal(parmName, kind);
        parmId->setType(parmType);
    }
    else
    {
        error.flag(REDECLARED_IDENTIFIER, idCtx);
    }

    idCtx->entry = parmId;
    idCtx->type  = parmType;

    parameterSublist.push_back(parmId);
    parmId->appendLineNumber(lineNumber);

    return parameterSublist;
}

Object Semantics::visitVariableDeclaration(CParser::VariableDeclarationContext *ctx){
    if(ctx->length()){
        //TODO: Array declarations
    }
    else{
        CParser::TypeIdentifierContext *typeCtx = ctx->typeIdentifier();
        visit(typeCtx);

        for(unsigned int i=0;i<ctx->variableIdentifier().size();i++){
            CParser::VariableIdentifierContext *idCtx = ctx->variableIdentifier(i);

            int lineNumber = idCtx->getStart()->getLine();
            string variableName = idCtx->IDENTIFIER()->getText();
            SymtabEntry *variableId = symtabStack->lookupLocal(variableName);

            if (variableId == nullptr)
            {
                variableId = symtabStack->enterLocal(variableName, VARIABLE);
                variableId->setType(typeCtx->type);

                // Assign slot numbers to local variables.
                Symtab *symtab = variableId->getSymtab();
                if (symtab->getNestingLevel() > 1)
                {
                    variableId->setSlotNumber(symtab->nextSlotNumber());
                }

                idCtx->entry = variableId;
            }
            else
            {
                error.flag(REDECLARED_IDENTIFIER, ctx);
            }

            variableId->appendLineNumber(lineNumber);
        }
    }

    return nullptr;
}

Object Semantics::visitTypeIdentifier(CParser::TypeIdentifierContext *ctx){
    string typeName = ctx->getText();
    SymtabEntry *typeId = symtabStack->lookup(typeName);

    if (typeId != nullptr)
    {
        if (typeId->getKind() != TYPE)
        {
            error.flag(INVALID_TYPE, ctx);
            ctx->type = Predefined::integerType;
        }
        else
        {
            ctx->type = typeId->getType();
        }

        typeId->appendLineNumber(ctx->start->getLine());
    }
    else
    {
        error.flag(UNDECLARED_IDENTIFIER, ctx);
        ctx->type = Predefined::integerType;
    }

    ctx->entry = typeId;
    return nullptr;
}

Object Semantics::visitLhs(CParser::LhsContext *ctx){
    if(ctx->variable()){
        CParser::VariableContext *varCtx = ctx->variable();
        visit(varCtx);
        ctx->type = varCtx->type;
    }
    else{
        CParser::VariableDeclarationContext *varDecCtx = ctx->variableDeclaration();
        visit(varDecCtx);
        ctx->type = ctx->variableDeclaration()->typeIdentifier()->type;;
    }
    return nullptr;
}

Object Semantics::visitAssignVariable(CParser::AssignVariableContext *ctx){
    CParser::LhsContext *lhsCtx = ctx->lhs();
    CParser::RhsContext *rhsCtx = ctx->rhs();

    visitChildren(ctx);

    Typespec *lhsType = lhsCtx->type;
    Typespec *rhsType = rhsCtx->expression()->type;

    if (!TypeChecker::areAssignmentCompatible(lhsType, rhsType))
    {
        error.flag(INCOMPATIBLE_ASSIGNMENT, ctx);
    }

    return nullptr;
}

Object Semantics::visitDecrementVariable(CParser::DecrementVariableContext *ctx){
    CParser::VariableContext *vCtx = ctx->variable();
    visit(vCtx);
    if(vCtx->type->getForm() != SCALAR){
        error.flag(TYPE_MUST_BE_NUMERIC,ctx);
    }
    return nullptr;
}

Object Semantics::visitIncrementVariable(CParser::IncrementVariableContext *ctx){
    CParser::VariableContext *vCtx = ctx->variable();
    visit(vCtx);
    if(vCtx->type->getForm() != SCALAR){
        error.flag(TYPE_MUST_BE_NUMERIC,ctx);
    }
    return nullptr;
}

Object Semantics::visitDoWhileLoop(CParser::DoWhileLoopContext *ctx){
    CParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;

    if (!TypeChecker::isBoolean(exprType))
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }

    visit(ctx->controlScope());
    return nullptr;
}

Object Semantics::visitWhileLoop(CParser::WhileLoopContext *ctx){
    CParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;

    if (!TypeChecker::isBoolean(exprType))
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }

    visit(ctx->controlScope());
    return nullptr;
}

Object Semantics::visitForLoop(CParser::ForLoopContext *ctx){
    //Visit the init and end-loop statements
    for(CParser::StatementContext *sCtx : ctx->statement()){
        visit(sCtx);
    }

    CParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    Typespec *exprType = exprCtx->type;

    if (!TypeChecker::isBoolean(exprType))
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }

    visit(ctx->controlScope());
    return nullptr;
}

Object Semantics::visitIfStatement(CParser::IfStatementContext *ctx){
    //Required if(condition)
    CParser::ExpressionContext *exprCtx  = ctx->expression(0);
    visit(exprCtx);
    Typespec *expr_type = exprCtx->type;
    if (!TypeChecker::isBoolean(expr_type))    {
        error.flag(TYPE_MUST_BE_BOOLEAN, exprCtx);
    }
    visit(ctx->controlScope(0));

    //Optional else if conditions
    int numElseIf = ctx->IF().size() - 1;
    //We know there is at least 1 'if', so the number of 'else if' is the number of 'if' - 1
    for(int i=0;i<numElseIf;i++){
        CParser::ExpressionContext *ie_exprCtx  = ctx->expression(1+i);
        visit(ie_exprCtx);
        Typespec *ie_expr_type = ie_exprCtx->type;
        if (!TypeChecker::isBoolean(ie_expr_type))        {
            error.flag(TYPE_MUST_BE_BOOLEAN, ie_exprCtx);
        }
        visit(ctx->controlScope(i+1));
    }

    //Optional else condition
    //If number of 'if' and 'else' are different by more than 1, we know there is an else at the end
    bool elsePresent = (ctx->IF().size() - 1) != ctx->ELSE().size();
    if(elsePresent){
        CParser::ExpressionContext *e_exprCtx  = ctx->expression().back();
        visit(e_exprCtx);
        Typespec *e_expr_type = e_exprCtx->type;
        if (!TypeChecker::isBoolean(e_expr_type))        {
            error.flag(TYPE_MUST_BE_BOOLEAN, e_exprCtx);
        }
        visit(ctx->controlScope().back());
    }

    return nullptr;
}

Object Semantics::visitFunctionCall(CParser::FunctionCallContext *ctx){
    //Can be treated like procedure call since we know in this case the value isn't being stored
    CParser::FunctionIdentifierContext*nameCtx = ctx->functionIdentifier();
    CParser::ArgumentListContext *listCtx = ctx->argumentList();
    string name = toLowerCase(ctx->functionIdentifier()->getText());
    SymtabEntry *procedureId = symtabStack->lookup(name);
    bool badName = false;

    if (procedureId == nullptr)
    {
        error.flag(UNDECLARED_IDENTIFIER, nameCtx);
        badName = true;
    }
    else if (procedureId->getKind() != PROCEDURE)
    {
        error.flag(NAME_MUST_BE_PROCEDURE, nameCtx);
        badName = true;
    }

    // Bad procedure name. Do a simple arguments check and then leave.
    if (badName)
    {
        for (CParser::ArgumentContext *exprCtx : listCtx->argument())
        {
            visit(exprCtx);
        }
    }

        // Good procedure name.
    else
    {
        vector<SymtabEntry *> *parms = procedureId->getRoutineParameters();
        checkCallArguments(listCtx, parms);
    }

    nameCtx->entry = procedureId;
    return nullptr;
}

Object Semantics::visitFunctionCallFactor(CParser::FunctionCallFactorContext *ctx){
    CParser::FunctionCallContext *callCtx = ctx->functionCall();
    CParser::FunctionIdentifierContext *nameCtx = callCtx->functionIdentifier();
    CParser::ArgumentListContext *listCtx = callCtx->argumentList();
    string name = toLowerCase(callCtx->functionIdentifier()->getText());
    SymtabEntry *functionId = symtabStack->lookup(name);
    bool badName = false;

    ctx->type = Predefined::integerType;

    if (functionId == nullptr)
    {
        error.flag(UNDECLARED_IDENTIFIER, nameCtx);
        badName = true;
    }
    else if (functionId->getKind() != FUNCTION)
    {
        error.flag(NAME_MUST_BE_FUNCTION, nameCtx);
        badName = true;
    }

    // Bad function name. Do a simple arguments check and then leave.
    if (badName)
    {
        for (CParser::ArgumentContext *exprCtx : listCtx->argument())
        {
            visit(exprCtx);
        }
    }

    // Good function name.
    else
    {
        vector<SymtabEntry *> *parms = functionId->getRoutineParameters();
        checkCallArguments(listCtx, parms);
        ctx->type = functionId->getType();
    }

    nameCtx->entry = functionId;
    nameCtx->type  = ctx->type;

    return nullptr;
}

Object Semantics::visitReturnStatement(CParser::ReturnStatementContext *ctx){
    Typespec* routineType = symtabStack->getLocalSymtab()->getOwner()->getType();
    Kind routineKind = symtabStack->getLocalSymtab()->getOwner()->getKind();
    if(ctx->expression()){
        CParser::ExpressionContext *eCtx = ctx->expression();
        visit(eCtx);
        if(eCtx->type != routineType){
            error.flag(INVALID_RETURN_TYPE,ctx);
        }
    }
    else{
        //Must be part of a function with return type void
        if(routineType != nullptr && routineKind != PROCEDURE){
            error.flag(INVALID_RETURN_TYPE,ctx);
        }
    }
    return nullptr;
}

Object Semantics::visitExpression(CParser::ExpressionContext *ctx){
    CParser::SimpleExpressionContext *simpleCtx1 = ctx->simpleExpression()[0];
    // First simple expression.
    visit(simpleCtx1);

    Typespec *simpleType1 = simpleCtx1->type;
    ctx->type = simpleType1;

    CParser::RelOpContext *relopCtx = ctx->relOp();

    // Second simple expression?
    if (relopCtx != nullptr)
    {
        CParser::SimpleExpressionContext *simpleCtx2 =
                ctx->simpleExpression()[1];
        visit(simpleCtx2);

        Typespec *simpleType2 = simpleCtx2->type;
        if (!TypeChecker::areComparisonCompatible(simpleType1, simpleType2))
        {
            error.flag(INCOMPATIBLE_COMPARISON, ctx);
        }

        ctx->type = Predefined::booleanType;
    }

    return nullptr;
}

Object Semantics::visitSimpleExpression(CParser::SimpleExpressionContext *ctx){
    int count = ctx->term().size();
    CParser::SignContext *signCtx = ctx->sign();
    bool hasSign = signCtx != nullptr;
    CParser::TermContext *termCtx1 = ctx->term()[0];

    if (hasSign)
    {
        string sign = signCtx->getText();
        if ((sign== "+") && (sign == "-"))
        {
            error.flag(INVALID_SIGN, signCtx);
        }
    }

    // First term.
    visit(termCtx1);
    Typespec *termType1 = termCtx1->type;

    // Loop over any subsequent terms.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->addOp()[i-1]->getText());
        CParser::TermContext *termCtx2 = ctx->term()[i];
        visit(termCtx2);
        Typespec *termType2 = termCtx2->type;

        // Both operands bool ==> bool result. Else type mismatch.
        if (op == "||")
        {
            if (!TypeChecker::isBoolean(termType1))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, termCtx1);
            }
            if (!TypeChecker::isBoolean(termType2))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, termCtx2);
            }
            if (hasSign)
            {
                error.flag(INVALID_SIGN, signCtx);
            }

            termType2 = Predefined::booleanType;
        }
        else if (op == "+")
        {
            // Both operands integer ==> integer result
            if (TypeChecker::areBothInteger(termType1, termType2))
            {
                termType2 = Predefined::integerType;
            }

                // Both real operands ==> real result
                // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(termType1, termType2))
            {
                termType2 = Predefined::realType;
            }

                // Both operands string ==> string result
            else if (TypeChecker::areBothString(termType1, termType2))
            {
                if (hasSign) error.flag(INVALID_SIGN, signCtx);
                termType2 = Predefined::stringType;
            }

                // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(termType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
                    termType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(termType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
                    termType2 = Predefined::integerType;
                }
            }
        }
        else  // -
        {
            // Both operands integer ==> integer result
            if (TypeChecker::areBothInteger(termType1, termType2))
            {
                termType2 = Predefined::integerType;
            }

                // Both real operands ==> real result
                // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(termType1, termType2))
            {
                termType2 = Predefined::realType;
            }

                // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(termType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
                    termType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(termType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
                    termType2 = Predefined::integerType;
                }
            }
        }

        termType1 = termType2;
    }

    ctx->type = termType1;
    return nullptr;
}

Object Semantics::visitTerm(CParser::TermContext *ctx){
    int count = ctx->factor().size();
    CParser::FactorContext *factorCtx1 = ctx->factor()[0];

    // First factor.
    visit(factorCtx1);
    Typespec *factorType1 = factorCtx1->type;

    // Loop over any subsequent factors.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->mulOp()[i-1]->getText());
        CParser::FactorContext *factorCtx2 = ctx->factor()[i];
        visit(factorCtx2);
        Typespec *factorType2 = factorCtx2->type;

        if (op == "*")
        {
            // Both operands integer  ==> integer result
            if (TypeChecker::areBothInteger(factorType1, factorType2))
            {
                factorType2 = Predefined::integerType;
            }

                // Both real operands ==> real result
                // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(factorType1, factorType2))
            {
                factorType2 = Predefined::realType;
            }

                // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(factorType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        }
        else if (op == "/")
        {
            // All integer and real operand combinations ==> real result
            if (   TypeChecker::areBothInteger(factorType1, factorType2)
                   || TypeChecker::isAtLeastOneReal(factorType1, factorType2))
            {
                factorType2 = Predefined::realType;
            }

                // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(factorType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        }
        else if ((op == "div") ||(op == "mod"))
        {
            // Both operands integer ==> integer result. Else type mismatch.
            if (!TypeChecker::isInteger(factorType1))
            {
                error.flag(TYPE_MUST_BE_INTEGER, factorCtx1);
                factorType2 = Predefined::integerType;
            }
            if (!TypeChecker::isInteger(factorType2))
            {
                error.flag(TYPE_MUST_BE_INTEGER, factorCtx2);
                factorType2 = Predefined::integerType;
            }

            ctx->type = Predefined::integerType;
        }
        else if (op == "&&")
        {
            // Both operands bool ==> bool result. Else type mismatch.
            if (!TypeChecker::isBoolean(factorType1))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx1);
                factorType2 = Predefined::booleanType;
            }
            if (!TypeChecker::isBoolean(factorType2))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx2);
                factorType2 = Predefined::booleanType;
            }
        }

        factorType1 = factorType2;
    }

    ctx->type = factorType1;
    return nullptr;
}

Object Semantics::visitVariableFactor(CParser::VariableFactorContext *ctx){
    CParser::VariableContext *varCtx = ctx->variable();
    visit(varCtx);
    ctx->type = varCtx->type;

    return nullptr;
}

Object Semantics::visitVariable(CParser::VariableContext *ctx){
    CParser::VariableIdentifierContext *varIdCtx =
            ctx->variableIdentifier();

    visit(varIdCtx);
    ctx->entry = varIdCtx->entry;
    ctx->type  = variableDatatype(ctx, varIdCtx->type);

    return nullptr;
}

Object Semantics::visitVariableIdentifier(CParser::VariableIdentifierContext *ctx){

    string variableName = toLowerCase(ctx->IDENTIFIER()->getText());
    SymtabEntry *variableId = symtabStack->lookup(variableName);

    if (variableId != nullptr)
    {
        int lineNumber = ctx->getStart()->getLine();
        ctx->type = variableId->getType();
        ctx->entry = variableId;
        variableId->appendLineNumber(lineNumber);

        Kind kind = variableId->getKind();
        switch (kind)
        {
            case TYPE:
            case PROGRAM:
            case PROGRAM_PARAMETER:
            case PROCEDURE:
            case UNDEFINED:
                error.flag(INVALID_VARIABLE, ctx);
                break;

            default: break;
        }
    }
    else
    {
        error.flag(UNDECLARED_IDENTIFIER, ctx);
        ctx->type = Predefined::integerType;
    }

    return nullptr;
}

Object Semantics::visitNumberFactor(CParser::NumberFactorContext *ctx){
    CParser::NumberContext          *numberCtx   = ctx->number();
    CParser::UnsignedNumberContext  *unsignedCtx = numberCtx->unsignedNumber();
    CParser::IntegerConstantContext *integerCtx  = unsignedCtx->integerConstant();

    ctx->type = (integerCtx != nullptr) ? Predefined::integerType
                                        : Predefined::realType;

    return nullptr;
}

Object Semantics::visitCharacterFactor(CParser::CharacterFactorContext *ctx){
    ctx->type = Predefined::charType;
    return nullptr;
}

Object Semantics::visitStringFactor(CParser::StringFactorContext *ctx){
    ctx->type = Predefined::stringType;
    return nullptr;
}

Object Semantics::visitNotFactor(CParser::NotFactorContext *ctx){
    CParser::FactorContext *factorCtx = ctx->factor();
    visit(factorCtx);

    if (factorCtx->type != Predefined::booleanType)
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx);
    }

    ctx->type = Predefined::booleanType;
    return nullptr;
}

Object Semantics::visitParenthesizedFactor(CParser::ParenthesizedFactorContext *ctx){
    CParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    ctx->type = exprCtx->type;

    return nullptr;
}






}