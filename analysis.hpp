#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP
#include <iostream>
#include <string>
#include "ast.hpp"
#include "symbolTable.hpp"


void sem_error(const std::string &s, int line);

void sem_warning(const std::string &s, int line);

class Analysis {
    private:
        SymbolTable st;
        Ast* ast;
    
        // pila para el recorrido en profundidad
        std::vector<Ast*> pila;
    
    public:
        Analysis(Ast* a);
    
        void nameResolution();
        void typeChecking();
    
        // inicializa el recorrido
        void beginTraversal();
    
        // obtiene el siguiente nodo (o nullptr si ya no hay)
        Ast* nextNode();
    };
    

#endif