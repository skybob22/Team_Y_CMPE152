#ifndef EXPRESSIONGENERATOR_H_
#define EXPRESSIONGENERATOR_H_

#include "backend/compiler/ASMCodeGenerator.h"

namespace backend { namespace compiler {

class ExpressionGenerator : public CodeGenerator
{
public:
    /**
     * Constructor.
     * @param parent the parent code generator.
     * @param compiler the compiler to use.
     */
    ExpressionGenerator(CodeGenerator *parent, Compiler *compiler,string outputDir="")
        : CodeGenerator(parent, compiler,outputDir) {}

    void emitExpression(CParser::ExpressionContext *ctx);

    void emitSimpleExpression(CParser::SimpleExpressionContext *ctx);

    void emitTerm(CParser::TermContext *ctx);

    void emitNotFactor(CParser::NotFactorContext *ctx);

    void emitLoadValue(CParser::VariableContext *varCtx);

    Typespec *emitLoadVariable(CParser::VariableContext *varCtx);

    void emitLoadIntegerConstant(CParser::NumberContext *intCtx);

    void emitLoadRealConstant(CParser::NumberContext *realCtx);

private:

};

}} // namespace backend::compiler

#endif /* EXPRESSIONGENERATOR_H_ */
