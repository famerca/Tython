#include "ast.hpp"


void Declaration::validate(const SymbolTable &st)
{
    if(validated)
        return;
    
    if(children.size() > 1)
    {
        sem_error("Declaration can only have one expression", this->line);
    }
    if(children.size() == 1)
    {
        Expression* expr = dynamic_cast<Expression*>(children[0]);
        expr->validate(st);

        if(this->type != expr->type)
        {
            sem_error("Type mismatch in declaration", this->line);
        }
    }

    validated = true;
}

void Identifier::validate(const SymbolTable &st)
{
    if(validated)
        return;
    
    auto symbol = st.lookup(this->value);

    if(symbol)
    {
        if(symbol->isFunction)
            sem_error("Identifier cannot be used as function", this->line);
        
        this->type = dynamic_cast<Declaration*>(symbol->nodo)->type;
    }
    else
        sem_error("Undeclared identifier: " + this->value, this->line);

    validated = true;
}

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


void  Expression::validate(const SymbolTable &st)
{
    if(validated)
        return;

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);
    
    if(left == nullptr || right == nullptr)
    {
        sem_error("Operaciones no permitidas", this->line);
    }

    left->validate(st);
    right->validate(st);

    if(left->type != right->type)
    {
        std::string error = "En la operacion '" + this->label + "' los operandos deben ser del mismo tipo \n";
        error += "Tipo izquierdo: " + left->type + "\n";
        error += "Tipo derecho: " + right->type + "\n";
        sem_error(error, this->line);
    }

    validated = true;

}

void Aritmetic::validate(const SymbolTable &st)
{

    if(validated)
        return;
    
    if(children.size() != 2)
    {
        sem_error("Operacion no permitida", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);

    // std::cout << "Validando aritmetic" << "left: " << left->type << "\n"
    // << "right: " << right->type << "\n";
    
    if(left == nullptr || right == nullptr)
    {
        sem_error("Operaciones no permitidas", this->line);
    }

    left->validate(st);
    right->validate(st);

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

     validated = true;
}

void Div::validate(const SymbolTable &st)
{
    if(validated)
        return;

    Expression* right = dynamic_cast<Expression*>(children[1]);
    right->validate(st);

    if(right->value == "0")
    {
        sem_error("Division by 0 not allowed", this->line);
    }

    Aritmetic::validate(st);

}

void BooleanExp::validate(const SymbolTable &st)
{
    if(validated)
        return;

    if(children.size() != 2)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);

    left->validate(st);
    right->validate(st);

    if(left->type != "Bool" || right->type != "Bool")
    {
        sem_error("Binary operation allowed only for boolean type", this->line);
    }

    validated = true;
}

void Uminus::validate(const SymbolTable &st)
{
    if(validated)
        return;
    if(children.size() !=1)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    left->validate(st);

    if(left->type != "Int" && left->type != "Float")
        sem_error("Aritmetic operation allowed only for int and float types", this->line);

    validated = true;
}

void Not::validate(const SymbolTable &st)
{
    if(validated)
        return;

    if(children.size() !=1)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);

    left->validate(st);
    
    if(left->type == "Any")
    {
        sem_warning("Opertation with Any type is not recommended", this->line);
        return;
    }

    if(left->type != "Bool")
        sem_error("Binary operation allowed only for boolean type", this->line);

    validated = true;

}

void LogicExp::validateNaN(const SymbolTable& st)
{
    if(validated)
        return;

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

    left->validate(st);
    right->validate(st);

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

     validated = true;
}

void LogicExp::validateNum(const SymbolTable& st)
{

    if(validated)
        return;
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

    left->validate(st);
    right->validate(st);

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

    validated = true;
}