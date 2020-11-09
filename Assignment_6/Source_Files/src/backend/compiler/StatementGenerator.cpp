#include <string>
#include <vector>
#include <map>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "backend/compiler/Compiler.h"
#include "backend/compiler/StatementGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

void StatementGenerator::emitAssignment(PascalParser::AssignmentStatementContext *ctx)
{
    PascalParser::VariableContext *varCtx  = ctx->lhs()->variable();
    PascalParser::ExpressionContext *exprCtx = ctx->rhs()->expression();
    SymtabEntry *varId = varCtx->entry;
    Typespec *varType  = varCtx->type;
    Typespec *exprType = exprCtx->type;

    // The last modifier, if any, is the variable's last subscript or field.
    int modifierCount = varCtx->modifier().size();
    PascalParser::ModifierContext *lastModCtx = modifierCount == 0
                            ? nullptr : varCtx->modifier()[modifierCount - 1];

    // The target variable has subscripts and/or fields.
    if (modifierCount > 0)
    {
        lastModCtx = varCtx->modifier()[modifierCount - 1];
        compiler->visit(varCtx);
    }

    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // float variable := integer constant
    if (   (varType == Predefined::realType)
        && (exprType->baseType() == Predefined::integerType)) emit(I2F);

    // Emit code to store the expression value into the target variable.
    // The target variable has no subscripts or fields.
    if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

    // The target variable is a field.
    else if (lastModCtx->field() != nullptr)
    {
        emitStoreValue(lastModCtx->field()->entry, lastModCtx->field()->type);
    }

    // The target variable is an array element.
    else
    {
        emitStoreValue(nullptr, varType);
    }
}

void StatementGenerator::emitIf(PascalParser::IfStatementContext *ctx)
{
    /***** Complete this member function. *****/
    Label* falseLabel = new Label();
    Label* doneLabel = new Label();

    //Evaluate expression
    compiler->visitExpression(ctx->expression());

    //Do comparison to see if expression is true
    emit(Instruction::ICONST_0);
    if(ctx->ELSE()) {
        emit(Instruction::IF_ICMPEQ, falseLabel->getString());
    }
    else{
        emit(Instruction::IF_ICMPEQ, doneLabel->getString());
    }

    //Execute if True, Fall through to next
    compiler->visit(ctx->trueStatement());
    emit(Instruction::GOTO,doneLabel->getString());

    //Emit else statement if present
    if(ctx->ELSE()){
        //Label to jump to if false
        emitLabel(falseLabel);
        compiler->visit(ctx->falseStatement());
    }

    //Jump to when done with true section so to skip false section
    emitLabel(doneLabel);
}

void StatementGenerator::emitCase(PascalParser::CaseStatementContext *ctx)
{
    /***** Complete this member function. *****/
    std::vector<std::pair<PascalParser::CaseBranchContext*,Label*>> branchLabels;

    //Add new labels for all the branches
    for(PascalParser::CaseBranchContext* branch : ctx->caseBranchList()->caseBranch()){
        branchLabels.emplace_back(branch,new Label);
    }
    Label* exitCase = new Label;

    //Evaluate input expression
    compiler->visit(ctx->expression());

    emit(Instruction::LOOKUPSWITCH);

    std::set<std::pair<int,Label*>> labelSet; //Used since labels have to be in order
    //Add all the constants and associated labels
    for(unsigned int i=0;i<branchLabels.size();i++){
        if(!branchLabels[i].first->caseConstantList()){
            continue;
        }

        //For each case statement, tell it what label to jump to
        for(PascalParser::CaseConstantContext* constantCtx : branchLabels[i].first->caseConstantList()->caseConstant()){
            labelSet.insert(std::make_pair(constantCtx->value, branchLabels[i].second));
        }
    }

    //Output all the labels in order
    for(auto entry : labelSet){
        emitLabel(entry.first,entry.second);
    }
    emitLabel("default",exitCase);

    //Create labels + code to execute for each branch
    for(auto entry : branchLabels){
        emitLabel(entry.second);
        if(entry.first->statement() != nullptr) {
            compiler->visit(entry.first->statement());
        }
        emit(Instruction::GOTO,exitCase->getString());
    }

    //Exit case(s)
    emitLabel(exitCase);
}

void StatementGenerator::emitRepeat(PascalParser::RepeatStatementContext *ctx)
{
    Label *loopTopLabel  = new Label();
    Label *loopExitLabel = new Label();

    emitLabel(loopTopLabel);

    compiler->visit(ctx->statementList());
    compiler->visit(ctx->expression());
    emit(IFNE, loopExitLabel);
    emit(GOTO, loopTopLabel);

    emitLabel(loopExitLabel);
}

