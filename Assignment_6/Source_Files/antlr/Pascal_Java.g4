grammar Pascal_Java;

program           : programHeader block '.' ;
programHeader     : PROGRAM programIdentifier programParameters? ';' ;
programParameters : '(' IDENTIFIER ( ',' IDENTIFIER )* ')' ;

programIdentifier
    : IDENTIFIER ;

block         : declarations compoundStatement ;
declarations  : ( constantsPart ';' )? ( typesPart ';' )?
                ( variablesPart ';' )? ( routinesPart ';')? ;

constantsPart           : CONST constantDefinitionsList ;
constantDefinitionsList : constantDefinition ( ';' constantDefinition )* ;
constantDefinition      : constantIdentifier '=' constant ;

constantIdentifier
    : IDENTIFIER ;

constant
    : sign? ( IDENTIFIER | unsignedNumber )
    | characterConstant
    | stringConstant
    ;

sign : '-' | '+' ;

typesPart           : TYPE typeDefinitionsList ;
typeDefinitionsList : typeDefinition ( ';' typeDefinition )* ;
typeDefinition      : typeIdentifier '=' typeSpecification ;

typeIdentifier
    : IDENTIFIER ;

typeSpecification
    : simpleType        # simpleTypespec
    | arrayType         # arrayTypespec
    | recordType        # recordTypespec
    ;

simpleType
    : typeIdentifier    # typeIdentifierTypespec
    | enumerationType   # enumerationTypespec
    | subrangeType      # subrangeTypespec
    ;

enumerationType     : '(' enumerationConstant ( ',' enumerationConstant )* ')' ;
enumerationConstant : constantIdentifier ;
subrangeType        : constant '..' constant ;

arrayType
    : ARRAY '[' arrayDimensionList ']' OF typeSpecification ;
arrayDimensionList : simpleType ( ',' simpleType )* ;

recordType
    : RECORD recordFields ';'? END ;
recordFields : variableDeclarationsList ;

variablesPart            : VAR variableDeclarationsList ;
variableDeclarationsList : variableDeclarations ( ';' variableDeclarations )* ;
variableDeclarations     : variableIdentifierList ':' typeSpecification ;
variableIdentifierList   : variableIdentifier ( ',' variableIdentifier )* ;

variableIdentifier
    : IDENTIFIER ;

routinesPart      : routineDefinition ( ';' routineDefinition)* ;
routineDefinition : ( procedureHead | functionHead ) ';' block ;
procedureHead     : PROCEDURE routineIdentifier parameters? ;
functionHead      : FUNCTION  routineIdentifier parameters? ':' typeIdentifier ;

routineIdentifier
    : IDENTIFIER ;

parameters                : '(' parameterDeclarationsList ')' ;
parameterDeclarationsList : parameterDeclarations ( ';' parameterDeclarations )* ;
parameterDeclarations     : VAR? parameterIdentifierList ':' typeIdentifier ;
parameterIdentifierList   : parameterIdentifier ( ',' parameterIdentifier )* ;

parameterIdentifier
    : IDENTIFIER ;

statement : compoundStatement
          | assignmentStatement
          | ifStatement
          | caseStatement
          | repeatStatement
          | whileStatement
          | forStatement
          | writeStatement
          | writelnStatement
          | readStatement
          | readlnStatement
          | procedureCallStatement
          | emptyStatement
          ;

compoundStatement : BEGIN statementList END ;
emptyStatement : ;

statementList       : statement ( ';' statement )* ;
assignmentStatement : lhs ':=' rhs ;

lhs
    : variable ;
rhs : expression ;

ifStatement    : IF expression THEN trueStatement ( ELSE falseStatement )? ;
trueStatement  : statement ;
falseStatement : statement ;

caseStatement
    : CASE expression OF caseBranchList END ;

caseBranchList   : caseBranch ( ';' caseBranch )* ;
caseBranch       : caseConstantList ':' statement | ;
caseConstantList : caseConstant ( ',' caseConstant )* ;

caseConstant
    : constant ;

repeatStatement : REPEAT statementList UNTIL expression ;
whileStatement  : WHILE expression DO statement ;

forStatement : FOR variable ':=' expression
                    ( TO | DOWNTO ) expression DO statement ;

procedureCallStatement : procedureName '(' argumentList? ')' ;

procedureName
    : IDENTIFIER ;

argumentList : argument ( ',' argument )* ;
argument     : expression ;

