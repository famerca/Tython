#include "ast.hpp"

std::string reemplazarComillas(const std::string& texto)
{
    std::string resultado = texto;
    std::replace(resultado.begin(), resultado.end(), '\"', '\'');
    return resultado;
}


void Declaration::validate(SymbolTable& st, Context& ctx)
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
        
        expr->validate(st, ctx);

        if(this->type == "Any")
        {
            sem_warning("Any type is not recommended", this->line);
        }else if(this->type != expr->type)
        {
            sem_error("Type mismatch in declaration", this->line);
        }
    }

    if(!st.insert(this, this->name, false))
    {
        sem_warning("Redeclaration of " + this->name, this->line);
    }

    validated = true;
}

void Assignment::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    if(children.size() != 1)
    {
        sem_error("Declaration can only have one expression", this->line);
    }

    auto symbol = st.lookup(this->name);

    if(symbol)
    {
        if(symbol->isFunction)
            sem_error("Assignment to function", this->line);
        
        this->type = dynamic_cast<Declaration*>(symbol->nodo)->type;
    }
    else
        sem_error("Undeclared identifier: " + this->name, this->line);

    Expression *expr = dynamic_cast<Expression*>(children[0]);
    expr->validate(st, ctx);

    if(this->type != expr->type)
    {
        std::string error = "Training assignment " + expr->type + " to " + this->name + ":" + this->type + "\n";
        
        sem_error(error, this->line);
    }

    validated = true;
}

void Identifier::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;
    
    auto symbol = st.lookup(this->value);

    if(symbol)
    {
        if(symbol->isFunction)
            sem_error("Identifier cannot be used as function", this->line);
        
        
        if(symbol->nodo->label == "Parameter")
        {
            Parameter* param = dynamic_cast<Parameter*>(symbol->nodo);
            this->type = param->type;
        }
        else
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


void  Expression::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    if(children.size() != 2)
    {
        sem_error("Operation for", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);
    
    if(left == nullptr || right == nullptr)
    {
        sem_error("Operaciones no permitidas", this->line);
    }

    left->validate(st, ctx);
    right->validate(st, ctx);

    if(left->type != right->type)
    {
        std::string error = "En la operacion '" + this->label + "' los operandos deben ser del mismo tipo \n";
        error += "Tipo izquierdo: " + left->type + "\n";
        error += "Tipo derecho: " + right->type + "\n";
        sem_error(error, this->line);
    }

    validated = true;

}

void Aritmetic::validate(SymbolTable& st, Context& ctx)
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

    left->validate(st, ctx);
    right->validate(st, ctx);

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

void Div::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    Expression* right = dynamic_cast<Expression*>(children[1]);
    right->validate(st, ctx);

    if(right->value == "0")
    {
        sem_error("Division by 0 not allowed", this->line);
    }

    Aritmetic::validate(st, ctx);
}

void Sum::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);

    if(left->type == "Float" || right->type == "Float")
        type = "Float";
    
    if(left->type == "String" || right->type == "String")
        type = "String";
    
    Aritmetic::validate(st, ctx);
}

void BooleanExp::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    if(children.size() != 2)
    {
        sem_error("Operation not allowed", this->line);
        validated = true;
        return;
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    Expression* right = dynamic_cast<Expression*>(children[1]);

    left->validate(st, ctx);
    right->validate(st, ctx);

    if(left->type != "Bool" || right->type != "Bool")
    {
        sem_error("Binary operation allowed only for boolean type", this->line);
    }

    validated = true;
}

void Uminus::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;
    if(children.size() !=1)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);
    left->validate(st, ctx);

    if(left->type != "Int" && left->type != "Float")
        sem_error("Aritmetic operation allowed only for int and float types", this->line);

    validated = true;
}

void Not::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    if(children.size() !=1)
    {
        sem_error("Operation not allowed", this->line);
    }

    Expression* left = dynamic_cast<Expression*>(children[0]);

    left->validate(st, ctx);
    
    if(left->type == "Any")
    {
        sem_warning("Opertation with Any type is not recommended", this->line);
        return;
    }

    if(left->type != "Bool")
        sem_error("Binary operation allowed only for boolean type", this->line);

    validated = true;

}

