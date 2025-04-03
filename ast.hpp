#include <iostream>
#include <vector>
#include <string>

#ifndef AST_HPP
#define AST_HPP

class Ast 
{
    public:
        std::string label;
        std::vector<Ast*> children;
        
        Ast(std::string label) : label(label) {}
        
        ~Ast() {
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

class Expression: public Statement {
    public:
        std::string value;
        std::string type;

        Expression(std::string v, std::string t) : Statement("expression") {
            value = v;
            type = t;
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


    
#endif