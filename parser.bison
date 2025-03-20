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
%token TOKEN_PLUS TOKEN_MINUS TOKEN_MULTIPLY
%token TOKEN_DIVIDE TOKEN_NUMBER TOKEN_COLON TOKEN_TYPE

// Precedence and associativity
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE
%right TOKEN_ASSIGN

%%

program:
    | program statement
    ;

statement:
      expression TOKEN_LINEBREAK
    | TOKEN_IF expression TOKEN_LINEBREAK statement
    | TOKEN_IF expression TOKEN_LINEBREAK statement TOKEN_ELSE TOKEN_LINEBREAK statement
    | TOKEN_FOR expression TOKEN_LINEBREAK statement
    | TOKEN_WHILE expression TOKEN_LINEBREAK statement
    | TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_ARROW expression TOKEN_LINEBREAK
    | TOKEN_RETURN expression TOKEN_LINEBREAK
    ;

expression:
      TOKEN_NUMBER
    | TOKEN_STRING
    | TOKEN_IDENTIFIER
    | TOKEN_IDENTIFIER TOKEN_ASSIGN expression
    | expression TOKEN_PLUS expression
    | expression TOKEN_MINUS expression
    | expression TOKEN_MULTIPLY expression
    | expression TOKEN_DIVIDE expression
    | expression TOKEN_COMPARE expression
    | expression TOKEN_DIFFERENT expression
    | expression TOKEN_LESS expression
    | expression TOKEN_GREATER expression
    | expression TOKEN_LESS_EQUAL expression
    | expression TOKEN_GREATER_EQUAL expression
    | TOKEN_LPAREN expression TOKEN_RPAREN
    | TOKEN_NOT expression
    | expression TOKEN_AND expression
    | expression TOKEN_OR expression
    ;

parameters:
    | parameter
    | parameters TOKEN_COMMA parameter
    ;

parameter:
      TOKEN_IDENTIFIER
    | TOKEN_TYPE TOKEN_IDENTIFIER
    ;

%%

int yyerror(const char* s)
{
    printf("Parse error: %s\n", s);
    return 1;
}
