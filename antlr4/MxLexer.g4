lexer grammar MxLexer;

// comments
Comment: (BlockComment | LineComment) -> skip;
BlockComment: ('/*' .*? '*/') -> skip;
LineComment: ('//' .*? (NewLine | EOF)) -> skip;

// standard operators
Add: '+';
Sub: '-';
Mul: '*';
Div: '/';
Mod: '%';

// relational operators
Gt: '>';
Lt: '<';
Geq: '>=';
Leq: '<=';
Neq: '!=';
Eq: '==';

// logical operators
And: '&&';
Or: '||';
Not: '!';

// bitwise operators
Rs: '>>';
Ls: '<<';
BitAnd: '&';
BitOr: '|';
BitXor: '^';
BitInv: '~';

// assign operator
Assign: '=';

// Self-Increasing and Self-Decreasing operators
Incre: '++';
Decre: '--';

// component operator
Dot: '.';

// ternary operator
Ques: '?';
Colon: ':';

LeftBracket: '[';
RightBracket: ']';
LeftParen: '(';
RightParen: ')';
LeftBrace: '{';
RightBrace: '}';
Semicolon: ';';
Comma: ',';

// literals
fragment EscapeChar: '\\\\' | '\\n' | '\\t' | '\\"';
LogicalLiteral: True | False;
NumberLiteral: [1-9]Digit* | '0';
StringLiteral: '"' (EscapeChar | .)*? '"';
NullLiteral: Null;

// keywords
Void: 'void';
Bool: 'bool';
Int: 'int';
String: 'string';
New: 'new';
Class: 'class';
Null: 'null';
True: 'true';
False: 'false';
This: 'this';
ElseIf: Else Whitespace If;
If: 'if';
Else: 'else';
For: 'for';
While: 'while';
Break: 'break';
Continue: 'continue';
Return: 'return';

fragment Digit: [0-9];
fragment Letter: [A-Za-z];
Identifier: Letter(Letter | Digit | '_')*;

// white space
Whitespace: (' ' | '\t' | '\u000B' | '\u000C' | '\u00A0' | NewLine) -> skip; 
NewLine: ('\r' | '\n' | '\u2028' | '\u2029') -> skip;