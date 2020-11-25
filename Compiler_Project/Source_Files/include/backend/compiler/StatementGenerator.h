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


private:


private:
    //A couple utility tools
    string typeToString(Typespec* type);
    void emitCast(Typespec* from, Typespec* to);
};

}} // namespace backend::compiler

#endif /* STATEMENTGENERATOR_H_ */
