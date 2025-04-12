#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "analysis.hpp"
#include "symbolTable.hpp"

std::string reemplazarComillas(const std::string& texto);

class Ast 
{
    public:
        std::string label;
        std::vector<Ast*> children;
        int line;
        bool validated;
        
        Ast(std::string label) : label(label), line(0), validated(false) {}
        
        virtual ~Ast() {

            for (Ast* child : children) {
                //std::cout << "Destruyendo el hijo: " << child->label << std::endl;
                delete child;
            }
            
        }
        
        void addChild(Ast* child) {
            children.push_back(child);
        }
        
        void generateDot(std::ostream& out, int& counter) {
            int nodeId = counter++;
            out << "  node" << nodeId << " [label=\"" << reemplazarComillas(label) << "\"]" << std::endl;
            for (Ast* child : children) {
                int childId = counter;
                child->generateDot(out, counter);
                out << "  node" << nodeId << " -> node" << childId << ";" << std::endl;
            }
        }
        
        void toDot(std::ostream& out) {
            out << "digraph AST {" << std::endl;
            int counter = 0;
            generateDot(out, counter);
            out << "}" << std::endl;
        }

        virtual void validate(SymbolTable& st) 
        {
            //std::cout << "Validate " << label << std::endl;
            validated = true;
        }
};


class Statement: public Ast {
    public:
         Statement(std::string label) : Ast("stat") {
            this->label = this->label + ": " + label;
        }

    
};

class Definition: public Ast {
    public:
        std::vector<Parameter *> parameters;
        std::string type;
        std::string name;
        
        Definition(std::string i, std::string t = "void") : Ast("Definition"), parameters(), type(t), name(i)
        {}

        void validate(SymbolTable& st) override;
};

class Block: public Ast {
    public:

        Definition *def;

        Block() : Ast("Block")
        {
            def = nullptr;
        }

        void validate(SymbolTable& st) override;
};

class Parameter : public Ast {
    public:
        std::string name;
        std::string type;
        
        Parameter(std::string i, std::string t ) : Ast("Parameter"), name(i), type(t)
        {}
};

class Return: public Ast 
{
    public:
        std::string type;

        Return() : Ast("Return"), type("void")
        {}

        void validate(SymbolTable& st) override;
};

class Declaration: public Statement{
    public:
        std::string name;
        std::string type;
        
        Declaration(std::string i, std::string t ) : Statement("Declaration"), name(i), type(t)
        {}

        void validate(SymbolTable& st) override;
     
};

class Assignment: public Statement
{   
    public:
        std::string name;
        std::string type;

        Assignment(std::string n) : Statement("Assignment"), name(n), type("Any"){}

        void validate(SymbolTable& st) override;
};

class Expression: public Ast {

    public:
        std::string value;
        std::string type;

        Expression(std::string v, std::string t, int l = 0) : Ast("expression") {
            value = v;
            type = t;
            line = l;
            //std::cout << "Creando una expresion:" << value << std::endl;
        }
        
        virtual void validate(SymbolTable& st);

};

class Number: public Expression {
    public:
        Number(std::string v);

        void validate(SymbolTable& st) override{
            validated = true;
        };
};

class String: public Expression
{
    public:
        String(std::string v) : Expression(v, "String") {
            this->label = "String: " + v;
        }

        void validate(SymbolTable& st) override{
            validated = true;
        };
};

class Identifier: public Expression
{
    public:
        Identifier(std::string v, std::string t = "Any") : Expression(v, t) 
        {
            this->label = "Identifier: " + v;
        }

        void validate(SymbolTable& st) override;
};

class Aritmetic: public Expression
{
    public:
        Aritmetic(std::string op, int l) : Expression(op, "Int", l) {
            this->label = op + ": Int";
        }
        void validate(SymbolTable& st) override;
};

class Sum: public Aritmetic
{
    public:
        Sum(int l) : Aritmetic("+", l) 
        {
            //std::cout << "Creando suma";
        }

        void validate(SymbolTable& st) override;
};

class Sub: public Aritmetic
{
    public:
        Sub(int l) : Aritmetic("-", l) {}
};

class Mul: public Aritmetic
{
    public:
        Mul(int l) : Aritmetic("*", l) {}
};

class Div: public Aritmetic
{
    public:
        Div(int l) : Aritmetic("/", l) 
        {
            type = "Float";
        }
    
    void validate(SymbolTable& st) override;
};

class Uminus: public Aritmetic
{
    public:
        Uminus(int l): Aritmetic("uminus", l){}

    void validate(SymbolTable& st) override;
};

class BooleanExp: public Expression
{
    public:
        BooleanExp(std::string op, int l) : Expression(op, "Bool" ,l)
        {
            label = op + ": Bool"; 
        }

    void validate(SymbolTable& st) override;
};

class And: public BooleanExp
{
    public:
        And(int l) : BooleanExp("AND", l) {}
        
};

class Or: public BooleanExp
{
    public:
        Or(int l): BooleanExp("OR", l) {}
};

class Not: public BooleanExp
{
    public:
        Not(int l): BooleanExp("Not", l) {}

    void validate(SymbolTable& st) override;
};

class LogicExp: public Expression
{
    public:
        LogicExp(std::string op, int l) : Expression(op, "Bool", l) {}

        void validateNaN(SymbolTable& st);
        void validateNum(SymbolTable& st);
};

class Compare: public LogicExp
{

    public:
        Compare(int l): LogicExp("==", l) {}

        void validate(SymbolTable& st) override 
        {
            LogicExp::validateNaN(st);
        }
};

class Diff: public LogicExp
{
    public:
        Diff(int l): LogicExp("!=", l) {}
        
        void validate(SymbolTable& st) override
        {
            LogicExp::validateNaN(st);
        }

};

class Greater: public LogicExp
{
    public:
        Greater(int l): LogicExp(">", l) {}

        void validate(SymbolTable& st) override
        {
            LogicExp::validateNum(st);
        }
};
    
class GreaterE: public LogicExp
{
    public:
        GreaterE(int l): LogicExp(">=", l) {}

        void validate(SymbolTable& st) override
        {
            LogicExp::validateNum(st);
        }
};

class Less: public LogicExp
{
    public:
        Less(int l): LogicExp("<", l) {}

        void validate(SymbolTable& st) override
        {
            LogicExp::validateNum(st);
        }
        
};

class LessE: public LogicExp
{
    public:
        LessE(int l): LogicExp("<=", l) {}

        void validate(SymbolTable& st) override
        {
            LogicExp::validateNum(st);
        }
};

class FunctionCall: public Expression 
{
    public:
        std::string name;

        FunctionCall(std::string i, Ast *arg) : Expression(i, "Void")
        {
            this->children = arg->children;
        }

        void validate(SymbolTable& st) override;
};


#endif