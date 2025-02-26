%{
#include "token.h"
%}


DIGIT       [0-9]
LETTER      [a-zA-Z_]
ID          {LETTER}({LETTER}|{DIGIT})*
NUMBER      {DIGIT}+("."{DIGIT}+)?
IDENTIFIER (_|{LETTER})({DIGIT}|{LETTER}|_)*

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
"Int"       { return TOKEN_INT; }
"Float"     { return TOKEN_FLOAT; }
"String"    { return TOKEN_STRING; }
"Any"       { return TOKEN_ANY; }
"AND"       { return TOKEN_AND; }
"OR"        { return TOKEN_OR; }
"NOT"       { return TOKEN_NOT; }
"+"         { return TOKEN_PLUS; }
"-"         { return TOKEN_MINUS; }
"*"         { return TOKEN_MULTIPLY; }
"/"         { return TOKEN_DIVIDE; }
{NUMBER}    { return TOKEN_NUMBER; }


int yywrap() { return 1; }
%%