// context.hpp
#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <string>
#include <vector>
#include <unordered_map>

class Ast;

class Context {
public:
    void push(const std::string& key, Ast* node);
    void pop();
    Ast* find(const std::string& key) const;
    bool contains(const std::string& key) const;

private:
    std::vector<std::unordered_map<std::string, Ast*>> stack;
};

#endif // CONTEXT_HPP
