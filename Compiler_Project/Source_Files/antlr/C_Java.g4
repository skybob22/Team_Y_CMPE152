grammar C_Java;

//====Starting point====//
program : (functionDefinition | functionDeclaration | c_statement)+ ;

//====General Statements====//
c_statement
    : statement ';'
    | emptyStatement ';'
    ;

statement
    : assignmentStatement
    | variableDeclaration
    | controlStatement
    | printStatement
    | printLnStatement
    | readStatement
    | readlnStatement
    | functionCall
    | returnStatement
    ;

emptyStatement : ;

//====Declarations====//
variableDeclaration
    : typeIdentifier variableIdentifier (',' variableIdentifier)*
    | typeIdentifier variableIdentifier ('[' length ']')*
    ;
length : INTEGER ;

//====Variable assignment====//
assignmentStatement
    : lhs '=' rhs   #assignVariable
    | variable '++' #decrementVariable
    | variable '--' #irncrementVariable
    ;

lhs
    : variable
    | variableDeclaration
    ;

rhs : expression ;

//====Program flow/control statements====//
controlScope : '{' (c_statement | controlStatement)* '}' ;

controlStatement
    : doWhileLoop
    | whileLoop
    | forLoop
    | ifStatement
    | controlScope
    ;

doWhileLoop : DO controlScope WHILE '(' expression ')';
whileLoop : WHILE '(' expression ')' controlScope ;
forLoop : FOR '(' statement? ';' expression ';' statement? ')' controlScope ;
ifStatement
    : IF '(' expression ')' controlScope
      (ELSE IF '(' expression ')' controlScope)*
      (ELSE controlScope)?
    ;

//====Function declarations/definitions/calls====//
functionDefinition : functionDeclaration controlScope ;
functionDeclaration : typeIdentifier functionIdentifier '(' (parameterDeclarationsList | VOID)? ')' ;

functionIdentifier
   : IDENTIFIER ;
parameterDeclarationsList : parameterDeclaration ( ',' parameterDeclaration )* ;
parameterDeclaration     : typeIdentifier ARRAYINDICATOR* parameterIdentifier;
parameterIdentifier
   : IDENTIFIER ;

returnStatement
    : RETURN expression?;

functionCall : functionName '(' argumentList? ')' ;
functionName
    : IDENTIFIER ;
argumentList : argument ( ',' argument )* ;
argument     : expression ;


//These are not actually in C, but we included them since we can't
//Use #include to use stdio.h
//====Printouts (So we can see what's going on)====//
printStatement: PRINT '(' printList* ')' ;
printLnStatement: PRINTLN '(' printList* ')' ;
printList : printItem (',' printItem)* ;
printItem : variable | stringConstant ;
//====Readin (So we can get input)====//
readStatement : READ '(' readArguments ')' ;
readlnStatement : READLN '(' readArguments ')' ;
readArguments : variable ( ',' variable )* ;

//====Expressions,factors, etc.====//
expression
    : simpleExpression (relOp simpleExpression)? ;

simpleExpression
    : sign? term (addOp term)* ;

term
    : factor (mulOp factor)* ;

factor
    : variable             # variableFactor
    | number               # numberFactor
    | characterConstant    # characterFactor
    | stringConstant       # stringFactor
    | functionCall         # functionCallFactor
    | '!' factor           # notFactor
    | '(' expression ')'   # parenthesizedFactor
    ;

//====Variables====//
variable
    : variableIdentifier modifier* ;
modifier : '[' index ']';
index : expression ;
variableIdentifier
    : IDENTIFIER ;

number          : sign? unsignedNumber ;
unsignedNumber  : integerConstant | realConstant ;
sign : '-' ;
integerConstant : INTEGER ;
realConstant    : REAL;


//====Operators====//
relOp : '==' | '!=' | '<' | '<=' | '>' | '>=' ;
addOp : '+' | '-' | '||' ;
mulOp : '*' | '/' | '&&' ;

//====Built-in Types====//
typeIdentifier
    : INT |
      BOOL |
      FLOAT |
      VOID ;


characterConstant : CHARACTER ;
stringConstant    : STRING ;

//====Lexor Fragments/Word Recognition====//
fragment A : 'a' ;
fragment B : 'b' ;
fragment C : 'c' ;
fragment D : 'd' ;
fragment E : 'e' ;
fragment F : 'f' ;
fragment G : 'g' ;
fragment H : 'h' ;
fragment I : 'i' ;
fragment J : 'j' ;
fragment K : 'k' ;
fragment L : 'l' ;
fragment M : 'm' ;
fragment N : 'n' ;
fragment O : 'o' ;
fragment P : 'p' ;
fragment Q : 'q' ;
fragment R : 'r' ;
fragment S : 's' ;
fragment T : 't' ;
fragment U : 'u' ;
fragment V : 'v' ;
fragment W : 'w' ;
fragment X : 'x' ;
fragment Y : 'y' ;
fragment Z : 'z' ;

INT    : I N T ;
BOOL   : B O O L ;
FLOAT  : F L O A T ;
VOID   : V O I D ;

DO        : D O ;
WHILE     : W H I L E ;
FOR       : F O R ;
IF        : I F ;
ELSEIF    : E L S E I F ;
ELSE      : E L S E ;
SWITCH    : S W I T C H ;
PRINT     : P R I N T ;
PRINTLN   : P R I N T L N ;
READ      : R E A D ;
READLN    : R E A D L N ;
RETURN    : R E T U R N ;

ARRAYINDICATOR : '[]' ;
SINGLEQUOTE  : '\'' ;
DOUBLEQUOTE  : '"' ;
DOUBLESLASH  : '//' ;

IDENTIFIER : [a-zA-Z][a-zA-Z0-9_]* ;
INTEGER    : [0-9]+ ;

REAL       : INTEGER '.' INTEGER
           | INTEGER ('e' | 'E') ('+' | '-')? INTEGER
           | INTEGER '.' INTEGER ('e' | 'E') ('+' | '-')? INTEGER
           ;

CHARACTER : SINGLEQUOTE CHARACTER_CHAR SINGLEQUOTE;
STRING : DOUBLEQUOTE STRING_CHAR* DOUBLEQUOTE;

fragment CHARACTER_CHAR : ~('\'');
fragment STRING_CHAR
    : DOUBLEQUOTE DOUBLEQUOTE
    | ~('"')
    ;

NEWLINE : '\r'? '\n' -> skip ;
WS      : [ \t]+ -> skip ;

COMMENT : DOUBLESLASH ~[\r\n]* -> skip ;
