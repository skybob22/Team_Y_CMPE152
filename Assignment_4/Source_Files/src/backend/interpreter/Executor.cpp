#include <iostream>
#include <string>
#include <cstdio>

#include "Object.h"
#include "backend/interpreter/Executor.h"

namespace backend { namespace interpreter {

using namespace std;

Object Executor::visitProgram(Pcl4Parser::ProgramContext *ctx)
{

    return visit(ctx->block());
}

Object Executor::visitStatement(Pcl4Parser::StatementContext *ctx)
{
    return visitChildren(ctx);
}

Object Executor::visitStatementList(Pcl4Parser::StatementListContext *ctx)
{
    for (Pcl4Parser::StatementContext *stmtCtx : ctx->statement())
    {
        visit(stmtCtx);
    }

    return nullptr;
}

Object Executor::visitCompoundStatement(Pcl4Parser::CompoundStatementContext *ctx)
{
    return visit(ctx->statementList());
}

Object Executor::visitAssignmentStatement(Pcl4Parser::AssignmentStatementContext *ctx)
{
    string variableName = ctx->lhs()->variable()->getText();
    visit(ctx->lhs());
    Object value = visit(ctx->rhs());

    intermediate::symtab::SymtabEntry* entry = symbol_table.enter(variableName);
    if(value.is<int>()){
        entry->setValue(value.as<int>());
    }
    else{
        entry->setValue(value);
    }
    return nullptr;
}

Object Executor::visitRepeatStatement(Pcl4Parser::RepeatStatementContext *ctx)
{
    do{
        visitStatementList(ctx->statementList());
    } while(visitExpression(ctx->expression()).equals(false));

   return nullptr;
}

Object Executor::visitWhileLoop(Pcl4Parser::WhileLoopContext *ctx) {
    while(visitExpression(ctx->expression()).equals(false)){
        visitStatement(ctx->statement());
    }
    return nullptr;
}

Object Executor::visitForLoop(Pcl4Parser::ForLoopContext *ctx) {
    //Figure out whether we are incrementing or decrementing the counter
    std::function<antlrcpp::Any(antlrcpp::Any)> op;
    std::function<bool(antlrcpp::Any,antlrcpp::Any)> comp;
    if(ctx->TO()){
        //Increment the counter
        op = [](antlrcpp::Any c){
            volatile int d = c.as<int>();
            return antlrcpp::Any(c.as<int>()+1);
        };
        comp = [](antlrcpp::Any c,antlrcpp::Any stop){
            return c.as<int>() <= stop.as<int>();
        };
    }
    else{
        //Decrement the counter
        op = [](antlrcpp::Any c){
            return antlrcpp::Any(c.as<int>()-1);
        };
        comp = [](antlrcpp::Any c,antlrcpp::Any stop){
            return c.as<int>() >= stop.as<int>();
        };
    }

    for(antlrcpp::Any i = visitExpression(ctx->expression(0));comp(i,visitExpression(ctx->expression(0)));i = op(i)){
        visitStatement(ctx->statement());
    }

    return nullptr;
}

Object Executor::visitIfStatement(Pcl4Parser::IfStatementContext *ctx){
    if(visitExpression(ctx->expression()).equals(true)){
        visitStatement(ctx->statement(0));
    }
    else if(ctx->children.size() > 4){
        //Visit the else statement if it exists and the expression is not true
        visitStatement(ctx->statement(1));
    }
    return nullptr;
}

Object Executor::visitCaseStatement(Pcl4Parser::CaseStatementContext *ctx){
    cout << "Visiting Case" << endl << endl;
    int value = visitExpression(ctx->expression()).as<int>();

    bool done = false;
    for(int i=0;i<ctx->children.size() && !done;i++){

        std::set<int> constants = visitConstantList(ctx->caseBlock(i)->constantList()).as<std::set<int>>();
        if(constants.find(value) != constants.end()){
            visitCaseBlock(ctx->caseBlock(i));
            done = true;
        }
    }
    return nullptr;
}

Object Executor::visitCaseBlock(Pcl4Parser::CaseBlockContext *ctx){
    //Called after checking the constants
    visitStatement(ctx->statement());
    return nullptr;
}

Object Executor::visitConstantList(Pcl4Parser::ConstantListContext *ctx){
    std::set<int> constants;
    for(int i=0;i<ctx->children.size();i++){
        constants.insert(visitIntegerConstant(ctx->integerConstant(i)).as<int>());
    }
    return constants;
}


Object Executor::visitWriteStatement(Pcl4Parser::WriteStatementContext *ctx)
{
    string retString = visitWriteArgumentList(ctx->writeArgumentsOn()->writeArgumentListOn()->writeArgumentList()).as<string>();
    cout << retString;
    return nullptr;
}

Object Executor::visitWriteArgumentList(Pcl4Parser::WriteArgumentListContext *ctx){
    string retString = "";
    for(int i=0;i<ctx->writeArgument().size();i++){
        retString = retString + visitWriteArgument(ctx->writeArgument(i)).as<string>();
        if(i < ctx->writeArgument().size() -1){
            retString = retString + " ";
        }
    }
}

Object Executor::visitWriteArgument(Pcl4Parser::WriteArgumentContext *ctx){
    //TODO: I'm not sure if this will work, Need to get visitExpression working first to test
    // The %.*s should tell it to take an argument for the padding width. I don't know how well this will work
    antlrcpp::Any value = visitExpression(ctx->expression());
    char printString[100];

    if(value.is<string>()){
        if(ctx->fieldWidth()) {
            sprintf(printString,"%.*s", value.as<string>().c_str(),visitIntegerConstant(ctx->fieldWidth()->integerConstant()).as<int>() * -1);
        }
        else{
            sprintf(printString,"%s",value.as<string>().c_str());
        }
    }
    else if(value.is<int>()){
        if(ctx->fieldWidth()) {
            sprintf(printString,"%.*d", value.as<int>(),visitIntegerConstant(ctx->fieldWidth()->integerConstant()).as<int>() * -1);
        }
        else{
            sprintf(printString,"%d", value.as<int>());
        }
    }
    else if(value.is<double>()){
        if(ctx->fieldWidth()) {
            if(ctx->fieldWidth()->decimalPlaces()){
                sprintf(printString,"%.*..*f", value.as<double>(),visitIntegerConstant(ctx->fieldWidth()->integerConstant()).as<int>() * -1,visitIntegerConstant(ctx->fieldWidth()->decimalPlaces()->integerConstant()).as<int>());
            }
            else{
                sprintf(printString,"%.*f", value.as<double>(),visitIntegerConstant(ctx->fieldWidth()->integerConstant()).as<int>() * -1);
            }
        }
        else{
            sprintf(printString,"%f", value.as<double>());
        }
    }

    return std::string(printString);
}

Object Executor::visitWritelnStatement(Pcl4Parser::WritelnStatementContext *ctx)
{
    string retString = visitWriteArgumentList(ctx->writeArgumentsLn()->writeArgumentListLn()->writeArgumentList()).as<string>();
    cout << retString << endl;
    return nullptr;
}

Object Executor::visitExpression(Pcl4Parser::ExpressionContext *ctx)
{
    //TODO: This isn't working, need to fix visitExpression
    return visitChildren(ctx);
}

Object Executor::visitVariable(Pcl4Parser::VariableContext *ctx)
{
    //cout << "Visiting variable ";
    string variableName = ctx->getText();
    cout << variableName << endl;

    intermediate::symtab::SymtabEntry* entry = symbol_table.lookup(variableName);

    if(entry != nullptr){
        //cout << "stored value: " << entry->getValue() << endl;
        return entry->getValue();
    }
    else{
        return nullptr;
    }
}

Object Executor::visitNumber(Pcl4Parser::NumberContext *ctx)
{
    //cout << "Visiting number: got value ";
    string text = ctx->unsignedNumber()->integerConstant()
                                       ->INTEGER()->getText();
    int value = stoi(text);
    cout << value << endl;

    return value;
}

Object Executor::visitIntegerConstant(Pcl4Parser::IntegerConstantContext *ctx){
    string text = ctx->INTEGER()->toString();
    int value = stoi(text);
    return value;
}

// Complete this class!

}}  // namespace backend::interpreter
