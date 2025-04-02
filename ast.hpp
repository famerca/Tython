#include <iostream>
#include <vector>
#include <string>

#ifndef AST_HPP
#define AST_HPP

class Ast {
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
    
#endif