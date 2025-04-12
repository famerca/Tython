#ifndef SYMBOL_TABLE_HPP
#define SYMBOL_TABLE_HPP

#include <string>
#include <unordered_map>
#include <vector>
#include <optional>

class Ast;

struct Symbol {
    Ast* nodo;
    bool isFunction; 

    Symbol() : nodo(nullptr), isFunction(false) {}
    Symbol(Ast * n, const bool &isf)
        : nodo(n), isFunction(isf) {}
};

class SymbolTable {
public:
    SymbolTable();

    void enterScope();                 // Nuevo ámbito
    void exitScope();                  // Salir del ámbito actual

    bool insert(Ast* node, const std::string& name, const bool& isFunction); 
    std::optional<Symbol> lookup(const std::string& name) const; // Búsqueda global
    std::optional<Symbol> lookupCurrent(const std::string& name) const; // Búsqueda solo en el ámbito actual
    using Scope = std::unordered_map<std::string, Symbol>;
    std::vector<Scope> scopes;

private:
};

#endif // SYMBOL_TABLE_HPP
