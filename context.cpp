// context.cpp
#include "context.hpp"

void Context::push(const std::string& key, Ast* node) {
    std::unordered_map<std::string, Ast*> frame;
    frame[key] = node;
    stack.push_back(frame);
}

void Context::pop() {
    if (!stack.empty()) {
        stack.pop_back();
    }
}

Ast* Context::find(const std::string& key) const {
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
        auto found = it->find(key);
        if (found != it->end()) {
            return found->second;
        }
    }
    return nullptr;
}

bool Context::contains(const std::string& key) const {
    return find(key) != nullptr;
}
