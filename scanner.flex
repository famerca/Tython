%{
#include "token.h"

int current_indent = 0;  // Nivel de indentación actual
int new_indent = 0;      // Nivel de indentación en la nueva línea

%}

SPACE      [ \t\n]
DIGIT      [0-9]
LETTER     [A-Za-z]
IDENTIFIER (_|{LETTER})({DIGIT}|{LETTER}|_)*
TEXT       \"({DIGIT}|{LETTER}|{SPACE})*\"
NUMBER      {DIGIT}+("."{DIGIT}+)?
TYPE        Int|Float|String|Any

%%

\n("    ")+ {
    new_indent = (yyleng - 1) / 4;  // Restamos 1 para ignorar el \n
    printf("leng: %d, new_indent: %d, current_indent: %d\n", yyleng, new_indent, current_indent);
    if (new_indent > current_indent) {
        current_indent = new_indent;
        return TOKEN_INDENT;
    } else if (new_indent < current_indent) {
        // Emitir TOKEN_DEDENT por cada nivel de indentación que se cierra
        int dedent_levels = current_indent - new_indent;
        current_indent = new_indent;
        for (int i = 0; i < dedent_levels; i++) {
            return TOKEN_DEDENT;
        }
    } else {
        return TOKEN_LINEBREAK;
    }
}

\n {
    // Si hay una reducción en la indentación (salto de línea sin espacios)
    printf("current_indent: %d\n", current_indent);
    // Si hay una reducción en la indentación (salto de línea sin espacios)
    if (current_indent > 0) {
        yyless(0);  
        --current_indent;  // Reducir la indentación en uno
        return TOKEN_DEDENT;  // Devolver un TOKEN_DEDENT
        
    }
    return TOKEN_LINEBREAK;
    
}

{SPACE}   { /* ignore */ }
"="          { return TOKEN_ASSIGN; }
"if"          { return TOKEN_IF; }
"else"        { return TOKEN_ELSE; }
"for"         { return TOKEN_FOR; }
"while"       { return TOKEN_WHILE; }
"def"         { return TOKEN_FUNC_DEF; }
"return"      { return TOKEN_RETURN; }
"in"          { return TOKEN_IN; }
"->"         { return TOKEN_ARROW; }
"=="         { return TOKEN_COMPARE; }
"!="         { return TOKEN_DIFFERENT; }
"<"          { return TOKEN_LESS; }
">"          { return TOKEN_GREATER; }
"<="         { return TOKEN_LESS_EQUAL; }
">="         { return TOKEN_GREATER_EQUAL; }
"("          { return TOKEN_LPAREN; }
")"          { return TOKEN_RPAREN; }
":"         { return TOKEN_COLON; }
","          { return TOKEN_COMMA; }
"AND"       { return TOKEN_AND; }
"OR"        { return TOKEN_OR; }
"NOT"       { return TOKEN_NOT; }
{TYPE}       { return TOKEN_TYPE; }
{IDENTIFIER} { return TOKEN_IDENTIFIER; }
{TEXT}       { return TOKEN_STRING; }
"+"         { return TOKEN_PLUS; }
"-"         { return TOKEN_MINUS; }
"*"         { return TOKEN_MULTIPLY; }
"/"         { return TOKEN_DIVIDE; }
{NUMBER}    { return TOKEN_NUMBER; }
<<EOF>> {

    if(current_indent > 0) {
        --current_indent;
        return TOKEN_DEDENT;
    }
    yyterminate(); 
}


%%

int yywrap() { 
    return 1; 
 }