void StatementGenerator::emitWhile(PascalParser::WhileStatementContext *ctx)
{
    /***** Complete this member function. *****/
    Label* topLabel = new Label();
    Label* exitLabel = new Label();

    //Set up label to return to at top of loop
    emitLabel(topLabel);

    //Evaluate expression
    compiler->visitExpression(ctx->expression());

    //Do comparison to see if expression is true
    emit(Instruction::ICONST_0);
    emit(Instruction::IF_ICMPEQ, exitLabel->getString());

    //Execute if true, fall through to next
    compiler->visit(ctx->statement());
    emit(Instruction::GOTO,topLabel->getString());

    emitLabel(exitLabel); //Jump to here to exit loop
}

void StatementGenerator::emitFor(PascalParser::ForStatementContext *ctx)
{
    /***** Complete this member function. *****/
    Label* topLabel = new Label();
    Label* exitLabel = new Label();

    string varType;
    if(ctx->variable()->type == Predefined::integerType) varType = "I";
    else if(ctx->variable()->type == Predefined::charType) varType = "C";

    //Initial assignment
    compiler->visit(ctx->expression()[0]); //Get value to assign
    if(ctx->variable()->entry->getSymtab()->getNestingLevel() > 1) {
        //Using local variable
        emit(Instruction::ISTORE,ctx->variable()->entry->getSlotNumber());
    }
    else{
        //Using global variable
        emit(Instruction::PUTSTATIC,programName+"/"+ctx->variable()->getText(),varType);
    }

    //Begin loop
    emitLabel(topLabel);
    //Perform test
    if(ctx->TO()){
        //Counting up
        compiler->visit(ctx->expression()[1]); //Puts result on opstack
        emit(Instruction::ICONST_1);
        emit(Instruction::IADD); //Should go up to the number and stop when one above
    }
    else{
        //Counting down
        compiler->visit(ctx->expression()[1]); //Puts result on opstack
        emit(Instruction::ICONST_1);
        emit(Instruction::ISUB);
    }
    if(ctx->variable()->entry->getSymtab()->getNestingLevel() > 1) {
        //Using local variable
        emit(Instruction::ILOAD, ctx->variable()->entry->getSlotNumber());
    }
    else{
        //Using static/global variable
        emit(Instruction::GETSTATIC,programName+"/"+ctx->variable()->getText(),varType);
    }
    //If done, exit loop
    emit(Instruction::IF_ICMPEQ, exitLabel->getString());

    //Do statement in loop
    compiler->visit(ctx->statement());

    //Increment variable and return to at top of loop
    if(ctx->variable()->entry->getSymtab()->getNestingLevel() > 1) {
        //Using local variable
        emit(Instruction::ILOAD,ctx->variable()->entry->getSlotNumber());
        emit(Instruction::ICONST_1);
        if(ctx->TO()) {
            //Counting up
            emit(Instruction::IADD);
        }
        else{
            //Counting down
            emit(Instruction::ISUB);
        }
        emit(Instruction::ISTORE, ctx->variable()->entry->getSlotNumber());
    }
    else{
        //Using static/global variable
        emit(Instruction::GETSTATIC,programName+"/"+ctx->variable()->getText(),varType);
        emit(Instruction::ICONST_1);
        if(ctx->TO()) {
            //Counting up
            emit(Instruction::IADD);
        }
        else{
            //Counting down
            emit(Instruction::ISUB);
        }
        emit(Instruction::PUTSTATIC,programName+"/"+ctx->variable()->getText(),varType);
    }
    emit(Instruction::GOTO,topLabel->getString());

    //Exit loop
    emitLabel(exitLabel);
}

void StatementGenerator::emitProcedureCall(PascalParser::ProcedureCallStatementContext *ctx)
{
    /***** Complete this member function. *****/
}

void StatementGenerator::emitFunctionCall(PascalParser::FunctionCallContext *ctx)
{
    /***** Complete this member function. *****/
}

void StatementGenerator::emitCall(SymtabEntry *routineId,
                                  PascalParser::ArgumentListContext *argListCtx)
{
    /***** Complete this member function. *****/
}

void StatementGenerator::emitWrite(PascalParser::WriteStatementContext *ctx)
{
    emitWrite(ctx->writeArguments(), false);
}

void StatementGenerator::emitWriteln(PascalParser::WritelnStatementContext *ctx)
{
    emitWrite(ctx->writeArguments(), true);
}

