#include <iostream>
#include <vector>
#include <string>

#include "error.hpp"
#ifndef AST_HPP
#define AST_HPP

class Ast 
{
    public:
        std::string label;
        std::vector<Ast*> children;
        int line;
        
        Ast(std::string label) : label(label), line(0) {}
        
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
            out << "  node" << nodeId << " [label=\"" << label << "\"]" << std::endl;
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

        virtual void validate() {}
};


class Statement: public Ast {
    public:
         Statement(std::string label) : Ast("stat") {
            this->label = this->label + ": " + label;
        }
};

class Declaration: public Statement{
    public:
        std::string identifier;
        std::string type;
        
        Declaration(std::string i, std::string t ) : Statement("Declaration") 
        {
            this->identifier = i;
            this->type = t;
   
        }
     
};

class Expression: public Ast {

    public:
        std::string value;
        std::string type;

        Expression(std::string v, std::string t, int l = 0) : Ast("expression") {
            value = v;
            type = t;
            line = l;
        }
        
        virtual void validate();

};

class Number: public Expression {
    public:
        Number(std::string v);
};

class String: public Expression
{
    public:
        String(std::string v) : Expression(v, "String") {
            this->label = "String: " + v;
        }
};

class Identifier: public Expression
{
    public:
        Identifier(std::string v, std::string t = "Any") : Expression(v, t) 
        {
            this->label = "Identifier: " + v;
        }
};

class Aritmetic: public Expression
{
    public:
        Aritmetic(std::string op, int l) : Expression(op, "Int", l) {
            this->label = op + ": Int";
        }
        void validate() override;
};

class Sum: public Aritmetic
{
    public:
        Sum(int l) : Aritmetic("+", l) 
        {
            //std::cout << "Creando suma";
        }
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
        Div(int l) : Aritmetic("/", l) {}
    
    void validate() override;
};

class Uminus: public Aritmetic
{
    public:
        Uminus(int l): Aritmetic("uminus", l){}

    void validate() override;
};

class BooleanExp: public Expression
{
    public:
        BooleanExp(std::string op, int l) : Expression(op, "Bool" ,l)
        {
            label = op + ": Bool"; 
        }

    void validate() override;
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

    void validate() override;
};

class LogicExp: public Expression
{
    public:
        LogicExp(std::string op, int l) : Expression(op, "Bool", l) {}

        void validateNaN();
        void validateNum();
};

class Compare: public LogicExp
{

    public:
        Compare(int l): LogicExp("==", l) {}

        void validate() override 
        {
            LogicExp::validateNaN();
        }
};

class Diff: public LogicExp
{
    public:
        Diff(int l): LogicExp("!=", l) {}
        
        void validate() override
        {
            LogicExp::validateNaN();
        }

};

class Greater: public LogicExp
{
    public:
        Greater(int l): LogicExp(">", l) {}

        void validate() override
        {
            LogicExp::validateNum();
        }
};
    
class GreaterE: public LogicExp
{
    public:
        GreaterE(int l): LogicExp(">=", l) {}

        void validate() override
        {
            LogicExp::validateNum();
        }
};

class Less: public LogicExp
{
    public:
        Less(int l): LogicExp("<", l) {}

        void validate() override
        {
            LogicExp::validateNum();
        }
        
};

class LessE: public LogicExp
{
    public:
        LessE(int l): LogicExp("<=", l) {}

        void validate() override
        {
            LogicExp::validateNum();
        }
};

#endif