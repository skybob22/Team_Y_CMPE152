// Generated from ../Source_Files/antlr/Pascal_Java.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeVisitor;

/**
 * This interface defines a complete generic visitor for a parse tree produced
 * by {@link Pascal_JavaParser}.
 *
 * @param <T> The return type of the visit operation. Use {@link Void} for
 * operations with no return type.
 */
public interface Pascal_JavaVisitor<T> extends ParseTreeVisitor<T> {
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#program}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgram(Pascal_JavaParser.ProgramContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#programHeader}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgramHeader(Pascal_JavaParser.ProgramHeaderContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#programParameters}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgramParameters(Pascal_JavaParser.ProgramParametersContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#programIdentifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProgramIdentifier(Pascal_JavaParser.ProgramIdentifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#block}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitBlock(Pascal_JavaParser.BlockContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#declarations}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDeclarations(Pascal_JavaParser.DeclarationsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#constantsPart}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantsPart(Pascal_JavaParser.ConstantsPartContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#constantDefinitionsList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantDefinitionsList(Pascal_JavaParser.ConstantDefinitionsListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#constantDefinition}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantDefinition(Pascal_JavaParser.ConstantDefinitionContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#constantIdentifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstantIdentifier(Pascal_JavaParser.ConstantIdentifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#constant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitConstant(Pascal_JavaParser.ConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#sign}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSign(Pascal_JavaParser.SignContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#typesPart}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypesPart(Pascal_JavaParser.TypesPartContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#typeDefinitionsList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeDefinitionsList(Pascal_JavaParser.TypeDefinitionsListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#typeDefinition}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeDefinition(Pascal_JavaParser.TypeDefinitionContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#typeIdentifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeIdentifier(Pascal_JavaParser.TypeIdentifierContext ctx);
	/**
	 * Visit a parse tree produced by the {@code simpleTypespec}
	 * labeled alternative in {@link Pascal_JavaParser#typeSpecification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSimpleTypespec(Pascal_JavaParser.SimpleTypespecContext ctx);
	/**
	 * Visit a parse tree produced by the {@code arrayTypespec}
	 * labeled alternative in {@link Pascal_JavaParser#typeSpecification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayTypespec(Pascal_JavaParser.ArrayTypespecContext ctx);
	/**
	 * Visit a parse tree produced by the {@code recordTypespec}
	 * labeled alternative in {@link Pascal_JavaParser#typeSpecification}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecordTypespec(Pascal_JavaParser.RecordTypespecContext ctx);
	/**
	 * Visit a parse tree produced by the {@code typeIdentifierTypespec}
	 * labeled alternative in {@link Pascal_JavaParser#simpleType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTypeIdentifierTypespec(Pascal_JavaParser.TypeIdentifierTypespecContext ctx);
	/**
	 * Visit a parse tree produced by the {@code enumerationTypespec}
	 * labeled alternative in {@link Pascal_JavaParser#simpleType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumerationTypespec(Pascal_JavaParser.EnumerationTypespecContext ctx);
	/**
	 * Visit a parse tree produced by the {@code subrangeTypespec}
	 * labeled alternative in {@link Pascal_JavaParser#simpleType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubrangeTypespec(Pascal_JavaParser.SubrangeTypespecContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#enumerationType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumerationType(Pascal_JavaParser.EnumerationTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#enumerationConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEnumerationConstant(Pascal_JavaParser.EnumerationConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#subrangeType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSubrangeType(Pascal_JavaParser.SubrangeTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#arrayType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayType(Pascal_JavaParser.ArrayTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#arrayDimensionList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArrayDimensionList(Pascal_JavaParser.ArrayDimensionListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#recordType}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecordType(Pascal_JavaParser.RecordTypeContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#recordFields}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRecordFields(Pascal_JavaParser.RecordFieldsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#variablesPart}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariablesPart(Pascal_JavaParser.VariablesPartContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#variableDeclarationsList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableDeclarationsList(Pascal_JavaParser.VariableDeclarationsListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#variableDeclarations}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableDeclarations(Pascal_JavaParser.VariableDeclarationsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#variableIdentifierList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableIdentifierList(Pascal_JavaParser.VariableIdentifierListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#variableIdentifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableIdentifier(Pascal_JavaParser.VariableIdentifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#routinesPart}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRoutinesPart(Pascal_JavaParser.RoutinesPartContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#routineDefinition}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRoutineDefinition(Pascal_JavaParser.RoutineDefinitionContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#procedureHead}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProcedureHead(Pascal_JavaParser.ProcedureHeadContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#functionHead}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionHead(Pascal_JavaParser.FunctionHeadContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#routineIdentifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRoutineIdentifier(Pascal_JavaParser.RoutineIdentifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#parameters}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameters(Pascal_JavaParser.ParametersContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#parameterDeclarationsList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterDeclarationsList(Pascal_JavaParser.ParameterDeclarationsListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#parameterDeclarations}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterDeclarations(Pascal_JavaParser.ParameterDeclarationsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#parameterIdentifierList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterIdentifierList(Pascal_JavaParser.ParameterIdentifierListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#parameterIdentifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParameterIdentifier(Pascal_JavaParser.ParameterIdentifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#statement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatement(Pascal_JavaParser.StatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#compoundStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCompoundStatement(Pascal_JavaParser.CompoundStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#emptyStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitEmptyStatement(Pascal_JavaParser.EmptyStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#statementList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStatementList(Pascal_JavaParser.StatementListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#assignmentStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAssignmentStatement(Pascal_JavaParser.AssignmentStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#lhs}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitLhs(Pascal_JavaParser.LhsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#rhs}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRhs(Pascal_JavaParser.RhsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#ifStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIfStatement(Pascal_JavaParser.IfStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#trueStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTrueStatement(Pascal_JavaParser.TrueStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#falseStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFalseStatement(Pascal_JavaParser.FalseStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#caseStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCaseStatement(Pascal_JavaParser.CaseStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#caseBranchList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCaseBranchList(Pascal_JavaParser.CaseBranchListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#caseBranch}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCaseBranch(Pascal_JavaParser.CaseBranchContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#caseConstantList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCaseConstantList(Pascal_JavaParser.CaseConstantListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#caseConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCaseConstant(Pascal_JavaParser.CaseConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#repeatStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRepeatStatement(Pascal_JavaParser.RepeatStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#whileStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitWhileStatement(Pascal_JavaParser.WhileStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#forStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitForStatement(Pascal_JavaParser.ForStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#procedureCallStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProcedureCallStatement(Pascal_JavaParser.ProcedureCallStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#procedureName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitProcedureName(Pascal_JavaParser.ProcedureNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#argumentList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArgumentList(Pascal_JavaParser.ArgumentListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#argument}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitArgument(Pascal_JavaParser.ArgumentContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#writeStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitWriteStatement(Pascal_JavaParser.WriteStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#writelnStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitWritelnStatement(Pascal_JavaParser.WritelnStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#writeArguments}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitWriteArguments(Pascal_JavaParser.WriteArgumentsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#writeArgument}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitWriteArgument(Pascal_JavaParser.WriteArgumentContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#fieldWidth}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFieldWidth(Pascal_JavaParser.FieldWidthContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#decimalPlaces}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitDecimalPlaces(Pascal_JavaParser.DecimalPlacesContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#readStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReadStatement(Pascal_JavaParser.ReadStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#readlnStatement}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReadlnStatement(Pascal_JavaParser.ReadlnStatementContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#readArguments}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitReadArguments(Pascal_JavaParser.ReadArgumentsContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#expression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitExpression(Pascal_JavaParser.ExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#simpleExpression}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitSimpleExpression(Pascal_JavaParser.SimpleExpressionContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#term}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitTerm(Pascal_JavaParser.TermContext ctx);
	/**
	 * Visit a parse tree produced by the {@code variableFactor}
	 * labeled alternative in {@link Pascal_JavaParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariableFactor(Pascal_JavaParser.VariableFactorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code numberFactor}
	 * labeled alternative in {@link Pascal_JavaParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumberFactor(Pascal_JavaParser.NumberFactorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code characterFactor}
	 * labeled alternative in {@link Pascal_JavaParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCharacterFactor(Pascal_JavaParser.CharacterFactorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code stringFactor}
	 * labeled alternative in {@link Pascal_JavaParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStringFactor(Pascal_JavaParser.StringFactorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code functionCallFactor}
	 * labeled alternative in {@link Pascal_JavaParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionCallFactor(Pascal_JavaParser.FunctionCallFactorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code notFactor}
	 * labeled alternative in {@link Pascal_JavaParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNotFactor(Pascal_JavaParser.NotFactorContext ctx);
	/**
	 * Visit a parse tree produced by the {@code parenthesizedFactor}
	 * labeled alternative in {@link Pascal_JavaParser#factor}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitParenthesizedFactor(Pascal_JavaParser.ParenthesizedFactorContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#variable}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitVariable(Pascal_JavaParser.VariableContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#modifier}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitModifier(Pascal_JavaParser.ModifierContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#indexList}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIndexList(Pascal_JavaParser.IndexListContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#index}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIndex(Pascal_JavaParser.IndexContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#field}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitField(Pascal_JavaParser.FieldContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#functionCall}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionCall(Pascal_JavaParser.FunctionCallContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#functionName}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitFunctionName(Pascal_JavaParser.FunctionNameContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#number}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitNumber(Pascal_JavaParser.NumberContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#unsignedNumber}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitUnsignedNumber(Pascal_JavaParser.UnsignedNumberContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#integerConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitIntegerConstant(Pascal_JavaParser.IntegerConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#realConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRealConstant(Pascal_JavaParser.RealConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#characterConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitCharacterConstant(Pascal_JavaParser.CharacterConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#stringConstant}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitStringConstant(Pascal_JavaParser.StringConstantContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#relOp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitRelOp(Pascal_JavaParser.RelOpContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#addOp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitAddOp(Pascal_JavaParser.AddOpContext ctx);
	/**
	 * Visit a parse tree produced by {@link Pascal_JavaParser#mulOp}.
	 * @param ctx the parse tree
	 * @return the visitor result
	 */
	T visitMulOp(Pascal_JavaParser.MulOpContext ctx);
}