void StatementGenerator::emitWrite(PascalParser::WriteArgumentsContext *argsCtx,
                      bool needLF)
{
    emit(GETSTATIC, "java/lang/System/out", "Ljava/io/PrintStream;");

    // WRITELN with no arguments.
    if (argsCtx == nullptr)
    {
        emit(INVOKEVIRTUAL, "java/io/PrintStream.println()V");
        localStack->decrease(1);
    }

    // Generate code for the arguments.
    else
    {
        string format;
        int exprCount = createWriteFormat(argsCtx, format, needLF);

        // Load the format string.
        emit(LDC, format);

        // Emit the arguments array.
       if (exprCount > 0)
        {
            emitArgumentsArray(argsCtx, exprCount);

            emit(INVOKEVIRTUAL,
                        string("java/io/PrintStream/printf(Ljava/lang/String;")
                      + string("[Ljava/lang/Object;)")
                      + string("Ljava/io/PrintStream;"));
            localStack->decrease(2);
            emit(POP);
        }
        else
        {
            emit(INVOKEVIRTUAL,
                 "java/io/PrintStream/print(Ljava/lang/String;)V");
            localStack->decrease(2);
        }
    }
}

int StatementGenerator::createWriteFormat(
                                PascalParser::WriteArgumentsContext *argsCtx,
                                string& format, bool needLF)
{
    int exprCount = 0;
    format += "\"";

    // Loop over the write arguments.
    for (PascalParser::WriteArgumentContext *argCtx : argsCtx->writeArgument())
    {
        Typespec *type = argCtx->expression()->type;
        string argText = argCtx->getText();

        // Append any literal strings.
        if (argText[0] == '\'') format += convertString(argText, true);

        // For any other expressions, append a field specifier.
        else
        {
            exprCount++;
            format.append("%");

            PascalParser::FieldWidthContext *fwCtx = argCtx->fieldWidth();
            if (fwCtx != nullptr)
            {
                string sign = (   (fwCtx->sign() != nullptr)
                               && (fwCtx->sign()->getText() == "-")) ? "-" : "";
                format += sign + fwCtx->integerConstant()->getText();

                PascalParser::DecimalPlacesContext *dpCtx =
                                                        fwCtx->decimalPlaces();
                if (dpCtx != nullptr)
                {
                    format += "." + dpCtx->integerConstant()->getText();
                }
            }

            string typeFlag = type == Predefined::integerType ? "d"
                            : type == Predefined::realType    ? "f"
                            : type == Predefined::booleanType ? "b"
                            : type == Predefined::charType    ? "c"
                            :                                  "s";
            format += typeFlag;
        }
    }

    format += needLF ? "\\n\"" : "\"";

    return exprCount;
}

void StatementGenerator::emitArgumentsArray(
                    PascalParser::WriteArgumentsContext *argsCtx, int exprCount)
{
    // Create the arguments array.
    emitLoadConstant(exprCount);
    emit(ANEWARRAY, "java/lang/Object");

    int index = 0;

    // Loop over the write arguments to fill the arguments array.
    for (PascalParser::WriteArgumentContext *argCtx :
                                                argsCtx->writeArgument())
    {
        string argText = argCtx->getText();
        PascalParser::ExpressionContext *exprCtx = argCtx->expression();
        Typespec *type = exprCtx->type->baseType();

        // Skip string constants, which were made part of
        // the format string.
        if (argText[0] != '\'')
        {
            emit(DUP);
            emitLoadConstant(index++);

            compiler->visit(exprCtx);

            Form form = type->getForm();
            if (    ((form == SCALAR) || (form == ENUMERATION))
                 && (type != Predefined::stringType))
            {
                emit(INVOKESTATIC, valueOfSignature(type));
            }

            // Store the value into the array.
            emit(AASTORE);
        }
    }
}

void StatementGenerator::emitRead(PascalParser::ReadStatementContext *ctx)
{
    emitRead(ctx->readArguments(), false);
}

void StatementGenerator::emitReadln(PascalParser::ReadlnStatementContext *ctx)
{
    emitRead(ctx->readArguments(), true);
}

void StatementGenerator::emitRead(PascalParser::ReadArgumentsContext *argsCtx,
                                  bool needSkip)
{
    int size = argsCtx->variable().size();

    // Loop over read arguments.
    for (int i = 0; i < size; i++)
    {
        PascalParser::VariableContext *varCtx = argsCtx->variable()[i];
        Typespec *varType = varCtx->type;

        if (varType == Predefined::integerType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextInt()I");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::realType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextFloat()F");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::booleanType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextBoolean()Z");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::charType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(LDC, "\"\"");
            emit(INVOKEVIRTUAL,
                 string("java/util/Scanner/useDelimiter(Ljava/lang/String;)") +
                 string("Ljava/util/Scanner;"));
            emit(POP);
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emit(ICONST_0);
            emit(INVOKEVIRTUAL, "java/lang/String/charAt(I)C");
            emitStoreValue(varCtx->entry, nullptr);

            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/reset()Ljava/util/Scanner;");

        }
        else  // string
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emitStoreValue(varCtx->entry, nullptr);
        }
    }

    // READLN: Skip the rest of the input line.
    if (needSkip)
    {
        emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
        emit(INVOKEVIRTUAL, "java/util/Scanner/nextLine()Ljava/lang/String;");
        emit(POP);
    }
}

}} // namespace backend::compiler
