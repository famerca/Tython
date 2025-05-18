// context.cpp
#include "context.hpp"

void Context::push(const std::string& key, Ast* node) 
{
    context frame = {key, node};
    stack.push_back(frame);
}

void Context::pop() 
{
    if (!stack.empty()) {
        stack.pop_back();
    }
}

Ast* Context::find(const std::string& key) const 
{
    for (auto it = stack.rbegin(); it != stack.rend(); ++it) 
    {
        if(it->first == key)
            return it->second;
    }
    return nullptr;
}

bool Context::contains(const std::string& key) const 
{
    return find(key) != nullptr;
}

Ast* Context::current(const std::string &key = "") const
{
    if(stack.empty())
        return nullptr;

    if(key == ""){
        return stack.back().second;
    }else if(stack.back().first == key) {
        return stack.back().second;
    }

    return nullptr;
}