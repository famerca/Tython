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
    
    public:
        Analysis(Ast* a);
        
        void Resolution(Ast* node);
    
    };
    

#endif