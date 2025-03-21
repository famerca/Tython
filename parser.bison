%{
#include <stdio.h>

extern int yylex();
int yyerror(const char*);
%}

// Token declarations
%token TOKEN_STRING TOKEN_NOT TOKEN_AND TOKEN_OR TOKEN_TAB TOKEN_BICOND
%token TOKEN_ASSIGN TOKEN_IDENTIFIER TOKEN_LPAREN TOKEN_RPAREN TOKEN_ARROW
%token TOKEN_COMPARE TOKEN_DIFFERENT TOKEN_IF TOKEN_ELSE TOKEN_FOR
%token TOKEN_WHILE TOKEN_FUNC_DEF TOKEN_RETURN TOKEN_GREATER TOKEN_LESS
%token TOKEN_LESS_EQUAL TOKEN_GREATER_EQUAL TOKEN_COMMA TOKEN_LINEBREAK
%token TOKEN_PLUS TOKEN_MINUS TOKEN_MULTIPLY TOKEN_INDENT TOKEN_DEDENT
%token TOKEN_DIVIDE TOKEN_NUMBER TOKEN_COLON TOKEN_TYPE

%%

// Regla principal
program: 
    program control block
    | block
    ;

// Bloque de código (indentación)
block: 
      statement_list
    | TOKEN_INDENT statement_list TOKEN_DEDENT
    ;

// Lista de statements
statement_list: 
    statement_list TOKEN_LINEBREAK statement
    | statement_list TOKEN_LINEBREAK
    | statement
    ;

control:
    TOKEN_IF expression TOKEN_COLON
    | TOKEN_ELSE TOKEN_COLON
    | TOKEN_FOR expression TOKEN_COLON
    | TOKEN_WHILE expression TOKEN_COLON
    ;

parameters:
    parameters TOKEN_COMMA parameter
    | parameter
    ;

parameter:
      TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE
    | TOKEN_IDENTIFIER
    ;

statement:
       TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE TOKEN_ASSIGN expression
    |  TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE
    |  TOKEN_IDENTIFIER TOKEN_ASSIGN expression
    |  TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_COLON block
    |  TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_ARROW TOKEN_TYPE TOKEN_COLON block
    |  expression
    ;

expression:
      TOKEN_NUMBER
    | TOKEN_STRING
    | TOKEN_IDENTIFIER
    | expression operator expression
    | TOKEN_IDENTIFIER TOKEN_LPAREN expression TOKEN_RPAREN
    | TOKEN_NOT expression
    | TOKEN_LPAREN expression TOKEN_RPAREN
    ;

operator:
    TOKEN_COMPARE
    | TOKEN_DIFFERENT
    | TOKEN_LESS
    | TOKEN_GREATER
    | TOKEN_LESS_EQUAL
    | TOKEN_GREATER_EQUAL
    | TOKEN_AND
    | TOKEN_OR
    | TOKEN_PLUS
    | TOKEN_MINUS
    | TOKEN_MULTIPLY
    | TOKEN_DIVIDE
    ;

%%

int yyerror(const char* s)
{
    printf("Parse error: %s\n", s);
    return 1;
}