void LogicExp::validateNaN(SymbolTable& st, Context& ctx)
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

    left->validate(st, ctx);
    right->validate(st, ctx);

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

void LogicExp::validateNum(SymbolTable& st, Context& ctx)
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

    left->validate(st, ctx);
    right->validate(st, ctx);

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

void Definition::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    if(children.size() == 0)
    {
        sem_error("Invalid definition", this->line);
    }

    if(children.size() == 2)
    {
        for(Ast* param : children[1]->children)
        {
            Parameter* paramAst = dynamic_cast<Parameter*>(param);
            
            parameters.push_back(paramAst);

            if(paramAst->type == "Any")
            {
                sem_warning("Type Any is not recommended", this->line);
            }
        }
    }

    if(!st.insert(this, this->name, true))
    {
        sem_error("Redeclaration of function " + this->name, this->line);
    }

    ctx.push("function", this);

    validated = true;

}

void Block::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    Ast *node = ctx.current("function");

    if(node != nullptr)
    {
        Definition *d = dynamic_cast<Definition *>(node);

        for(Parameter* param : d->parameters)
        {
            st.insert(param, param->name, false);
        }


        if(d->type == "void")
        {
            validated = true;
            return;
        }


        for(Ast* stmt : children)
        {
            if(stmt->label == "return")
            {
                validated = true;
                return;
            }
            
        }

        sem_error("This function must return a " + d->type, this->line);
        

    }

    node = ctx.current("for");

    if(node != nullptr)
    {
        For *fornode = dynamic_cast<For *>(node);
        st.insert(fornode->iterator, fornode->iterator->name, false);

    }

    validated = true;

}

void Return::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    Ast *f = ctx.find("function");

    if(f == nullptr)
    {
        sem_error("Return statement out of function context", line);
        validated = true;
        return;

    }

    Definition *fun =  dynamic_cast<Definition *>(f);
    
    if(fun->type == "void")
    {
        validated = true;
        return;
    }

    if(children.size() != 1 )
    {
        sem_error("Invalid return", this->line);
    }

    Expression* expr = dynamic_cast<Expression*>(children[0]);
    expr->validate(st, ctx);

    if(expr->type != fun->type)
    {
        std::string error = "Return type mismatch in function \n";
        error += "Expected: " + fun->type + "\n";
        error += "Returned: " + expr->type + "\n";
        sem_error(error, this->line);
    }

    validated = true;
}

void FunctionCall::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    auto symbol = st.lookup(value);

    if(symbol)
    {
        if(symbol->isFunction)
        {
            Definition* def = dynamic_cast<Definition*>(symbol->nodo);

            type = def->type;

            if(children.size() != def->parameters.size())
            {
                sem_error("Invalid arguments count", this->line);
            }

            for(int i = 0; i < children.size(); ++i)
            {
                Expression* expr = dynamic_cast<Expression*>(children[i]);
                expr->validate(st, ctx);

                if(def->parameters[i]->type == "Any")
                    continue;

                if(expr->type == "Any")
                {
                    sem_warning("Use of Any type not recommended", line);
                    continue;
                }

                if(expr->type != def->parameters[i]->type)
                {
                    std::string error = "Invalid argument type in function call \n";
                    error += "Expected: " + def->parameters[i]->type + "\n";
                    error += "Received: " + expr->type + "\n";
                    sem_error(error, this->line);
                }
            }
            
        }else
            sem_error("Cannot call non-function", this->line);
    } else
        sem_error("Undefined function: " + value, this->line);

    

    validated = true;
} 

void For::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    ctx.push("for", this);

    validated = true;
}

void While::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    ctx.push("while", this);

    validated = true;
}

void Break::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    if(!ctx.contains("for") && !ctx.contains("while"))
    {
        sem_error("Break statement out of loop", line);
    }
    
    validated = true;
}

void Continue::validate(SymbolTable& st, Context& ctx)
{
    if(validated)
        return;

    if(!ctx.contains("for") && !ctx.contains("while"))
    {
        sem_error("Continue statement out of loop", line);
    }
    
    validated = true;
}


