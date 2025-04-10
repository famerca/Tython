#include "ast.hpp"

Number::Number(std::string v) : Expression(v,"Int")
{
    this->label = "number: " + v;

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



    if(left->type != right->type)
    {
        if(left->type == "Any" || right->type == "Any")
        {
            sem_warning("Opertation with Any type is not recommended", this->line);
        }else
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
}

void Div::validate()
{
    Aritmetic::validate();

    Expression* right = dynamic_cast<Expression*>(children[1]);

    if(right->value == "0")
    {
        sem_error("Division by 0 not allowed", this->line);
    }

}

void BooleanExp::validate()
{
    if(children.size() != 2)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);

    if(left->type != "Bool" || left->type != "Bool")
    {
        sem_error("Binary operation allowed only for boolean type", this->line);
    }

}

void Uminus::validate()
{
    if(children.size() !=1)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);

    if(left->type != "Int" && left->type != "Float")
        sem_error("Aritmetic operation allowed only for int and float types", this->line);
}

void Not::validate()
{
    
    if(children.size() !=1)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    
    if(left->type == "Any")
    {
        sem_warning("Opertation with Any type is not recommended", this->line);
        return;
    }

    if(left->type != "Bool")
        sem_error("Binary operation allowed only for boolean type", this->line);

}

void LogicExp::validateNaN()
{
    if(children.size() != 2)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);
    
    if(left == nullptr || right == nullptr)
    {
        sem_error("Operaciones no permitidas", this->line);
    }


    if(left->type != right->type)
    {
        if(left->type == "Any" || right->type == "Any")
        {
            sem_warning("Opertation with Any type is not recommended", this->line);
        }else
        {

            if(!((left->type == "Int" && right->type == "Float") || (left->type == "Float" && right->type == "Int")))
            {

                std::string error = "Logic operation '" + this->label + "' for different types not allowed \n";
                error += "Type left: " + left->type + "\n";
                error += "Type right: " + right->type + "\n";
                sem_error(error, this->line);

            }
            
        }

    }
}

void LogicExp::validateNum()
{

    if(children.size() != 2)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);
    
    if(left == nullptr || right == nullptr)
    {
        sem_error("Operaciones no permitidas", this->line);
    }

    if(left->type == "Any" || right->type == "Any")
    {
        sem_warning("Opertation with Any type is not recommended", this->line);
    }else
    {

        if((left->type != "Int" && left->type != "Float") || (right->type != "Float" && right->type != "Int"))
        {

            std::string error = "Logic operation '" + this->label + "' for non-numeric types not allowed \n";
            error += "Type left: " + left->type + "\n";
            error += "Type right: " + right->type + "\n";
            sem_error(error, this->line);

        }
        
    }

}