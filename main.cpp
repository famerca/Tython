#include <stdio.h>
#include <stdlib.h>

#include "ast.hpp"

extern FILE* yyin;
extern int yyparse();
extern Ast* ast;
//extern int yydebug;

void usage(char* argv[])
{
    printf("Usage: %s input_file\n", argv[0]);
    exit(1);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        usage(argv);
    }

    yyin = fopen(argv[1], "r");

    if (!yyin)
    {
        printf("Could not open %s\n", argv[1]);
        exit(1);
    }
    //yydebug = 1;
    int result = yyparse();

    if (result == 0)
    {
        //printf("Parse successful!\n\n\n\n");
        ast->toDot(std::cout);
        Analysis analysis(ast);
        printf("OUTPUT\n\n");
        std::string ident = "";
        std::cout << ast->output(ident);
        
    }
    else
    {
        printf("Parse failed!\n");
    }

    return 0;
}