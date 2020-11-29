#ifndef SEMANTICS_H_
#define SEMANTICS_H_

#include <map>

#include "CBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/util/BackendMode.h"
#include "frontend/SemanticErrorHandler.h"

namespace frontend {

    using namespace std;
    using namespace intermediate::symtab;
    using namespace intermediate::type;

    class Semantics : public CBaseVisitor
    {
    private:
        string programName;
        BackendMode mode;
        SymtabStack *symtabStack;
        SymtabEntry *programId;
        SemanticErrorHandler error;

        map<string, Typespec *> *typeTable;

        /**
         * Return the number of values in a datatype.
         * @param type the datatype.
         * @return the number of values.
         */
        int typeCount(Typespec *type);

        /**
         * Determine whether or not an expression is a variable only.
         * @param exprCtx the ExpressionContext.
         * @return true if it's an expression only, else false.
         */
        bool expressionIsVariable(CParser::ExpressionContext *exprCtx);

        /**
         * Perform semantic operations on procedure and function call arguments.
         * @param listCtx the ArgumentListContext.
         * @param parameters the vector of parameters to fill.
         */
        void checkCallArguments(CParser::ArgumentListContext *listCtx,
                                vector<SymtabEntry *> *parms);

        /**
         * Determine the datatype of a variable that can have modifiers.
         * @param varCtx the VariableContext.
         * @param varType the variable's datatype without the modifiers.
         * @return the datatype with any modifiers.
         */
        Typespec *variableDatatype(CParser::VariableContext *varCtx,
                                   Typespec *varType);

        void postErrorCheck();


    public:
        Semantics(BackendMode mode,string programName) : mode(mode), programId(nullptr), programName(programName)
        {
            // Create and initialize the symbol table stack.
            symtabStack = new SymtabStack();
            Predefined::initialize(symtabStack);

            typeTable = new map<string, Typespec *>();
            (*typeTable)["integer"] = Predefined::integerType;
            (*typeTable)["real"]    = Predefined::realType;
            (*typeTable)["boolean"] = Predefined::booleanType;
            (*typeTable)["char"]    = Predefined::charType;
            (*typeTable)["string"]  = Predefined::stringType;
            (*typeTable)["void"]  = Predefined::voidType;
        }

        /**
         * Get the symbol table entry of the program identifier.
         * @return the entry.
         */
        SymtabEntry *getProgramId() { return programId; }

        /**
         * Get the count of semantic errors.
         * @return the count.
         */
        int getErrorCount() const;

        Object visitProgram(CParser::ProgramContext *ctx) override;
        Object visitVariableDeclaration(CParser::VariableDeclarationContext *ctx) override;
        Object visitTypeIdentifier(CParser::TypeIdentifierContext *ctx) override;
        Object visitLhs(CParser::LhsContext *ctx) override;
        Object visitAssignVariable(CParser::AssignVariableContext *ctx) override;
        Object visitDecrementVariable(CParser::DecrementVariableContext *ctx) override;
        Object visitIncrementVariable(CParser::IncrementVariableContext *ctx) override;

        Object visitFunctionDeclaration(CParser::FunctionDeclarationContext *ctx) override;
        Object visitFunctionDefinition(CParser::FunctionDefinitionContext *ctx) override;
        Object visitParameterDeclarationsList(CParser::ParameterDeclarationsListContext *ctx) override;
        Object visitParameterDeclaration(CParser::ParameterDeclarationContext *ctx) override;

        Object visitDoWhileLoop(CParser::DoWhileLoopContext *ctx) override;
        Object visitWhileLoop(CParser::WhileLoopContext *ctx) override;
        Object visitForLoop(CParser::ForLoopContext *ctx) override;
        Object visitIfStatement(CParser::IfStatementContext *ctx) override;

        Object visitFunctionCall(CParser::FunctionCallContext *ctx) override;
        Object visitFunctionCallFactor(CParser::FunctionCallFactorContext *ctx) override;
        Object visitReturnStatement(CParser::ReturnStatementContext *ctx) override;

        Object visitExpression(CParser::ExpressionContext *ctx) override;
        Object visitSimpleExpression(CParser::SimpleExpressionContext *ctx) override;
        Object visitTerm(CParser::TermContext *ctx) override;
        Object visitVariableFactor(CParser::VariableFactorContext *ctx) override;
        Object visitVariable(CParser::VariableContext *ctx) override;
        Object visitVariableIdentifier(CParser::VariableIdentifierContext *ctx) override;
        Object visitNumberFactor(CParser::NumberFactorContext *ctx) override;
        Object visitCharacterFactor(CParser::CharacterFactorContext *ctx) override;
        Object visitStringFactor(CParser::StringFactorContext *ctx) override;
        Object visitNotFactor(CParser::NotFactorContext *ctx) override;
        Object visitParenthesizedFactor(CParser::ParenthesizedFactorContext *ctx) override;

    };

} // namespace frontend

#endif /* SEMANTICS_H_ */
