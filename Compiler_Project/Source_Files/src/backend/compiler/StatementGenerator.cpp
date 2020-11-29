#include <string>
#include <vector>
#include <map>

#include "CBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "backend/compiler/Compiler.h"
#include "backend/compiler/StatementGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

string StatementGenerator::typeToString(Typespec *type){
    static std::map<Typespec*,string> typeMap= {
            {Predefined::integerType,"I"},
            {Predefined::charType,"C"},
            {Predefined::booleanType,"Z"},
            {Predefined::realType,"F"},
            {Predefined::stringType,"S"},
            {Predefined::undefinedType,"V"},
            {Predefined::voidType,"V"}
    };
    return typeMap[type];
}

void StatementGenerator::emitCast(Typespec* from, Typespec* to){
    //There's probably a better way to do this, but...
    if(from == Predefined::integerType){
        if(to == Predefined::realType){
            emit(Instruction::I2F);
        }
    }
}

//FIXME: Debug this, likely isn't correct
void StatementGenerator::emitAssignment(CParser::AssignVariableContext *ctx){
    SymtabEntry *varId;
    Typespec *varType;
    if(ctx->lhs()->variable()){
        varId = ctx->lhs()->variable()->entry;
        varType = ctx->lhs()->variable()->type;
    }
    else{
        varId = ctx->lhs()->variableDeclaration()->variableIdentifier()[0]->entry;
        varType = ctx->lhs()->variableDeclaration()->variableIdentifier()[0]->type;
    }
    CParser::ExpressionContext *exprCtx = ctx->rhs()->expression();

    Typespec *exprType = exprCtx->type;

    /*Not needed since we're not using arrays
    // The last modifier, if any, is the variable's last subscript or field.
    int modifierCount = varCtx->modifier().size();
    PascalParser::ModifierContext *lastModCtx = modifierCount == 0
                                                ? nullptr : varCtx->modifier()[modifierCount - 1];


    // The target variable has subscripts and/or fields.
    if (modifierCount > 0)
    {
        lastModCtx = varCtx->modifier()[modifierCount - 1];
        compiler->visit(varCtx);
    }*/

    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // float variable := integer constant
    if (   (varType == Predefined::realType)
           && (exprType->baseType() == Predefined::integerType)) emit(I2F);

    // Emit code to store the expression value into the target variable.
    emitStoreValue(varId, varId->getType());
}

void StatementGenerator::emitIncrement(CParser::IncrementVariableContext *ctx){
    CodeGenerator::emitLoadValue(ctx->variable()->entry);
    emitLoadConstant(1);
    emit(Instruction::IADD);
    emitStoreValue(ctx->variable()->entry,ctx->variable()->type);
}

void StatementGenerator::emitDecrement(CParser::DecrementVariableContext *ctx){
    CodeGenerator::emitLoadValue(ctx->variable()->entry);
    emitLoadConstant(1);
    emit(Instruction::ISUB);
    emitStoreValue(ctx->variable()->entry,ctx->variable()->type);
}

//FIXME: Debug this, likely isn't correct
void StatementGenerator::emitIf(CParser::IfStatementContext *ctx){
    Label* doneLabel = new Label();

    int numElseIf = ctx->IF().size() - 1;
    bool elsePresent = (ctx->IF().size() - 1) != ctx->ELSE().size();

    Label* skipFirst = new Label();
    //Evaluate expression
    compiler->visitExpression(ctx->expression()[0]);
    emit(Instruction::ICONST_0);
    emit(Instruction::IF_ICMPEQ,skipFirst->getString());

    //Execute if True, Fall through to next
    compiler->visit(ctx->controlScope()[0]);
    emit(Instruction::GOTO,doneLabel->getString());
    emitLabel(skipFirst);

    //Repeat for all the else if
    for(unsigned int i=0;i<numElseIf;i++){
        Label* skipOver = new Label();
        //Evaluate expression
        compiler->visitExpression(ctx->expression()[1+i]);
        emit(Instruction::ICONST_0);
        emit(Instruction::IF_ICMPEQ,skipOver->getString());

        //Execute if True, Fall through to next
        compiler->visit(ctx->controlScope()[1+i]);
        emit(Instruction::GOTO,doneLabel->getString());
        emitLabel(skipOver);
    }

    if(elsePresent){
        //Falls through to the last statement
        compiler->visit(ctx->controlScope().back());
    }

    //Jump to when done with true section so to skip false section
    emitLabel(doneLabel);
};

void StatementGenerator::emitDoWhile(CParser::DoWhileLoopContext *ctx){
    Label *loopTopLabel  = new Label();
    Label *loopExitLabel = new Label();

    emitLabel(loopTopLabel);

    compiler->visit(ctx->controlScope());
    compiler->visit(ctx->expression());
    emit(IFNE, loopExitLabel);
    emit(GOTO, loopTopLabel);

    emitLabel(loopExitLabel);
}

void StatementGenerator::emitWhile(CParser::WhileLoopContext *ctx){
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
    compiler->visit(ctx->controlScope());
    emit(Instruction::GOTO,topLabel->getString());

    emitLabel(exitLabel); //Jump to here to exit loop
}

