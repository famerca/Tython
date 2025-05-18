#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "ast.hpp"
#include "symbolTable.hpp"
#include "context.hpp"


void sem_error(const std::string &s, Ast *node);

void sem_warning(const std::string &s, Ast *node);

class Analysis {
    private:
        SymbolTable st;
        Context context;
        Ast* ast;
        bool error;
    
    public:
    
        Analysis(Ast* a);
        void Resolution(Ast* node);
        bool is_error()
        {
            return error;
        }
    
    };
    

#endif