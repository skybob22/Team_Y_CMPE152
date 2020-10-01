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
    Object value = visitExpression(ctx->rhs()->expression());

    intermediate::symtab::SymtabEntry* entry;
    if(symbol_table.lookup(variableName) != nullptr) {
        entry = symbol_table.lookup(variableName);
    }
    else{
        entry = symbol_table.enter(variableName);
    }

    if(value.is<int>()){
        entry->setValue(value.as<int>());
        entry->type = intermediate::symtab::SymtabEntry::dtype::i;
    }
    else{
        entry->setValue(value);
        entry->type = intermediate::symtab::SymtabEntry::dtype::d;
    }

    return nullptr;
}

Object Executor::visitRepeatStatement(Pcl4Parser::RepeatStatementContext *ctx)
{
    do{
        visitStatementList(ctx->statementList());
    } while(!visitExpression(ctx->expression()).as<bool>());

   return nullptr;
}

Object Executor::visitWhileLoop(Pcl4Parser::WhileLoopContext *ctx) {
    while(visitExpression(ctx->expression()).as<bool>()){
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
            return custOp::operator+(c,1);
        };
        comp = [](antlrcpp::Any c,antlrcpp::Any stop){
            return custOp::operator<=(c,stop);
        };
    }
    else{
        //Decrement the counter
        op = [](antlrcpp::Any c){
            return custOp::operator-(c,1);
        };
        comp = [](antlrcpp::Any c,antlrcpp::Any stop){
            return custOp::operator>=(c,stop);
        };
    }

    for(antlrcpp::Any i = visitExpression(ctx->expression(0));comp(i,visitExpression(ctx->expression(1)));i = op(i)){
        //Update the variable with the current value
        intermediate::symtab::SymtabEntry* entry = symbol_table.lookup(ctx->variable()->getText());
        if(!entry){
            //Symbol not in table
            entry = symbol_table.enter(ctx->variable()->getText());
        }
        entry->setValue(castObjTo<int>(i));

        //Do stuff
        visitStatement(ctx->statement());
    }

    return nullptr;
}

Object Executor::visitIfStatement(Pcl4Parser::IfStatementContext *ctx){
    if(visitExpression(ctx->expression()).as<bool>()){
        visitStatement(ctx->statement(0));
    }
    else if(ctx->children.size() > 4){
        //Visit the else statement if it exists and the expression is not true
        visitStatement(ctx->statement(1));
    }
    return nullptr;
}

