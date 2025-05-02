#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP
#include <iostream>
#include <string>
#include <vector>
#include "ast.hpp"
#include "symbolTable.hpp"
#include "context.hpp"


void sem_error(const std::string &s, int line);

void sem_warning(const std::string &s, int line);

class Analysis {
    private:
        SymbolTable st;
        Context context;
        Ast* ast;
    
    public:
    
        Analysis(Ast* a);
        void Resolution(Ast* node);
    
    };
    

#endif