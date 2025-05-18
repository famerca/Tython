#include <stdio.h>
#include <stdlib.h>

#include <fstream>

#include "ast.hpp"

extern FILE* yyin;
extern int yyparse();
extern Ast* ast;
//extern int yydebug;

void usage(char *argv[]) {
    std::cout << "Uso: " << argv[0] << " [opciones] archivo_fuente" << std::endl;
    std::cout << "Opciones:" << std::endl;
    std::cout << "  -ast           Generar el árbol de sintaxis abstracta (AST) en un archivo .dot." << std::endl;
    std::cout << "  -o <nombre>    Especificar el nombre del archivo de salida." << std::endl;
    std::cout << "  --help, -h    Mostrar esta ayuda." << std::endl;
    exit(1);
}



int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        usage(argv);
    }

    bool generar_ast = false;
    std::string output_file = "";
    std::string input_file;
    bool input_find = false;

    for (int i = 1; i < argc; ++i) {
        std::string argumento = argv[i];
        //std::cout << argumento << ",";
        if (argumento == "-ast") {
            generar_ast = true;
        } else if (argumento == "-o") {
            if (i + 1 < argc) {
                output_file = argv[++i]; // Tomamos el siguiente argumento como el nombre del archivo
            } else {
                std::cerr << "Error: Se esperaba un nombre de archivo después de -o." << std::endl;
                usage(argv);
            }
        } else if (argumento == "--help" || argumento == "-h") {
            usage(argv);
        } else if (!input_find) {
            input_file = argumento;
            input_find = true;
        } else {
            std::cerr << "Opción o argumento desconocido: " << argumento << std::endl;
            usage(argv);
        }
    }

    if (!input_find) {
        usage(argv);
    }

    yyin = fopen(input_file.c_str(), "r");

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
        if(generar_ast)
        {
            std::ofstream archivo_dot("ast.dot");

            if (!archivo_dot.is_open()) 
            {
                printf("Could not open ast.dot\n");
                exit(1);
            }
            ast->toDot(archivo_dot);
            archivo_dot.close();
        }

        Analysis analysis(ast);

        if(!analysis.is_error())
        {

            std::string ident = "";
            if(output_file != "")
            {

                std::ofstream output(output_file);

                if (!output.is_open()) 
                {
                    printf("Could not open %s\n", output_file.c_str());
                    exit(1);
                }
                output << ast->output(ident);
                output.close();

            }else{

                printf("OUTPUT\n\n");
                std::cout << ast->output(ident);

            }
        }else
            printf("Compiled failed\n");
        
    }
    else
    {
        printf("Parse failed!\n");
    }

    return 0;
}