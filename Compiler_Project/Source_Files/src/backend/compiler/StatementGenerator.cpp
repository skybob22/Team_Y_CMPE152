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
            {Predefined::undefinedType,"V"}
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


}} // namespace backend::compiler
