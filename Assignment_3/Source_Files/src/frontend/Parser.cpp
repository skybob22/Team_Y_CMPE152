/**
 * Parser class for a simple interpreter.
 *
 * (c) 2020 by Ronald Mak
 * Department of Computer Science
 * San Jose State University
 */
#include <string>
#include <map>
#include <deque>

#include "frontend/Token.h"
#include "frontend/Parser.h"

namespace frontend {

using namespace std;

set<TokenType> Parser::statementStarters;
set<TokenType> Parser::statementFollowers;
set<TokenType> Parser::relationalOperators;
set<TokenType> Parser::simpleExpressionOperators;
set<TokenType> Parser::termOperators;

void Parser::initialize()
{
    statementStarters.insert(BEGIN);
    statementStarters.insert(IDENTIFIER);
    statementStarters.insert(REPEAT);
    statementStarters.insert(WHILE);
    statementStarters.insert(TokenType::WRITE);
    statementStarters.insert(TokenType::WRITELN);
    statementStarters.insert(IF);

    statementFollowers.insert(SEMICOLON);
    statementFollowers.insert(END);
    statementFollowers.insert(UNTIL);
    statementFollowers.insert(END_OF_FILE);
    statementFollowers.insert(THEN);
    statementFollowers.insert(TO);
    statementFollowers.insert(DOWNTO);

    relationalOperators.insert(EQUALS);
    relationalOperators.insert(LESS_THAN);
    relationalOperators.insert(GREATER_THAN);
    relationalOperators.insert(LESS_EQUALS);
    relationalOperators.insert(GREATER_EQUALS);
    relationalOperators.insert(NOT_EQUALS);

    simpleExpressionOperators.insert(PLUS);
    simpleExpressionOperators.insert(MINUS);

    termOperators.insert(STAR);
    termOperators.insert(SLASH);
    termOperators.insert(DIV);
}

Node *Parser::parseProgram()
{
    Node *programNode = new Node(NodeType::PROGRAM);

    currentToken = scanner->nextToken();  // first token!

    if (currentToken->type == TokenType::PROGRAM)
    {
        currentToken = scanner->nextToken();  // consume PROGRAM
    }
    else syntaxError("Expecting PROGRAM");

    if (currentToken->type == IDENTIFIER)
    {
        string programName = currentToken->text;
        symtab->enter(programName);
        programNode->text = programName;

        currentToken = scanner->nextToken();  // consume program name
    }
    else syntaxError("Expecting program name");

    if (currentToken->type == SEMICOLON)
    {
        currentToken = scanner->nextToken();  // consume ;
    }
    else syntaxError("Missing ;");

    if (currentToken->type != BEGIN) syntaxError("Expecting BEGIN");

    // The PROGRAM node adopts the COMPOUND tree.
    programNode->adopt(parseCompoundStatement());

    if (currentToken->type == SEMICOLON) syntaxError("Expecting .");
    return programNode;
}

Node *Parser::parseStatement()
{
    Node *stmtNode = nullptr;
    int savedLineNumber = currentToken->lineNumber;
    lineNumber = savedLineNumber;

    switch (currentToken->type)
    {
        case IDENTIFIER : stmtNode = parseAssignmentStatement(); break;
        case BEGIN :      stmtNode = parseCompoundStatement();   break;
        //Looping statements
        case REPEAT :     stmtNode = parseRepeatStatement();     break;
        case WHILE :      stmtNode = parseWhileStatement();      break;
        case FOR :        stmtNode = parseForStatement();         break;

        case IF :         stmtNode = parseIfStatement();         break;
        case CASE :       stmtNode = parseCaseStatement();       break;

        case WRITE :      stmtNode = parseWriteStatement();      break;
        case WRITELN :    stmtNode = parseWritelnStatement();    break;
        case SEMICOLON :  stmtNode = nullptr; break;  // empty statement

        default : syntaxError("Unexpected token");
    }

    if (stmtNode != nullptr) stmtNode->lineNumber = savedLineNumber;
    return stmtNode;
}

Node *Parser::parseAssignmentStatement()
{
    // The current token should now be the left-hand-side variable name.

    Node *assignmentNode = new Node(ASSIGN);

    // The assignment Node *adopts the variable Node *as its first child.
    Node *lhsNode = new Node(VARIABLE);
    string variableName = currentToken->text;
    SymtabEntry *variableId = symtab->enter(toLowerCase(variableName));

    lhsNode->text  = variableName;
    lhsNode->entry = variableId;
    lhsNode->lineNumber = currentToken->lineNumber;
    assignmentNode->adopt(lhsNode);

    currentToken = scanner->nextToken();  // consume the LHS variable;

    if (currentToken->type == COLON_EQUALS)
    {
        currentToken = scanner->nextToken();  // consume :=
    }
    else syntaxError("Missing :=");

    // The assignment Node *adopts the expression Node *as its second child.
    Node *rhsNode = parseExpression();
    assignmentNode->adopt(rhsNode);

    return assignmentNode;
}

Node *Parser::parseCompoundStatement()
{
    Node *compoundNode = new Node(COMPOUND);
    compoundNode->lineNumber = currentToken->lineNumber;

    currentToken = scanner->nextToken();  // consume BEGIN
    parseStatementList(compoundNode, END);

    if (currentToken->type == END)
    {
        currentToken = scanner->nextToken();  // consume END
    }
    else syntaxError("Expecting END");

    return compoundNode;
}

void Parser::parseStatementList(Node *parentNode, TokenType terminalType)
{
    while (   (currentToken->type != terminalType)
           && (currentToken->type != END_OF_FILE))
    {
        Node *stmtNode = parseStatement();
        if (stmtNode != nullptr) parentNode->adopt(stmtNode);

        // A semicolon separates statements.
        if (currentToken->type == SEMICOLON)
        {
            while (currentToken->type == SEMICOLON)
            {
                currentToken = scanner->nextToken();  // consume ;
            }
        }
        else if (statementStarters.find(currentToken->type) !=
                                                        statementStarters.end())
        {
            syntaxError("Missing ;");
        }
    }
}

Node *Parser::parseRepeatStatement()
{
    // The current token should now be REPEAT.

    // Create a LOOP node->
    Node *loopNode = new Node(LOOP);
    currentToken = scanner->nextToken();  // consume REPEAT

    parseStatementList(loopNode, UNTIL);

    if (currentToken->type == UNTIL)
    {
        // Create a TEST node-> It adopts the test expression node->
        Node *testNode = new Node(TEST);
        lineNumber = currentToken->lineNumber;
        testNode->lineNumber = lineNumber;
        currentToken = scanner->nextToken();  // consume UNTIL

        testNode->adopt(parseExpression());

        // The LOOP Node *adopts the TEST Node *as its final child.
        loopNode->adopt(testNode);
    }
    else syntaxError("Expecting UNTIL");

    return loopNode;
}

Node *Parser::parseWhileStatement()
{
    // The current token should now be WHILE

    // Create a LOOP node with the test at the front
    Node *loopNode = new Node(LOOP);
    loopNode->lineNumber = currentToken->lineNumber;
    currentToken = scanner->nextToken(); // consume WHILE

    //Creates a TEST node which adopts the test expression node
    Node *testNode = new Node(TEST);
    lineNumber = currentToken->lineNumber;
    testNode->lineNumber = lineNumber;

    //Invert the test condition
    Node *invertedCondition = new Node(NodeType::NOT);
    invertedCondition->lineNumber = lineNumber;
    invertedCondition->adopt(parseExpression());
    testNode->adopt(invertedCondition);

    //Loop node adopts the test node as first child
    loopNode->adopt(testNode);


    if(currentToken->type != DO){
        syntaxError("Expected DO statement");
        return nullptr;
    }
    currentToken = scanner->nextToken(); //Consume DO statement
    loopNode->adopt(parseStatement());

    return loopNode;
}

Node *Parser::parseForStatement(){
    // Current token should now be FOR
    Node *compoundNode = new Node(COMPOUND);
    currentToken = scanner->nextToken();

    //Initialization step
    Node *initNode = parseAssignmentStatement();
    compoundNode->adopt(initNode);

    //Step node
    Node *iterNode = new Node(ASSIGN);
    iterNode->adopt(new Node(VARIABLE));
    iterNode->children[0]->text = initNode->children[0]->text; //Get variable to modify


    Node *compareNode = nullptr;
    if(currentToken->type == TO){
        currentToken = scanner->nextToken(); //Consume TO

        //Create test case
        compareNode = new Node(GT);
        compareNode->adopt(new Node(VARIABLE));
        compareNode->children[0]->text = initNode->children[0]->text;
        compareNode->adopt(parseExpression());

        //Increment at end of loop
        Node *addNode = new Node(ADD);
        addNode->adopt(new Node(VARIABLE));
        addNode->children[0]->text = initNode->children[0]->text; //Point at variable
        addNode->adopt(new Node(INTEGER_CONSTANT));
        addNode->children[1]->value = Object(static_cast<long>(1));

        iterNode->adopt(addNode);

    }
    else if(currentToken->type == DOWNTO){
        currentToken = scanner->nextToken(); //Consume DOWNTO

        //Create test case
        compareNode = new Node(LT);
        compareNode->adopt(new Node(VARIABLE));
        compareNode->children[0]->text = initNode->children[0]->text;
        compareNode->adopt(parseExpression());

        //Decrement at end of loop
        Node *addNode = new Node(SUBTRACT);
        addNode->adopt(new Node(VARIABLE));
        addNode->children[0]->text = initNode->children[0]->text; //Point at variable
        addNode->adopt(new Node(INTEGER_CONSTANT));
        addNode->children[1]->value = Object(static_cast<long>(1));

        iterNode->adopt(addNode);
    }
    else{
        //Missing range specifier

        return nullptr;
    }

    //Create looping node
    Node *loopNode = new Node(LOOP);
    loopNode->adopt(new Node(TEST));
    loopNode->children[0]->adopt(compareNode); //Adopt the comparison as a test

    //Token should be DO
    if(currentToken->type != DO){
        syntaxError("Expected DO statement");
        return nullptr;
    }
    currentToken = scanner->nextToken();
    loopNode->adopt(parseStatement());
    loopNode->adopt(iterNode);

    compoundNode->adopt(loopNode);
    return compoundNode;
}

Node *Parser::parseIfStatement(){
    // The current token should now be IF
    Node *ifNode = new Node(NodeType::IF);
    currentToken = scanner->nextToken();

    //Create a TEST node which adopts the target expression
    Node *testNode = new Node(TEST);
    lineNumber = currentToken->lineNumber;
    testNode->lineNumber = lineNumber;

    testNode->adopt(parseExpression());
    ifNode->adopt(testNode);

    if (currentToken->type != THEN){
        syntaxError("Expected THEN statement");
    }
    currentToken = scanner->nextToken(); //Consume THEN statement

    //Adopt the following statement;
    ifNode->adopt(parseStatement());

    //Check if there is an else statement
    if(currentToken->type == ELSE){
        currentToken = scanner->nextToken(); //Consume ELSE statement
        ifNode->adopt(parseStatement());
    }

    return ifNode;
}

Node *Parser::parseCaseStatement(){
    // Current token should be CASE

    Node* caseNode = new Node(NodeType::CASE);
    currentToken = scanner->nextToken(); //Consume CASE

    //Get the expression to evaluates
    caseNode->adopt(parseExpression());

    if(currentToken->type != OF){
        syntaxError("Expected OF statement");
        return nullptr;
    }
    currentToken = scanner->nextToken(); //Consume OF


    while(currentToken->type != END){
        Node* branchNode = new Node(CASE_BRANCH);

        //Grab the numeric constants
        Node* caseConstants = new Node(CASE_CONSTANTS);
        while(currentToken->type != COLON){
            if(currentToken->type == INTEGER){
                Node* constant = new Node(INTEGER_CONSTANT);
                constant->lineNumber = currentToken->lineNumber;
                constant->value = Object(currentToken->value.L);

                //Add the current constant to the list
                caseConstants->adopt(constant);
            }
            currentToken = scanner->nextToken();
        }
        currentToken = scanner->nextToken(); //Consume colon

        //Add all the constants for the current branch to the branch
        branchNode->adopt(caseConstants);

        //Add the statement to execute
        branchNode->adopt(parseStatement());
        if(currentToken->type == SEMICOLON){
            currentToken = scanner->nextToken();
        }

        //Adopt the branch node as one of the branches of the case statement
        caseNode->adopt(branchNode);
    }

    //Current token should be END
    currentToken = scanner->nextToken();

    return caseNode;
}

Node *Parser::parseWriteStatement()
{
    // The current token should now be WRITE.

    // Create a WRITE node-> It adopts the variable or string node->
    Node *writeNode = new Node(NodeType::WRITE);
    currentToken = scanner->nextToken();  // consume WRITE

    parseWriteArguments(writeNode);
    if (writeNode->children.size() == 0)
    {
        syntaxError("Invalid WRITE statement");
    }

    return writeNode;
}

Node *Parser::parseWritelnStatement()
{
    // The current token should now be WRITELN.

    // Create a WRITELN node-> It adopts the variable or string node->
    Node *writelnNode = new Node(NodeType::WRITELN);
    currentToken = scanner->nextToken();  // consume WRITELN

    if (currentToken->type == LPAREN) parseWriteArguments(writelnNode);
    return writelnNode;
}

void Parser::parseWriteArguments(Node *node)
{
    // The current token should now be (

    bool hasArgument = false;

    if (currentToken->type == LPAREN)
    {
        currentToken = scanner->nextToken();  // consume (
    }
    else syntaxError("Missing left parenthesis");

    if (currentToken->type == IDENTIFIER)
    {
        node->adopt(parseVariable());
        hasArgument = true;
    }
    else if (currentToken->type == STRING)
    {
        node->adopt(parseStringConstant());
        hasArgument = true;
    }
    else syntaxError("Invalid WRITE or WRITELN statement");

    // Look for a field width and a count of decimal places.
    if (hasArgument)
    {
        if (currentToken->type == COLON)
        {
            currentToken = scanner->nextToken();  // consume ,

            if (currentToken->type == INTEGER)
            {
                // Field width
                node->adopt(parseIntegerConstant());

                if (currentToken->type == COLON)
                {
                    currentToken = scanner->nextToken();  // consume ,

                    if (currentToken->type == INTEGER)
                    {
                        // Count of decimal places
                        node->adopt(parseIntegerConstant());
                    }
                    else syntaxError("Invalid count of decimal places");
                }
            }
            else syntaxError("Invalid field width");
        }
    }

    if (currentToken->type == RPAREN)
    {
        currentToken = scanner->nextToken();  // consume )
    }
    else syntaxError("Missing right parenthesis");
}

Node *Parser::parseExpression()
{
    std::deque<Node *> expressionQueue;
    bool done = true;
    do {
        done = true;

        //Check if the expression is inverted via NOT
        if(currentToken->type == NOT){
            Node *invertedNode = new Node(NodeType::NOT);
            invertedNode->lineNumber=currentToken->lineNumber;
            currentToken = scanner->nextToken(); //Consume NOT

            expressionQueue.push_back(invertedNode);
            done = false;
            continue;
        }

        // The current token should now be an identifier or a number.

        // The expression's root node->
        Node *exprNode = parseSimpleExpression();

        // The current token might now be a relational operator.
        if (relationalOperators.find(currentToken->type) != relationalOperators.end()) {
            TokenType tokenType = currentToken->type;
            Node *opNode = tokenType == EQUALS ? new Node(EQ)
                : tokenType == LESS_THAN ? new Node(LT)
                : tokenType == GREATER_THAN ? new Node(GT)
                : tokenType == LESS_EQUALS ? new Node(LE)
                : tokenType == GREATER_EQUALS? new Node(GE)
                : tokenType == NOT_EQUALS ? new Node(NE)
                : nullptr;

            currentToken = scanner->nextToken();  // consume relational operator

            // The relational operator Node *adopts the first simple expression
            // Node *as its first child and the second simple expression node
            // as its second child. Then it becomes the expression's root node->
            if (opNode != nullptr) {
                opNode->adopt(exprNode);
                opNode->adopt(parseSimpleExpression());
                exprNode = opNode;
            }
        }

        if(!expressionQueue.empty() && expressionQueue.back()->type == NodeType::NOT) {
            expressionQueue.back()->adopt(exprNode);
        }
        else{
            expressionQueue.push_back(exprNode);
        }

        if(expressionQueue.size() == 3) {
            //There should be an expression and a boolean operator
            Node *leftChild = expressionQueue.front();
            expressionQueue.pop_front();

            Node *booleanNode = expressionQueue.front();
            expressionQueue.pop_front();

            Node * rightChild = expressionQueue.front();
            expressionQueue.pop_front();

            booleanNode->adopt(leftChild);
            booleanNode->adopt(rightChild);
            expressionQueue.push_back(booleanNode);
        }

        if(currentToken->type == AND){
            expressionQueue.push_back(new Node(NodeType::AND));
            currentToken = scanner->nextToken(); //Consume AND
            done = false;
            continue;
        }
        else if(currentToken->type == OR) {
            expressionQueue.push_back(new Node(NodeType::OR));
            currentToken = scanner->nextToken(); //Consume OR
            done = false;
            continue;
        }
    } while(!done);

    if(expressionQueue.size() != 1){
        //Some error occurred
        semanticError("Mismatched Boolean operations");
        return nullptr;
    }
    else{
        return expressionQueue.front();
    }
}

Node *Parser::parseSimpleExpression()
{
    // The current token should now be an identifier or a number.

    // The simple expression's root node->
    Node *simpExprNode = parseTerm();

    // Keep parsing more terms as long as the current token
    // is a + or - operator.
    while (simpleExpressionOperators.find(currentToken->type) !=
                                                simpleExpressionOperators.end())
    {
        Node *opNode = currentToken->type == PLUS ? new Node(ADD)
                                                : new Node(SUBTRACT);

        currentToken = scanner->nextToken();  // consume the operator

        // The add or subtract Node *adopts the first term Node *as its
        // first child and the next term Node *as its second child.
        // Then it becomes the simple expression's root node->
        opNode->adopt(simpExprNode);
        opNode->adopt(parseTerm());
        simpExprNode = opNode;
    }

    return simpExprNode;
}

Node *Parser::parseTerm()
{
    // The current token should now be an identifier or a number.

    // The term's root node->
    Node *termNode = parseFactor();

    // Keep parsing more factor as long as the current token
    // is a * or / operator.
    while (termOperators.find(currentToken->type) != termOperators.end())
    {
        Node *opNode = currentToken->type == STAR ? new Node(MULTIPLY)
                                                : currentToken->type == DIV ? new Node(NodeType::DIV)
                                                : new Node(DIVIDE);

        currentToken = scanner->nextToken();  // consume the operator

        // The multiply or dive Node *adopts the first factor Node *as its
        // as its first child and the next factor Node *as its second child.
        // Then it becomes the term's root node->
        opNode->adopt(termNode);
        opNode->adopt(parseFactor());
        termNode = opNode;
    }

    return termNode;
}

Node *Parser::parseFactor()
{
    // The current token should now be an identifier or a number or (

    if      (currentToken->type == IDENTIFIER) return parseVariable();
    else if (currentToken->type == INTEGER)    return parseIntegerConstant();
    else if (currentToken->type == REAL)       return parseRealConstant();

    else if (currentToken->type == LPAREN)
    {
        currentToken = scanner->nextToken();  // consume (
        Node *exprNode = parseExpression();

        if (currentToken->type == RPAREN)
        {
            currentToken = scanner->nextToken();  // consume )
        }
        else syntaxError("Expecting )");

        return exprNode;
    }

    else syntaxError("Unexpected token");
    return nullptr;
}

Node *Parser::parseVariable()
{
    // The current token should now be an identifier.

    string variableName = currentToken->text;
    SymtabEntry *variableId = symtab->lookup(toLowerCase(variableName));

    if (variableId == nullptr) semanticError("Undeclared identifier");

    Node *node = new Node(VARIABLE);
    node->text = variableName;

    currentToken = scanner->nextToken();  // consume the identifier
    return node;
}

Node *Parser::parseIntegerConstant()
{
    // The current token should now be a number.

    Node *integerNode = new Node(INTEGER_CONSTANT);
    integerNode->value = currentToken->value;

    currentToken = scanner->nextToken();  // consume the number
    return integerNode;
}

Node *Parser::parseRealConstant()
{
    // The current token should now be a number.

    Node *realNode = new Node(REAL_CONSTANT);
    realNode->value = currentToken->value;

    currentToken = scanner->nextToken();  // consume the number
    return realNode;
}

Node *Parser::parseStringConstant()
{
    // The current token should now be string.

    Node *stringNode = new Node(STRING_CONSTANT);
    stringNode->value = currentToken->value;

    currentToken = scanner->nextToken();  // consume the string
    return stringNode;
}

void Parser::syntaxError(string message)
{
    printf("SYNTAX ERROR at line %d: %s at '%s'\n",
           lineNumber, message.c_str(), currentToken->text.c_str());
    errorCount++;

    // Recover by skipping the rest of the statement.
    // Skip to a statement follower token.
    while (statementFollowers.find(currentToken->type) ==
                                                    statementFollowers.end())
    {
        currentToken = scanner->nextToken();
    }
}

void Parser::semanticError(string message)
{
    printf("SEMANTIC ERROR at line %d: %s at '%s'\n",
           lineNumber, message.c_str(), currentToken->text.c_str());
    errorCount++;
}

}  // namespace frontend
