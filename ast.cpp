#include "ast.hpp"

Number::Number(std::string v) : Expression(v,"Int")
{
    for(unsigned int i = 0; i < v.length(); ++i)
    {
        if(v[i] == '.')
        {
            type = "Float";
            break;
        }
    }
}


void  Expression::validate()
{
    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);
    
    if(left == nullptr || right == nullptr)
    {
        sem_error("Operaciones no permitidas", this->line);
    }

    if(left->type != right->type)
    {
        std::string error = "En la operacion '" + this->label + "' los operandos deben ser del mismo tipo \n";
        error += "Tipo izquierdo: " + left->type + "\n";
        error += "Tipo derecho: " + right->type + "\n";
        sem_error(error, this->line);
    }

}

void Aritmetic::validate()
{
    if(children.size() != 2)
    {
        sem_error("Operacion no permitida", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);
    
    if(left == nullptr || right == nullptr)
    {
        sem_error("Operaciones no permitidas", this->line);
    }

    if(left->type == "Bool" || right->type == "Bool")
    {
        sem_error("Operacion no permitida para tipos booleanos", this->line);
    }

    if(left->type == "Any" || right->type == "Any")
    {
        sem_warning("Opertation with Any type is not recommended", this->line);
    }

    if(left->type != right->type)
    {
        if((left->type == "Int" && right->type == "Float") || (left->type == "Float" && right->type == "Int"))
        {

            std::string error = "Operation between int and float loses precision \n";
            sem_warning(error, this->line);

        }else
        {
            std::string error = "En la operacion '" + this->label + "' los operandos deben ser del mismo tipo \n";
            error += "Tipo izquierdo: " + left->type + "\n";
            error += "Tipo derecho: " + right->type + "\n";
            sem_error(error, this->line);
        }

    }
}