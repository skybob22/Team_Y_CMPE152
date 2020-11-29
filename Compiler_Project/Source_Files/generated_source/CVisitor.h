
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from ../Source_Files/antlr/C.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "CParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CParser.
 */
class  CVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by CParser.
   */
    virtual antlrcpp::Any visitProgram(CParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitC_statement(CParser::C_statementContext *context) = 0;

    virtual antlrcpp::Any visitStatement(CParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(CParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclaration(CParser::VariableDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitLength(CParser::LengthContext *context) = 0;

    virtual antlrcpp::Any visitAssignVariable(CParser::AssignVariableContext *context) = 0;

    virtual antlrcpp::Any visitIncrementVariable(CParser::IncrementVariableContext *context) = 0;

    virtual antlrcpp::Any visitDecrementVariable(CParser::DecrementVariableContext *context) = 0;

    virtual antlrcpp::Any visitLhs(CParser::LhsContext *context) = 0;

    virtual antlrcpp::Any visitRhs(CParser::RhsContext *context) = 0;

    virtual antlrcpp::Any visitControlScope(CParser::ControlScopeContext *context) = 0;

    virtual antlrcpp::Any visitControlStatement(CParser::ControlStatementContext *context) = 0;

    virtual antlrcpp::Any visitDoWhileLoop(CParser::DoWhileLoopContext *context) = 0;

    virtual antlrcpp::Any visitWhileLoop(CParser::WhileLoopContext *context) = 0;

    virtual antlrcpp::Any visitForLoop(CParser::ForLoopContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(CParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(CParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(CParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionIdentifier(CParser::FunctionIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclarationsList(CParser::ParameterDeclarationsListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(CParser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitParameterIdentifier(CParser::ParameterIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(CParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(CParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(CParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitArgument(CParser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitPrintStatement(CParser::PrintStatementContext *context) = 0;

    virtual antlrcpp::Any visitPrintlnStatement(CParser::PrintlnStatementContext *context) = 0;

    virtual antlrcpp::Any visitPrintArguments(CParser::PrintArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitPrintArgument(CParser::PrintArgumentContext *context) = 0;

    virtual antlrcpp::Any visitFieldWidth(CParser::FieldWidthContext *context) = 0;

    virtual antlrcpp::Any visitDecimalPlaces(CParser::DecimalPlacesContext *context) = 0;

    virtual antlrcpp::Any visitReadStatement(CParser::ReadStatementContext *context) = 0;

    virtual antlrcpp::Any visitReadlnStatement(CParser::ReadlnStatementContext *context) = 0;

    virtual antlrcpp::Any visitReadArguments(CParser::ReadArgumentsContext *context) = 0;

    virtual antlrcpp::Any visitExpression(CParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(CParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTerm(CParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitVariableFactor(CParser::VariableFactorContext *context) = 0;

    virtual antlrcpp::Any visitNumberFactor(CParser::NumberFactorContext *context) = 0;

    virtual antlrcpp::Any visitCharacterFactor(CParser::CharacterFactorContext *context) = 0;

    virtual antlrcpp::Any visitStringFactor(CParser::StringFactorContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCallFactor(CParser::FunctionCallFactorContext *context) = 0;

    virtual antlrcpp::Any visitNotFactor(CParser::NotFactorContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedFactor(CParser::ParenthesizedFactorContext *context) = 0;

    virtual antlrcpp::Any visitVariable(CParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitModifier(CParser::ModifierContext *context) = 0;

    virtual antlrcpp::Any visitIndex(CParser::IndexContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifier(CParser::VariableIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitNumber(CParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumber(CParser::UnsignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitSign(CParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitIntegerConstant(CParser::IntegerConstantContext *context) = 0;

    virtual antlrcpp::Any visitRealConstant(CParser::RealConstantContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(CParser::RelOpContext *context) = 0;

    virtual antlrcpp::Any visitAddOp(CParser::AddOpContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(CParser::MulOpContext *context) = 0;

    virtual antlrcpp::Any visitTypeIdentifier(CParser::TypeIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitCharacterConstant(CParser::CharacterConstantContext *context) = 0;

    virtual antlrcpp::Any visitStringConstant(CParser::StringConstantContext *context) = 0;


};

