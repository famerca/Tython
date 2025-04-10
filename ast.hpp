#include <iostream>
#include <vector>
#include <string>

#include "error.hpp"
#ifndef AST_HPP
#define AST_HPP

class Ast 
{
    public:
        std::string label;
        std::vector<Ast*> children;
        int line;
        
        Ast(std::string label) : label(label), line(0) {}
        
        virtual ~Ast() {
            for (Ast* child : children) {
                //std::cout << "Destruyendo el hijo: " << child->label << std::endl;
                delete child;
            }
        }
        
        void addChild(Ast* child) {
            children.push_back(child);
        }
        
        void generateDot(std::ostream& out, int& counter) {
            int nodeId = counter++;
            out << "  node" << nodeId << " [label=\"" << label << "\"]" << std::endl;
            for (Ast* child : children) {
                int childId = counter;
                child->generateDot(out, counter);
                out << "  node" << nodeId << " -> node" << childId << ";" << std::endl;
            }
        }
        
        void toDot(std::ostream& out) {
            out << "digraph AST {" << std::endl;
            int counter = 0;
            generateDot(out, counter);
            out << "}" << std::endl;
        }
};


class Statement: public Ast {
    public:
         Statement(std::string label) : Ast("stat") {
            this->label = this->label + ": " + label;
        }
};

class Declaration: public Statement{
    public:
        std::string identifier;
        std::string type;
        
        Declaration(std::string i, std::string t ) : Statement("Declaration") 
        {
            this->identifier = i;
            this->type = t;
   
        }
     
};


class Expression: public Ast {

    public:
        std::string value;
        std::string type;

        Expression(std::string v, std::string t, int l = 0) : Ast("expression") {
            value = v;
            type = t;
            line = l;
        }
        
        virtual void validate();

};

class Number: public Expression {
    public:
        Number(std::string v);
};

class String: public Expression
{
    public:
        String(std::string v) : Expression(v, "String") {}
};

class Identifier: public Expression
{
    public:
        Identifier(std::string v, std::string t = "Any") : Expression(v, t) {}
};

class Aritmetic: public Expression
{
    public:
        Aritmetic(std::string op, int l) : Expression(op, "Int", l) {}
        void validate() override;
};
    
#endif