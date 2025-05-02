// context.hpp
#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <string>
#include <vector>
#include <utility>

class Ast;

class Context {
public:
    void push(const std::string& key, Ast* node);
    void pop();
    Ast* find(const std::string& key) const;
    Ast* current(const std::string& key) const;
    bool contains(const std::string& key) const;

private:
    using context = std::pair<std::string, Ast*>;
    std::vector<context> stack;
};

#endif // CONTEXT_HPP