Object Executor::visitCaseStatement(Pcl4Parser::CaseStatementContext *ctx){
    int value = visitExpression(ctx->expression()).as<int>();

    bool done = false;
    for(int i=0;i<ctx->caseBlock().size() && !done;i++){

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
    for(int i=0;i<ctx->integerConstant().size();i++){
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
    int tmp = ctx->writeArgument().size();
    for(int i=0;i<ctx->writeArgument().size();i++){
        retString = retString + visitWriteArgument(ctx->writeArgument(i)).as<string>();
        if(i < ctx->writeArgument().size() -1){
            retString = retString + " ";
        }
    }
    return retString;
}

Object Executor::visitWriteArgument(Pcl4Parser::WriteArgumentContext *ctx){
    antlrcpp::Any value = visitExpression(ctx->expression());
    char printBuffer[256] = {0};

    if(value.is<string>()){
        snprintf(printBuffer,256,"%s",value.as<string>().c_str());
    }
    else if(value.is<int>()){
        snprintf(printBuffer,256,"%d", value.as<int>());
    }
    else if(value.is<double>()){
        //First get desired number of decimal places
        if(ctx->fieldWidth() && ctx->fieldWidth()->decimalPlaces()) {
            snprintf(printBuffer,256, "%.*f",visitIntegerConstant(ctx->fieldWidth()->decimalPlaces()->integerConstant()).as<int>(),value.as<double>());
        }
        else{
            snprintf(printBuffer,256,"%f", value.as<double>());
        }
    }
    //Make copy to free up buffer
    std::string retString(printBuffer);

    //If size specifier
    if(ctx->fieldWidth()){
        int fieldWidth = castObjTo<int>(visitIntegerConstant(ctx->fieldWidth()->integerConstant()));
        snprintf(printBuffer,256,"% *s",fieldWidth * -1,retString.c_str());
    }
    return std::string(printBuffer);
}

Object Executor::visitWritelnStatement(Pcl4Parser::WritelnStatementContext *ctx)
{
    if(ctx->writeArgumentsLn()) {
        string retString = visitWriteArgumentList(ctx->writeArgumentsLn()->writeArgumentListLn()->writeArgumentList()).as<string>();
        cout << retString << endl;
    }
    else{
        cout << endl;
    }
    //string retString = ctx->getText();

    return nullptr;
}

Object Executor::visitExpression(Pcl4Parser::ExpressionContext *ctx)
{
    antlrcpp::Any value = visitSimpleExpression(ctx->simpleExpression(0));

    //If there is a relational operator
    //Overloading the operators didn't work correctly, so have to call them with fully-qualified identifier
    if (ctx->relOp()) {
        if (ctx->relOp()->getText() == "=") {
            return custOp::operator==(value,visitSimpleExpression(ctx->simpleExpression(1)));
        } else if (ctx->relOp()->getText() == "<>") {
            return custOp::operator!=(value,visitSimpleExpression(ctx->simpleExpression(1)));
        } else if (ctx->relOp()->getText() == "<") {
            return custOp::operator<(value,visitSimpleExpression(ctx->simpleExpression(1)));
        } else if (ctx->relOp()->getText() == "<=") {
            return custOp::operator<=(value,visitSimpleExpression(ctx->simpleExpression(1)));
        } else if (ctx->relOp()->getText() == ">") {
            return custOp::operator>(value,visitSimpleExpression(ctx->simpleExpression(1)));
        } else if (ctx->relOp()->getText() == ">=") {
            return custOp::operator>=(value,visitSimpleExpression(ctx->simpleExpression(1)));
        }
    }

    return value;
}

Object Executor::visitSimpleExpression(Pcl4Parser::SimpleExpressionContext *ctx){
    antlrcpp::Any value = visitTerm(ctx->term(0));

    //Overloading the operators didn't work correctly, so have to call them with fully-qualified identifier
    for(int i=1;i<ctx->term().size();i++){
        if(ctx->addOp(i-1)->getText() == "OR"){
            value = custOp::operator||(value,visitTerm(ctx->term(i)));
        }
        else if(ctx->addOp(i-1)->getText() == "+"){
            value = custOp::operator+(value,visitTerm(ctx->term(i)));
        }
        else if(ctx->addOp(i-1)->getText() == "-"){
            value = custOp::operator-(value,visitTerm(ctx->term(i)));
        }
    }

    return value;
}

Object Executor::visitTerm(Pcl4Parser::TermContext *ctx){
    antlrcpp::Any value = visitFactor(ctx->factor(0));

    //Overloading the operators didn't work correctly, so have to call them with fully-qualified identifier
    for(int i=1;i<ctx->factor().size();i++){
        if(ctx->mulOp(i-1)->getText() == "*"){
            value = custOp::operator*(value,visitFactor(ctx->factor(i)));
        }
        else if(ctx->mulOp(i-1)->getText() == "/"){
            value = custOp::operator/(value,visitFactor(ctx->factor(i)));
        }
        else if(ctx->mulOp(i-1)->getText() == "DIV"){
            Object rhs = visitFactor(ctx->factor(i));
            int res = castObjTo<int>(value) / castObjTo<int>(rhs);
            value = Object(res);
        }
        else if(ctx->mulOp(i-1)->getText() == "MOD"){
            Object rhs = visitFactor(ctx->factor(i));
            int res = castObjTo<int>(value) % castObjTo<int>(rhs);
            value = Object(res);
        }
        else if(ctx->mulOp(i-1)->getText() == "AND"){
            value = value && visitFactor(ctx->factor(i));
        }
    }
    return value;
}

Object Executor::visitFactor(Pcl4Parser::FactorContext *ctx) {
    if(ctx->variable()){
        return visitVariable(ctx->variable());
    }
    else if(ctx->number()){
        return visitNumber(ctx->number());
    }
    else if(ctx->characterConstant()){
        std::string text = ctx->characterConstant()->CHARACTER()->getText();
        std::string ch = text.substr(1,1);
        return ch;
    }
    else if(ctx->stringConstant()){
        std::string text = ctx->stringConstant()->getText();
        std::string str = text.substr(1,text.size()-2);
        return str;
    }
    else if(ctx->NOT()){
        //Not factor
        return !(visitFactor(ctx->factor()).as<bool>());
    }
    else{
        return visitExpression(ctx->expression());
    }
}

Object Executor::visitVariable(Pcl4Parser::VariableContext *ctx)
{
    string variableName = ctx->getText();
    intermediate::symtab::SymtabEntry* entry = symbol_table.lookup(variableName);

    if(entry != nullptr){
        //cout << "stored value: " << entry->getValue() << endl;
        if(entry->type == intermediate::symtab::SymtabEntry::dtype::d){
            return entry->getValue();
        }
        else{
            return static_cast<int>(entry->getValue());
        }
    }
    else{
        return nullptr;
    }
}

Object Executor::visitNumber(Pcl4Parser::NumberContext *ctx)
{
    //Integer
    if(ctx->unsignedNumber()->integerConstant()) {
        string text = ctx->unsignedNumber()->integerConstant()->INTEGER()->getText();
        int value = stoi(text);
        return value;
    }
    if(ctx->unsignedNumber()->realConstant()){
        string text = ctx->unsignedNumber()->realConstant()->REAL()->getText();
        double value = stod(text);
        return value;
    }
    return nullptr;
}

Object Executor::visitIntegerConstant(Pcl4Parser::IntegerConstantContext *ctx){
    string text = ctx->INTEGER()->getText();
    int value = stoi(text);
    return value;
}

// Complete this class!

}}  // namespace backend::interpreter