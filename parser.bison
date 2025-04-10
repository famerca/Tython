%code requires {
    #include "ast.hpp"
    #include <string>
}

%union {

    Ast* astNode;
    std::string* str;
}

%{
#include <stdio.h>
#include <string>
#include <algorithm>
#include "ast.hpp"

//#define YYDEBUG 1

extern int yylex();

void yyerror(const char*);

extern int yylineno; 

Ast* ast = NULL;

std::string reemplazarComillas(const std::string& texto) {
    std::string resultado = texto;
    std::replace(resultado.begin(), resultado.end(), '\"', '\'');
    return resultado;
}


%}

%locations
%define parse.error verbose

// Token declarations
%token TOKEN_STRING TOKEN_NOT TOKEN_AND TOKEN_OR TOKEN_BREAK TOKEN_IN
%token TOKEN_ASSIGN TOKEN_IDENTIFIER TOKEN_LPAREN TOKEN_RPAREN TOKEN_ARROW
%token TOKEN_COMPARE TOKEN_DIFFERENT TOKEN_IF TOKEN_ELSE TOKEN_FOR
%token TOKEN_WHILE TOKEN_FUNC_DEF TOKEN_RETURN TOKEN_GREATER TOKEN_LESS
%token TOKEN_LESS_EQUAL TOKEN_GREATER_EQUAL TOKEN_COMMA TOKEN_LINEBREAK
%token TOKEN_PLUS TOKEN_MINUS TOKEN_MULTIPLY TOKEN_INDENT TOKEN_DEDENT
%token TOKEN_DIVIDE TOKEN_NUMBER TOKEN_COLON TOKEN_TYPE

%left TOKEN_WHILE TOKEN_FOR TOKEN_FUNC_DEF TOKEN_RETURN TOKEN_COLON TOKEN_LINEBREAK  TOKEN_IF

%left TOKEN_OR
%left TOKEN_AND
%right TOKEN_NOT

%nonassoc TOKEN_COMPARE TOKEN_DIFFERENT TOKEN_GREATER TOKEN_LESS TOKEN_LESS_EQUAL TOKEN_GREATER_EQUAL

// Precedencia para resolver if-else
%nonassoc LOWER_THAN_ELSE
%nonassoc TOKEN_ELSE

%right TOKEN_ASSIGN

%left TOKEN_PLUS TOKEN_MINUS
%left TOKEN_MULTIPLY TOKEN_DIVIDE

%left TOKEN_LPAREN TOKEN_RPAREN TOKEN_COMMA

%nonassoc UMINUS

%type<astNode> program statement_list statement block expression declaration assignment definition parameters parameter arguments function_call
%type<astNode> stmt_if term stmt_for stmt_while
%type<str> TOKEN_STRING TOKEN_IDENTIFIER TOKEN_TYPE TOKEN_NUMBER
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

    }|
    TOKEN_LINEBREAK statement_list {
        $$ = new Ast("Root");
        $$->addChild($2);
    }
    ;

// Bloque de código (indentación)
block: 
    TOKEN_COLON TOKEN_INDENT statement_list TOKEN_DEDENT {
        $$ = new Ast("Block");
        $$->addChild($3);
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
    |  TOKEN_RETURN expression {
        $$ = new Ast("return");
        $$->addChild($2);
    }
    |  TOKEN_BREAK {
        $$ = new Ast("break");
    }
    |  TOKEN_RETURN
    {
        $$ = new Ast("return");
    }
    |  expression {
        $$ = $1;
    }
    ;

stmt_if:
    TOKEN_IF expression block %prec LOWER_THAN_ELSE{
        $$ = new Statement("If");
        $$->addChild($2);
        $$->addChild($3);
    }
    | TOKEN_IF expression block TOKEN_ELSE block{
        $$ = new Statement("If Else");
        $$->addChild($2);
        $$->addChild($3);
        $$->addChild($5);
    }
;

stmt_for:
    TOKEN_FOR TOKEN_IDENTIFIER TOKEN_IN expression  block{
        $$ = new Ast("For ");
        $$->addChild($4);
        $$->addChild($5);
    }

stmt_while:
    TOKEN_WHILE expression block{
        $$ = new Ast("While");
        $$->addChild($2);
        $$->addChild($3);
    }

declaration:
    TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE TOKEN_ASSIGN expression{
        $$ = new Ast("Declaration : " + *$3 );
        $$->addChild($5);
    }
    | TOKEN_IDENTIFIER TOKEN_COLON TOKEN_TYPE{
        $$ = new Ast("Declaration : " + *$3 );
    }
    ;

assignment:
    TOKEN_IDENTIFIER TOKEN_ASSIGN expression{
        $$ = new Ast("Statement Assignment");
    }
    ;

definition:
    TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN  block{
        $$ = new Ast("Function Definition");
        $$->addChild($4);
        $$->addChild($6);
    }
    | TOKEN_FUNC_DEF TOKEN_IDENTIFIER TOKEN_LPAREN parameters TOKEN_RPAREN TOKEN_ARROW TOKEN_TYPE  block{
        $$ = new Ast("Function --> " +  *$7);
        $$->addChild($4);
        $$->addChild($8);
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
        $$ = new Ast("Parameter : " + *$3);
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
        $$ = new Compare(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_DIFFERENT expression{
        $$ = new Diff(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_LESS expression{
        $$ = new Less(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_LESS_EQUAL expression{
        $$ = new LessE(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_GREATER expression{
        $$ = new Greater(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_GREATER_EQUAL expression{
        $$ = new GreaterE(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_AND expression{
        $$ = new And(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    |  expression TOKEN_OR expression{
        $$ = new Or(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_PLUS expression{
        $$ = new Sum(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_MINUS expression{
        $$ = new Sub(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_MULTIPLY expression{
        $$ = new Mul(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | expression TOKEN_DIVIDE expression{
        $$ = new Div(@1.first_line);
        $$->addChild($1);
        $$->addChild($3);
        $$->validate();
    }
    | TOKEN_NOT expression {
        $$ = new Or(@1.first_line);
        $$->addChild($2);
        $$->validate();
    }
    | TOKEN_MINUS expression %prec UMINUS {
        $$ = new Uminus(@1.first_line);
        $$->addChild($2);
        $$->validate();
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
        $$ = new Number(*$1);
    }
    | TOKEN_STRING {
        $$ = new String(*$1);
    }
    | TOKEN_IDENTIFIER {
        $$ = new Identifier(*$1);
    }
    ;

%%



void yyerror(const char* s)
{
    fprintf(stderr, "Line %d: %s\n", yylineno, s);

}
