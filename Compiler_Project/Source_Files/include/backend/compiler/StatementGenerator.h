#ifndef STATEMENTGENERATOR_H_
#define STATEMENTGENERATOR_H_

#include <vector>
#include <map>

#include "backend/compiler/ASMCodeGenerator.h"

namespace backend { namespace compiler {

using namespace std;

class StatementGenerator : public CodeGenerator
{
public:
    /**
     * Constructor.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    StatementGenerator(CodeGenerator *parent, Compiler *compiler,string outputDir="")
        : CodeGenerator(parent, compiler,outputDir) {}

    void emitAssignment(CParser::AssignVariableContext *ctx);

    void emitDeclarationAssignment(CParser::AssignVariableContext *ctx);

    void emitIncrement(CParser::IncrementVariableContext *ctx);

    void emitDecrement(CParser::DecrementVariableContext *ctx);

    void emitIf(CParser::IfStatementContext *ctx);

    void emitDoWhile(CParser::DoWhileLoopContext *ctx);

    void emitWhile(CParser::WhileLoopContext *ctx);

    void emitFor(CParser::ForLoopContext *ctx);

    void emitProcedureCall(CParser::FunctionCallContext *ctx);

    void emitFunctionCall(CParser::FunctionCallContext *ctx);

    void emitPrint(CParser::PrintStatementContext *ctx);

    void emitPrintln(CParser::PrintlnStatementContext *ctx);

    void emitRead(CParser::ReadStatementContext *ctx);

    void emitReadln(CParser::ReadlnStatementContext *ctx);

    void emitReturn(CParser::ReturnStatementContext *ctx);

private:

    void emitCall(SymtabEntry *routineId, CParser::ArgumentListContext *argListCtx);

    void emitPrint(CParser::PrintArgumentsContext *argsCtx, bool needLF);

    int createPrintFormat(CParser::PrintArgumentsContext *argsCtx, string& format,bool needLF);

    void emitArgumentsArray(CParser::PrintArgumentsContext *argsCtx,int exprCount);

    void emitRead(CParser::ReadArgumentsContext *argsCtx, bool needSkip);

private:
    //A couple utility tools
    string typeToString(Typespec* type);
    void emitCast(Typespec* from, Typespec* to);
};

}} // namespace backend::compiler

#endif /* STATEMENTGENERATOR_H_ */
