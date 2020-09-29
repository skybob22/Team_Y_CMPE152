#ifndef EXECUTOR_H_
#define EXECUTOR_H_

#include <string>
#include <map>

#include "antlr4-runtime.h"
#include "Pcl4BaseVisitor.h"
#include "intermediate/symtab/Symtab.h"

#include "Object.h"

namespace backend { namespace interpreter {

using namespace std;

typedef antlrcpp::Any Object;

class Executor : public Pcl4BaseVisitor
{
public:
    Executor() {}
    virtual ~Executor() {}

    Object visitProgram(Pcl4Parser::ProgramContext *ctx) override;
    Object visitStatement(Pcl4Parser::StatementContext *ctx) override;
    Object visitStatementList(Pcl4Parser::StatementListContext *ctx) override;
    Object visitCompoundStatement(Pcl4Parser::CompoundStatementContext *ctx) override;
    Object visitAssignmentStatement(Pcl4Parser::AssignmentStatementContext *ctx) override;

    Object visitRepeatStatement(Pcl4Parser::RepeatStatementContext *ctx) override;
    Object visitWhileLoop(Pcl4Parser::WhileLoopContext *ctx) override;
    Object visitForLoop(Pcl4Parser::ForLoopContext *ctx) override;

    Object visitIfStatement(Pcl4Parser::IfStatementContext *ctx) override;
    Object visitCaseStatement(Pcl4Parser::CaseStatementContext *ctx) override;
    Object visitCaseBlock(Pcl4Parser::CaseBlockContext *ctx) override;
    Object visitConstantList(Pcl4Parser::ConstantListContext *ctx) override;

    Object visitWriteStatement(Pcl4Parser::WriteStatementContext *ctx) override;
    Object visitWriteArgumentList(Pcl4Parser::WriteArgumentListContext *ctx) override;
    Object visitWriteArgument(Pcl4Parser::WriteArgumentContext *ctx) override;
    Object visitWritelnStatement(Pcl4Parser::WritelnStatementContext *ctx) override;
    Object visitExpression(Pcl4Parser::ExpressionContext *ctx) override;
    Object visitVariable(Pcl4Parser::VariableContext *ctx) override;
    Object visitNumber(Pcl4Parser::NumberContext *ctx) override;
    Object visitIntegerConstant(Pcl4Parser::IntegerConstantContext *ctx) override;

    // Complete this class!

private:
    intermediate::symtab::Symtab symbol_table;

};

}}  // namespace backend::interpreter

#endif /* EXECUTOR_H_ */