writeStatement   : WRITE writeArguments ;
writelnStatement : WRITELN writeArguments? ;
writeArguments   : '(' writeArgument (',' writeArgument)* ')' ;
writeArgument    : expression (':' fieldWidth)? ;
fieldWidth       : sign? integerConstant (':' decimalPlaces)? ;
decimalPlaces    : integerConstant ;

readStatement   : READ readArguments ;
readlnStatement : READLN readArguments ;
readArguments   : '(' variable ( ',' variable )* ')' ;

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
    | NOT factor           # notFactor
    | '(' expression ')'   # parenthesizedFactor
    ;

variable
    : variableIdentifier modifier* ;

modifier  : '[' indexList ']' | '.' field ;
indexList : index ( ',' index )* ;
index     : expression ;

field
    : IDENTIFIER ;

functionCall : functionName '(' argumentList? ')' ;
functionName
    : IDENTIFIER ;

number          : sign? unsignedNumber ;
unsignedNumber  : integerConstant | realConstant ;
integerConstant : INTEGER ;
realConstant    : REAL;

characterConstant : CHARACTER ;
stringConstant    : STRING ;

relOp : '=' | '<>' | '<' | '<=' | '>' | '>=' ;
addOp : '+' | '-' | OR ;
mulOp : '*' | '/' | DIV | MOD | AND ;

fragment A : ('a' | 'A') ;
fragment B : ('b' | 'B') ;
fragment C : ('c' | 'C') ;
fragment D : ('d' | 'D') ;
fragment E : ('e' | 'E') ;
fragment F : ('f' | 'F') ;
fragment G : ('g' | 'G') ;
fragment H : ('h' | 'H') ;
fragment I : ('i' | 'I') ;
fragment J : ('j' | 'J') ;
fragment K : ('k' | 'K') ;
fragment L : ('l' | 'L') ;
fragment M : ('m' | 'M') ;
fragment N : ('n' | 'N') ;
fragment O : ('o' | 'O') ;
fragment P : ('p' | 'P') ;
fragment Q : ('q' | 'Q') ;
fragment R : ('r' | 'R') ;
fragment S : ('s' | 'S') ;
fragment T : ('t' | 'T') ;
fragment U : ('u' | 'U') ;
fragment V : ('v' | 'V') ;
fragment W : ('w' | 'W') ;
fragment X : ('x' | 'X') ;
fragment Y : ('y' | 'Y') ;
fragment Z : ('z' | 'Z') ;

PROGRAM   : P R O G R A M ;
CONST     : C O N S T ;
TYPE      : T Y P E ;
ARRAY     : A R R A Y ;
OF        : O F ;
RECORD    : R E C O R D ;
VAR       : V A R ;
BEGIN     : B E G I N ;
END       : E N D ;
DIV       : D I V ;
MOD       : M O D ;
AND       : A N D ;
OR        : O R ;
NOT       : N O T ;
IF        : I F ;
THEN      : T H E N ;
ELSE      : E L S E ;
CASE      : C A S E ;
REPEAT    : R E P E A T ;
UNTIL     : U N T I L ;
WHILE     : W H I L E ;
DO        : D O ;
FOR       : F O R ;
TO        : T O ;
DOWNTO    : D O W N T O ;
WRITE     : W R I T E ;
WRITELN   : W R I T E L N ;
READ      : R E A D ;
READLN    : R E A D L N ;
PROCEDURE : P R O C E D U R E ;
FUNCTION  : F U N C T I O N ;

IDENTIFIER : [a-zA-Z][a-zA-Z0-9]* ;
INTEGER    : [0-9]+ ;

REAL       : INTEGER '.' INTEGER
           | INTEGER ('e' | 'E') ('+' | '-')? INTEGER
           | INTEGER '.' INTEGER ('e' | 'E') ('+' | '-')? INTEGER
           ;

NEWLINE : '\r'? '\n' -> skip  ;
WS      : [ \t]+ -> skip ;

QUOTE     : '\'' ;
CHARACTER : QUOTE CHARACTER_CHAR QUOTE ;
STRING    : QUOTE STRING_CHAR* QUOTE ;

fragment CHARACTER_CHAR : ~('\'')   // any non-quote character
                        ;

fragment STRING_CHAR : QUOTE QUOTE  // two consecutive quotes
                     | ~('\'')      // any non-quote character
                     ;

COMMENT : '{' COMMENT_CHARACTER* '}' -> skip ;

fragment COMMENT_CHARACTER : ~('}') ;
