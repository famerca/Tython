#include "analysis.hpp"

void sem_error(const std::string &s, int line)
{
    std::cout << "Line " << line << ": Error: " << s << std::endl;
}

void sem_warning(const std::string &s, int line)
{
    std::cout << "Line " << line << ": Warning: " << s << std::endl;
}

Analysis::Analysis(Ast *a) : ast(a), st() 
{
    beginTraversal();
    nameResolution();
}

void Analysis::nameResolution() {

    Ast* node;

    while ((node = nextNode()) != nullptr) {
        // Aquí haces lo que quieras con cada nodo:
        // - dynamic_cast para ver el tipo
        // - insertar en la tabla
        // - hacer lookup
        // - etc.

        if(node->label == "Block")
            st.enterScope();

        node->validate(st);

        if(node->label == "Declaration")
        {
            Declaration* decl = dynamic_cast<Declaration*>(node);
            st.insert(node, decl->name, false);
        }


        std::cout << "Node: " << node->label << std::endl;
    }
}

void Analysis::beginTraversal() {
    pila.clear();
    if (ast) pila.push_back(ast);
}

Ast* Analysis::nextNode() {
    if (pila.empty()) return nullptr;

    Ast* actual = pila.back();
    pila.pop_back();

    // Agrega hijos en orden inverso para mantener preorden
    for (auto it = actual->children.rbegin(); it != actual->children.rend(); ++it) {
        pila.push_back(*it);
    }

    return actual;
}