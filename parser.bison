%code requires {
    #include "ast.hpp"
    #include <string>
}

%union {

    Ast* astNode;
    
}

%{
#include <stdio.h>
#include "ast.hpp"
#define YYDEBUG 1

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

%left TOKEN_IF TOKEN_ELSE TOKEN_WHILE TOKEN_FOR TOKEN_FUNC_DEF TOKEN_RETURN TOKEN_COLON TOKEN_LINEBREAK
%left TOKEN_OR
%left TOKEN_AND
%right TOKEN_NOT

%nonassoc TOKEN_COMPARE TOKEN_DIFFERENT TOKEN_GREATER TOKEN_LESS TOKEN_LESS_EQUAL TOKEN_GREATER_EQUAL

%right TOKEN_ASSIGN

%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE

%left TOKEN_LPAREN TOKEN_RPAREN TOKEN_COMMA

%nonassoc UMINUS

%type<astNode> program statement_list statement block expression declaration assignment definition parameters parameter arguments function_call
%type<astNode> stmt_if term stmt_else stmt_for stmt_while
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
    ;

// Bloque de código (indentación)
block: 
    TOKEN_INDENT statement_list TOKEN_DEDENT{
        $$ = new Ast("Block");
        $$->addChild($2);
    }
    |  TOKEN_INDENT statement_list TOKEN_DEDENT TOKEN_LINEBREAK{
        $$ = $2;
    }
    ;

// Lista de statements
statement_list: 
    statement{
        $$ = new Ast("Statements");
        $$->addChild($1);
    }
    | statement_list TOKEN_LINEBREAK statement{
        $1->addChild($3);
        $$ = $1;
    }
    | statement_list TOKEN_LINEBREAK{
        $$ = $1; 
    }
    ;

/* control:
      TOKEN_IF expression TOKEN_COLON
    | TOKEN_ELSE TOKEN_COLON
    | TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN expression TOKEN_COLON
    | TOKEN_WHILE expression TOKEN_COLON
    ; */

statement:
    stmt_if {
        $$ = $1;
    }
    | stmt_for {
        $$ = $1;
    }
    | stmt_while {
        $$ = $1;
    }
    | declaration {
        $$ = $1;
    }
    | assignment{
        $$ = $1;
    }
    | definition{
        $$ = $1;
    }
    |  TOKEN_RETURN expression
    |  TOKEN_BREAK
    |  TOKEN_RETURN
    |  expression
    ;

stmt_if:
    TOKEN_IF expression TOKEN_COLON block stmt_else { 
        $$ = new Statement($5 ? "If Else" : "If");
        $$->addChild($2);
        $$->addChild($4);
        if ($5) $$->addChild($5);
    };

stmt_else:
    TOKEN_ELSE TOKEN_COLON block { $$ = $3; }
    | %empty { $$ = nullptr; };

stmt_for:
    TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN expression TOKEN_COLON block{
        $$ = new Ast("For ");
        $$->addChild($4);
        $$->addChild($6);
    }

stmt_while:
    TOKEN_WHILE expression TOKEN_COLON block{
        $$ = new Ast("While");
        $$->addChild($2);
        $$->addChild($4);
    }

declaration:
    TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE TOKEN_ASSIGN expression{
        $$ = new Declaration("", "");
        $$->addChild($5);
    }
    | TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE{
        $$ = new Declaration("", "");
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGN expression{
        $$ = new Ast("Statement Assignment");
    }
    ;

definition:
    TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_COLON block{
        $$ = new Ast("Function Definition");
        $$->addChild($4);
        $$->addChild($7);
    }
    | TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_ARROW TOKEN_TYPE TOKEN_COLON block{
        $$ = new Ast("Function Definition Typed");
        $$->addChild($4);
        $$->addChild($9);
    }
    ;

parameters:
    parameters TOKEN_COMMA parameter
    {
        $1->addChild($3);
        $$ = $1;
    }
    | parameter{
        $$ = new Ast("Parameters");
        $$->addChild($1);
    }
    ;

parameter:
      TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE{
        $$ = new Ast("Parameter Typed");
      }
    | TOKEN_IDENTIFIER{
        $$ = new Ast("Parameter");
    }
    ;

arguments:
    arguments TOKEN_COMMA expression
    {
        $1->addChild($3);
        $$ = $1;
    }
    | expression{
        $$ = new Ast("Arguments");
        $$->addChild($1);
    }
    ;

function_call:
    TOKEN_IDENTIFIER TOKEN_LPAREN arguments TOKEN_RPAREN {
        $$ = new Ast("Function Call");
        $$->addChild($3);
    }
    ;

expression:
    TOKEN_LPAREN expression TOKEN_RPAREN {
        $$ = $2;
    }
    | expression TOKEN_COMPARE expression{
        $$ = new Ast("Compare");
    }
    | expression TOKEN_DIFFERENT expression{
        $$ = new Ast("Different");
    }
    | expression TOKEN_LESS expression{
        $$ = new Ast("Less");
    }
    | expression TOKEN_LESS_EQUAL expression{
        $$ = new Ast("LessEqual");
    }
    | expression TOKEN_GREATER expression{
        $$ = new Ast("Greater");
    }
    | expression TOKEN_GREATER_EQUAL expression{
        $$ = new Ast("GreaterEqual");
    }
    | expression TOKEN_AND expression{
         $$ = new Ast("And");
    }
    |  expression TOKEN_OR expression{
          $$ = new Ast("Or");
    }
    | expression TOKEN_PLUS expression{
        $$ = new Ast("Plus");
    }
    | expression TOKEN_MINUS expression{
        $$ = new Ast("Minus");
    }
    | expression TOKEN_MULTIPLY expression{
        $$ = new Ast("Multiply");
    }
    | expression TOKEN_DIVIDE expression{
        $$ = new Ast("Divide");
    }
    | TOKEN_NOT expression {
        $$ = new Expression("", "");
    }
    | TOKEN_MINUS expression %prec UMINUS {
        $$ = new Expression("", "");
    }
    | function_call {
        $$ = $1;
    }
    | term {
        $$ = $1;
    }
    ;

term :
    TOKEN_NUMBER {
        $$ = new Ast("Number");
    }
    | TOKEN_STRING {
        $$ = new Ast("String");
    }
    | TOKEN_IDENTIFIER {
        $$ = new Ast("Identifier");
    }
    ;

%%



int yyerror(const char* s)
{
    printf("Parse error: %s\n", s);
    return 1;
}
