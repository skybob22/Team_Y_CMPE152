#ifndef COMPILER_H_
#define COMPILER_H_

#include "CBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/type/Typespec.h"
#include "backend/compiler/ProgramGenerator.h"
#include "backend/compiler/StatementGenerator.h"
#include "backend/compiler/ExpressionGenerator.h"

namespace backend { namespace compiler {

        using namespace std;
        using namespace intermediate::symtab;
        using namespace intermediate::type;

        class CodeGenerator;

        class Compiler : public CBaseVisitor
        {
        private:
            SymtabEntry *programId;  // symbol table entry of the program name
            string programName;      // the program name

            CodeGenerator       *code;            // base code generator
            ProgramGenerator    *programCode;     // program code generator
            StatementGenerator  *statementCode;   // statement code generator
            ExpressionGenerator *expressionCode;  // expression code generator

        public:
            /**
             * Constructor for the base compiler.
             * @param programId the symtab entry for the program name.
             */
            Compiler(SymtabEntry *programId,string outputDir="")
                    : programId(programId), programName(programId->getName()),
                      code(new CodeGenerator(programName, "j", this,outputDir)),
                      programCode(nullptr), statementCode(nullptr),
                      expressionCode(nullptr) {}

            /**
             * Constructor for child compilers of procedures and functions.
             * @param parent the parent compiler.
             */
            Compiler(Compiler *parent,string outputDir="")
                    : programId(parent->programId), programName(parent->programName),
                      code(parent->code), programCode(parent->programCode),
                      statementCode(nullptr), expressionCode(nullptr) {}


            /**
             * Get the name of the object (Jasmin) file.
             * @return the file name.
             */
            string getObjectFileName() { return code->getObjectFileName(); }


        private:
            /**
             * Create new child code generators.
             * @param parentGenerator the parent code generator.
             */
            void createNewGenerators(CodeGenerator *parentGenerator,string outputDir="")
            {
                programCode    = new ProgramGenerator(parentGenerator, this,outputDir);
                statementCode  = new StatementGenerator(programCode, this,outputDir);
                expressionCode = new ExpressionGenerator(programCode, this,outputDir);
            }
        };

    }}  // namespace backend::compiler

#endif /* COMPILER_H_ */