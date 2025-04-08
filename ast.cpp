#include "ast.hpp"

Number::Number(std::string v) : Ast("Number")
{
    value = v;
    type = "Int";
    for(unsigned int i = 0; i < v.length(); ++i)
    {
        if(v[i] == '.')
        {
            type = "Float";
            break;
        }
    }
}

Identifier::Identifier(std::string v) : Ast("Identifier")
{
    value = v;
}

