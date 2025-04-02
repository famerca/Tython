%code requires {
    #include "ast.hpp"
}

%union {

    Ast* astNode;
}

%{
#include <stdio.h>
#include "ast.hpp"
#define YYDEBUG 0

extern int yylex();
int yyerror(const char*);

Ast* ast = NULL;


%}

// Token declarations
%token TOKEN_STRING TOKEN_NOT TOKEN_AND TOKEN_OR TOKEN_BREAK TOKEN_IN
%token TOKEN_ASSIGN TOKEN_IDENTIFIER TOKEN_LPAREN TOKEN_RPAREN TOKEN_ARROW
%token TOKEN_COMPARE TOKEN_DIFFERENT TOKEN_IF TOKEN_ELSE TOKEN_FOR
%token TOKEN_WHILE TOKEN_FUNC_DEF TOKEN_RETURN TOKEN_GREATER TOKEN_LESS
%token TOKEN_LESS_EQUAL TOKEN_GREATER_EQUAL TOKEN_COMMA TOKEN_LINEBREAK
%token TOKEN_PLUS TOKEN_MINUS TOKEN_MULTIPLY TOKEN_INDENT TOKEN_DEDENT
%token TOKEN_DIVIDE TOKEN_NUMBER TOKEN_COLON TOKEN_TYPE


%nonassoc TOKEN_ASSIGN
%nonassoc TOKEN_GREATER TOKEN_LESS TOKEN_LESS_EQUAL TOKEN_GREATER_EQUAL TOKEN_COMPARE
%left TOKEN_AND TOKEN_OR
%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE
//%nonassoc UMINUS

%type<astNode> program statement_list statement control block linebreaks

%%

// Regla principal
start:
    program {
        ast = $1;
        YYACCEPT;
    }


program: 
    statement_list {
        $$ = new Ast("Root");
        $$->addChild($1);

    }
    | statement_list linebreaks {
        $$ = new Ast("Root");
        $$->addChild($1);
    }
    ;

// Bloque de código (indentación)
block: 
    TOKEN_INDENT statement_list TOKEN_DEDENT{
        $$ = new Ast("Block");
        $$->addChild($2);
    }
    
    ;

linebreaks:
    TOKEN_LINEBREAK linebreaks  // Uno o más saltos de línea
    | /* vacío */               // Ningún salto de línea
    ;

// Lista de statements
statement_list: 
    statement_list linebreaks statement {
        $1->addChild($3);
        $$ = $1;
    }
    | statement_list linebreaks control block{
        $1->addChild($4);
        $$ = $1;
    }
    | linebreaks statement_list {
        $$ = $2;
    }
    | statement {
        $$ = new Ast("Statements");
        $$->addChild($1);
    }
    | control block {
        $$ = $2;
    }
    ;

control:
      TOKEN_IF expression TOKEN_COLON
    | TOKEN_ELSE TOKEN_COLON
    | TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN expression TOKEN_COLON
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

arguments:
    arguments TOKEN_COMMA expression
    | expression
    ;

statement:
       TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE TOKEN_ASSIGN expression{
           $$ = new Ast("Statement Definition");
       }
    |  TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE{
        $$ = new Ast("Statement Definition");
    }
    |  TOKEN_IDENTIFIER TOKEN_ASSIGN expression{
        $$ = new Ast("Statement Assignment");
    }
    |  TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_COLON block
    {
        $$ = new Ast("Function Definition");
    }
    |  TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_ARROW TOKEN_TYPE TOKEN_COLON block{
        $$ = new Ast("Function Definition");
    }
    |  TOKEN_RETURN expression
    |  TOKEN_BREAK
    |  TOKEN_RETURN
    |  expression
    ;

expression:
      TOKEN_NUMBER
    | TOKEN_STRING
    | TOKEN_IDENTIFIER
    | expression operator expression
    | TOKEN_IDENTIFIER TOKEN_LPAREN arguments TOKEN_RPAREN
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
