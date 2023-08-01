parser grammar MxParser;

options {
    tokenVocab = MxLexer;
}

program: (functionDef | classDef | varDefStmt)* EOF;

classDef: Class Identifier '{' classSuite* '}' ';';
classSuite
    :varDefStmt
    |constructDef
    |functionDef
    ;

constructDef: Identifier '(' ')' block;
functionDef: typeName Identifier '(' parameters? ')' block;
parameters: varDef (',' varDef)*;

varDef: typeName Identifier;
varDefInit: Identifier ('=' expression)?;

suite: block | stmt;
block: '{' stmt* '}';

stmt
    : exprStmt
    | ifStmt
    | whileStmt
    | forStmt
    | flowStmt
    | varDefStmt
    | block
    ;

exprStmt: exprList? ';';
exprList: expression (',' expression)*;

ifStmt
    : If '(' expression ')' suite 
     (ElseIf '(' expression ')' suite)*
     (Else suite)?
    ;

whileStmt: While '(' expression ')' suite;
forStmt: For '(' (exprStmt | varDefStmt)? expression? ';' expression? ')' suite;
flowStmt: (Continue | Break | (Return expression?)) ';';

expression
    : '(' expression ')'                                               # ParentheseExpr
    | expression '(' exprList? ')'                                     # FunctionExpr
    | expression '[' expression ']'                                    # ArrayExpr
    | expression '.' expression                                        # MemberExpr
    | expression      op = ('++' | '--')                               # RightSingleExpr
    | <assoc = right> op = ('++' | '--')       expression              # LeftSingleExpr
    | <assoc = right> op = ('!' | '~' | '-')   expression              # LeftSingleExpr
    | New newTypeName ('(' ')')?                                       # NewExpr
    | lhs = expression op = ('*' | '/' | '%')         rhs = expression # BinaryExpr
    | lhs = expression op = ('+' | '-')               rhs = expression # BinaryExpr
    | lhs = expression op = ('>>' | '<<')             rhs = expression # BinaryExpr
    | lhs = expression op = ('>=' | '<=' | '<' | '>') rhs = expression # BinaryExpr
    | lhs = expression op = ('!=' | '==')             rhs = expression # BinaryExpr
    | lhs = expression op = '&'                       rhs = expression # BinaryExpr
    | lhs = expression op = '^'                       rhs = expression # BinaryExpr
    | lhs = expression op = '|'                       rhs = expression # BinaryExpr
    | lhs = expression op = '&&'                      rhs = expression # BinaryExpr
    | lhs = expression op = '||'                      rhs = expression # BinaryExpr
    | <assoc = right> expression '?' expression ':' expression         # TernaryExpr
    | <assoc = right> expression '=' expression                        # AssignExpr
    | literalExpr                                                      # LiterExpr
    | (Identifier | This)                                              # AtomExpr
    ;

varDefStmt: typeName (varDefInit ',')* varDefInit ';';

typeName
    : basicType        # Basic
    | Identifier       # Class
    | typeName '[' ']' # Array
    ;

newTypeName
    : Identifier                                                     # NewClass
    | Identifier newArrayExpr+ newArrayEmpty* (fail = newArrayExpr)* # NewClassArray
    | basicType newArrayExpr+ newArrayEmpty* (fail = newArrayExpr)*  # NewBasicArray
    ;

newArrayExpr: '[' expression ']';
newArrayEmpty: '[' ']';

literalExpr
    : NumberLiteral
    | StringLiteral
    | NullLiteral
    | LogicalLiteral
    ;

basicType
    : Bool
    | Int
    | String
    | Void
    ;