void StatementGenerator::emitFor(CParser::ForLoopContext *ctx){
    Label* topLabel = new Label();
    Label* exitLabel = new Label();

    //Initial assignment
    compiler->visit(ctx->statement(0));

    //Begin Loop
    emitLabel(topLabel);

    //Perform Test
    compiler->visit(ctx->expression());
    emit(Instruction::ICONST_0);
    emit(Instruction::IF_ICMPEQ, exitLabel->getString());

    //Do looping statement
    compiler->visit(ctx->controlScope());
    compiler->visit(ctx->statement(1));
    emit(Instruction::GOTO,topLabel->getString());

    emitLabel(exitLabel);
}

void StatementGenerator::emitProcedureCall(CParser::FunctionCallContext *ctx){
    emitCall(ctx->functionIdentifier()->entry,ctx->argumentList());
}

void StatementGenerator::emitFunctionCall(CParser::FunctionCallContext *ctx){
    emitCall(ctx->functionIdentifier()->entry,ctx->argumentList());
}

void StatementGenerator::emitCall(SymtabEntry *routineId, CParser::ArgumentListContext *argListCtx){
//Need to get datatypes of arguments
    string argTypeString;

    if(argListCtx){
        std::vector<Typespec*> expectedArgType;
        expectedArgType.reserve(argListCtx->argument().size());
        for(auto argSymTabEntry : *routineId->getRoutineParameters()){
            expectedArgType.push_back(argSymTabEntry->getType());
            argTypeString += typeToString(argSymTabEntry->getType());
        }

        for(unsigned int i=0;i<argListCtx->argument().size();i++){
            auto argCtx = argListCtx->argument(i);
            compiler->visit(argCtx->expression()); //Will put the arguments on the top of the argument stack
            if(argCtx->expression()->type != expectedArgType[i]){
                emitCast(argCtx->expression()->type,expectedArgType[i]);
            }
        }
    }

    //This is a bit of a hack since we know we will only have static methods
    string retType = typeToString(routineId->getType());
    string functionName = programName + "/" + routineId->getName() + "(" + argTypeString + ")" + (retType.empty()?"V":retType);
    emit(Instruction::INVOKESTATIC,functionName);
}

void StatementGenerator::emitReturn(CParser::ReturnStatementContext *ctx) {
    //Leave the value on top of stack
    if (ctx->expression()){
        compiler->visit(ctx->expression());
    }
}

void StatementGenerator::emitPrint(CParser::PrintStatementContext *ctx){
    emitPrint(ctx->printArguments(), false);
}

void StatementGenerator::emitPrintln(CParser::PrintlnStatementContext *ctx){
    emitPrint(ctx->printArguments(), true);
}

void StatementGenerator::emitPrint(CParser::PrintArgumentsContext *argsCtx, bool needLF){
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
        int exprCount = createPrintFormat(argsCtx, format, needLF);

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

int StatementGenerator::createPrintFormat(CParser::PrintArgumentsContext *argsCtx, string& format, bool needLF){
    int exprCount = 0;
    format += "\"";

    // Loop over the write arguments.
    for (CParser::PrintArgumentContext *argCtx : argsCtx->printArgument())
    {
        Typespec *type = argCtx->expression()->type;
        string argText = argCtx->getText();

        // Append any literal strings.
        if (argText[0] == '\"') format += convertString(argText, true);

            // For any other expressions, append a field specifier.
        else
        {
            exprCount++;
            format.append("%");

            CParser::FieldWidthContext *fwCtx = argCtx->fieldWidth();
            if (fwCtx != nullptr)
            {
                string sign = (   (fwCtx->sign() != nullptr)
                                  && (fwCtx->sign()->getText() == "-")) ? "-" : "";
                format += sign + fwCtx->integerConstant()->getText();

                CParser::DecimalPlacesContext *dpCtx =
                        fwCtx->decimalPlaces();
                if (dpCtx != nullptr)
                {
                    format += "." + dpCtx->integerConstant()->getText();
                }
            }

            string typeFlag = type == Predefined::integerType ? "d"
                : type == Predefined::realType    ?     "f"
                    : type == Predefined::booleanType ?     "b"
                        : type == Predefined::charType    ?     "c"
                            :                                       "s";
            format += typeFlag;
        }
    }

    format += needLF ? "\\n\"" : "\"";

    return exprCount;
}

void StatementGenerator::emitArgumentsArray(CParser::PrintArgumentsContext *argsCtx, int exprCount){
    // Create the arguments array.
    emitLoadConstant(exprCount);
    emit(ANEWARRAY, "java/lang/Object");

    int index = 0;

    // Loop over the write arguments to fill the arguments array.
    for (CParser::PrintArgumentContext *argCtx :
            argsCtx->printArgument())
    {
        string argText = argCtx->getText();
        CParser::ExpressionContext *exprCtx = argCtx->expression();
        Typespec *type = exprCtx->type->baseType();

        // Skip string constants, which were made part of
        // the format string.
        if (argText[0] != '\"')
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

void StatementGenerator::emitRead(CParser::ReadStatementContext *ctx){
    emitRead(ctx->readArguments(), false);
}

void StatementGenerator::emitReadln(CParser::ReadlnStatementContext *ctx){
    emitRead(ctx->readArguments(), true);
}

void StatementGenerator::emitRead(CParser::ReadArgumentsContext *argsCtx, bool needSkip){
    int size = argsCtx->variable().size();

    // Loop over read arguments.
    for (int i = 0; i < size; i++)
    {
        CParser::VariableContext *varCtx = argsCtx->variable()[i];
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
