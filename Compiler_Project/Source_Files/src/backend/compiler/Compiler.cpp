#include "intermediate/symtab/Predefined.h"
#include "backend/compiler/Compiler.h"

namespace backend { namespace compiler {

Object Compiler::loadValue(CParser::VariableContext *ctx){
    expressionCode->emitLoadValue(ctx);
    return nullptr;
}

Object Compiler::visitProgram(CParser::ProgramContext *ctx){
    createNewGenerators(code);
    programCode->emitProgram(ctx);
    return nullptr;
}

Object Compiler::visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx){
    createNewGenerators(code);
    programCode->emitRoutine(ctx);
    return nullptr;
}

Object Compiler::visitStatement(CParser::StatementContext *ctx){
    if (ctx->controlStatement() == nullptr){
        statementCode->emitComment(ctx);
    }

    return visitChildren(ctx);
}

Object Compiler::visitAssignVariable(CParser::AssignVariableContext *ctx){
    if(ctx->lhs()->variable()){
        statementCode->emitAssignment(ctx);
    }
    else{
        statementCode->emitDeclarationAssignment(ctx);
    }

    return nullptr;
}

Object Compiler::visitIncrementVariable(CParser::IncrementVariableContext *ctx){
    statementCode->emitIncrement(ctx);
    return nullptr;
}

Object Compiler::visitDecrementVariable(CParser::DecrementVariableContext *ctx){
    statementCode->emitDecrement(ctx);
    return nullptr;
}

Object Compiler::visitIfStatement(CParser::IfStatementContext *ctx){
    statementCode->emitIf(ctx);
    return nullptr;
}

Object Compiler::visitDoWhileLoop(CParser::DoWhileLoopContext *ctx){
    statementCode->emitDoWhile(ctx);
    return nullptr;
}

Object Compiler::visitWhileLoop(CParser::WhileLoopContext *ctx){
    statementCode->emitWhile(ctx);
    return nullptr;
}

Object Compiler::visitForLoop(CParser::ForLoopContext *ctx){
    statementCode->emitFor(ctx);
    return nullptr;
}

Object Compiler::visitFunctionCall(CParser::FunctionCallContext *ctx){
    statementCode->emitFunctionCall(ctx);
    auto b = ctx->functionIdentifier()->getText();
    auto a = ctx->functionIdentifier()->type;
    if(ctx->functionIdentifier()->type != Predefined::voidType) {
        //We don't want to use the result, so remove it from the stack
        statementCode->emit(Instruction::POP);
    }
    return nullptr;
}

Object Compiler::visitReturnStatement(CParser::ReturnStatementContext *ctx){
    statementCode->emitReturn(ctx);
    return nullptr;
}

Object Compiler::visitExpression(CParser::ExpressionContext *ctx){
    expressionCode->emitExpression(ctx);
    return nullptr;
}

Object Compiler::visitVariableFactor(CParser::VariableFactorContext *ctx){
    expressionCode->emitLoadValue(ctx->variable());
    return nullptr;
}

Object Compiler::visitVariable(CParser::VariableContext *ctx){
    expressionCode->emitLoadVariable(ctx);
    return nullptr;
}

Object Compiler::visitNumberFactor(CParser::NumberFactorContext *ctx){
    if (ctx->type == Predefined::integerType)
    {
        expressionCode->emitLoadIntegerConstant(ctx->number());
    }
    else
    {
        expressionCode->emitLoadRealConstant(ctx->number());
    }

    return nullptr;
}

Object Compiler::visitCharacterFactor(CParser::CharacterFactorContext *ctx){
    char ch = ctx->getText()[1];
    expressionCode->emitLoadConstant(ch);

    return nullptr;
}

Object Compiler::visitStringFactor(CParser::StringFactorContext *ctx){
    string jasminString = convertString(ctx->getText(), true);
    expressionCode->emitLoadConstant(jasminString);

    return nullptr;
}

Object Compiler::visitFunctionCallFactor(CParser::FunctionCallFactorContext *ctx){
    statementCode->emitFunctionCall(ctx->functionCall());
    return nullptr;
}

Object Compiler::visitNotFactor(CParser::NotFactorContext *ctx){
    expressionCode->emitNotFactor(ctx);
    return nullptr;
}

Object Compiler::visitParenthesizedFactor(CParser::ParenthesizedFactorContext *ctx){
    return visit(ctx->expression());
}

Object Compiler::visitPrintStatement(CParser::PrintStatementContext *ctx){
    statementCode->emitPrint(ctx);
    return nullptr;
}

Object Compiler::visitPrintlnStatement(CParser::PrintlnStatementContext *ctx){
    statementCode->emitPrintln(ctx);
    return nullptr;
}

Object Compiler::visitReadStatement(CParser::ReadStatementContext *ctx){
    statementCode->emitRead(ctx);
    return nullptr;
}

Object Compiler::visitReadlnStatement(CParser::ReadlnStatementContext *ctx){
    statementCode->emitReadln(ctx);
    return nullptr;
}

}}