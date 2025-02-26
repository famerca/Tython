%{
#include "token.h"
%}

SPACE      [ \t\n]
DIGIT      [0-9]
LETTER     [A-Za-z]
IDENTIFIER (_|{LETTER})({DIGIT}|{LETTER}|_)*
TEXT       \"({DIGIT}|{LETTER}|{SPACE})*\"

%%
" "     { /* Ignore */ }
"\n"     { return TOKEN_LINEBREAK; }
"\t"         { return TOKEN_TAB; }
"="          { return TOKEN_ASSIGN; }
"if"          { return TOKEN_IF; }
"else"        { return TOKEN_ELSE; }
"for"         { return TOKEN_FOR; }
"while"       { return TOKEN_WHILE; }
"def"         { return TOKEN_FUNC_DEF; }
"return"      { return TOKEN_RETURN; }
"->"         { return TOKEN_ARROW; }
"=="         { return TOKEN_COMPARE; }
"!="         { return TOKEN_DIFFERENT; }
"<"          { return TOKEN_LESS; }
">"          { return TOKEN_GREATER; }
"<="         { return TOKEN_LESS_EQUAL; }
">="         { return TOKEN_GREATER_EQUAL; }
"("          { return TOKEN_LPAREN; }
")"          { return TOKEN_RPAREN; }
":"         { return TOKEN_BICOND; }
","          { return TOKEN_COMMA; }
{IDENTIFIER} { return TOKEN_IDENTIFIER; }
{TEXT}       { return TOKEN_STRING; }
%%

int yywrap() { return 1; }