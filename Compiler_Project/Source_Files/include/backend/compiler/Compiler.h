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
            Compiler(SymtabEntry *programId,string outputFile="")
                    : programId(programId), programName(programId->getName()),
                      code(new CodeGenerator(programName, "j", this,outputFile)),
                      programCode(nullptr), statementCode(nullptr),
                      expressionCode(nullptr) {}

            /**
             * Constructor for child compilers of procedures and functions.
             * @param parent the parent compiler.
             */
            Compiler(Compiler *parent,string outputFile="")
                    : programId(parent->programId), programName(parent->programName),
                      code(parent->code), programCode(parent->programCode),
                      statementCode(nullptr), expressionCode(nullptr) {}


            /**
             * Get the name of the object (Jasmin) file.
             * @return the file name.
             */
            string getObjectFileName() { return code->getObjectFileName(); }

            Object visitProgram(CParser::ProgramContext *ctx) override;
            Object visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override;
            Object visitStatement(CParser::StatementContext *ctx) override;
            Object visitAssignVariable(CParser::AssignVariableContext *ctx) override;
            Object visitIncrementVariable(CParser::IncrementVariableContext *ctx) override;
            Object visitDecrementVariable(CParser::DecrementVariableContext *ctx) override;
            Object visitIfStatement(CParser::IfStatementContext *ctx) override;
            Object visitDoWhileLoop(CParser::DoWhileLoopContext *ctx) override;
            Object visitWhileLoop(CParser::WhileLoopContext *ctx) override;
            Object visitForLoop(CParser::ForLoopContext *ctx) override;
            Object visitFunctionCall(CParser::FunctionCallContext *ctx) override;
            Object visitReturnStatement(CParser::ReturnStatementContext *ctx) override;
            Object visitExpression(CParser::ExpressionContext *ctx) override;
            Object visitVariableFactor(CParser::VariableFactorContext *ctx) override;
            Object visitVariable(CParser::VariableContext *ctx) override;
            Object visitNumberFactor(CParser::NumberFactorContext *ctx) override;
            Object visitCharacterFactor(CParser::CharacterFactorContext *ctx) override;
            Object visitStringFactor(CParser::StringFactorContext *ctx) override;
            Object visitFunctionCallFactor(CParser::FunctionCallFactorContext *ctx) override;
            Object visitNotFactor(CParser::NotFactorContext *ctx) override;
            Object visitParenthesizedFactor(CParser::ParenthesizedFactorContext *ctx) override;
            Object visitPrintStatement(CParser::PrintStatementContext *ctx) override;
            Object visitPrintlnStatement(CParser::PrintlnStatementContext *ctx) override;
            Object visitReadStatement(CParser::ReadStatementContext *ctx) override;
            Object visitReadlnStatement(CParser::ReadlnStatementContext *ctx) override;


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