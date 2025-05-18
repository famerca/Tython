#include "analysis.hpp"

void sem_error(const std::string &s, Ast *node)
{
    std::cout << "Line " << node->line << ": Error: " << s << std::endl;
    node->validated = true;
    throw std::runtime_error("semantic error");
}

void sem_warning(const std::string &s, Ast *node)
{
    std::cout << "Line " << node->line << ": Warning: " << s << std::endl;
}

Analysis::Analysis(Ast *a) : ast(a), st()
{
    //Symbolos iniciales 
    error = false;
    Definition *print = new Definition("print");
    print->parameters.push_back(new Parameter("printable", "Any"));
    print->children.push_back(print->parameters[0]);

    st.insert(print, "print", true);

    Definition *range = new Definition("range");
    range->parameters.push_back(new Parameter("Step", "Int"));
    range->parameters.push_back(new Parameter("Limit", "Int"));

    range->addChild(range->parameters[0]);
    range->addChild(range->parameters[1]);

    st.insert(range, "range", true);

    Resolution(a);

    delete print;
    delete range;
}


void Analysis::Resolution(Ast* node)
{
    //std::cout << "resolviendo " << node->label << std::endl;
    if(node->label == "Block")
    {
        st.enterScope();
    }

    try{
        node->validate(st, context);
    }catch(const std::runtime_error &err)
    {
        error = true;
    }


    for (Ast* child : node->children) {
        Resolution(child);
    }

    if(node->label == "Block")
    {
        st.exitScope();
    }
}

