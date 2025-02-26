#include <stdio.h>
#include <stdlib.h>

#include "token.h"

// Declaraciones de variables y funciones de Flex
extern FILE* yyin;
//extern int yylex();
extern char* yytext;


const char* to_str(token_t t);

// Función para mostrar el uso del programa
void usage(char *argv[]) {
    printf("Usage: %s input_file\n", argv[0]);
    exit(1);
}

// Función principal
int main(int argc, char* argv[]) {
    if (argc != 2) {
        usage(argv);
    }

    // Abrir el archivo de entrada
    yyin = fopen(argv[1], "r");

    if (!yyin) {
        printf("Could not open %s\n", argv[1]);
        exit(1);
    }

    // Leer tokens hasta el final del archivo
    while (1) {
        token_t t = yylex();

        if (t == TOKEN_EOF) {
            printf("End of file\n");
            break;
        }

        // Imprimir el token y su valor
        printf("Token: %s, Value: %s\n", to_str(t), yytext);
    }



    return 0;
}