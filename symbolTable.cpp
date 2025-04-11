#include "symbolTable.hpp"

SymbolTable::SymbolTable() {
    // Creamos un ámbito global al inicio
    enterScope();
}

void SymbolTable::enterScope() {
    scopes.emplace_back(); // Añade un nuevo scope vacío
}

void SymbolTable::exitScope() {
    if (!scopes.empty()) {
        scopes.pop_back();
    }
}

bool SymbolTable::insert(Ast *node, const std::string& name, const bool& isFunction)
{
    if (scopes.empty()) return false;

    auto& currentScope = scopes.back();
    if (currentScope.count(name) > 0) {
        // Ya existe en el scope actual
        return false;
    }

    Symbol symbol(node, isFunction);
    currentScope[name] = symbol;
    return true;
}

std::optional<Symbol> SymbolTable::lookup(const std::string& name) const {
    for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
        const auto& scope = *it;
        auto found = scope.find(name);
        if (found != scope.end()) {
            return found->second;
        }
    }
    return std::nullopt;
}

std::optional<Symbol> SymbolTable::lookupCurrent(const std::string& name) const {
    if (scopes.empty()) return std::nullopt;

    const auto& currentScope = scopes.back();
    auto found = currentScope.find(name);
    if (found != currentScope.end()) {
        return found->second;
    }
    return std::nullopt;
}
