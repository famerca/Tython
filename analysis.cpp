#include "analysis.hpp"

void sem_error(const std::string &s, int line)
{
    std::cout << "Line " << line << ": Error: " << s << std::endl;
}

void sem_warning(const std::string &s, int line)
{
    std::cout << "Line " << line << ": Warning: " << s << std::endl;
}

Analysis::Analysis(Ast *a) : ast(a), st() 
{
    //Symblos iniciales 
    Definition *print = new Definition("print");
    print->parameters.push_back(new Parameter("printable", "Any"));
    print->children.push_back(print->parameters[0]);

    st.insert(print, "print", true);

    // Definition *range = new Definition("range");
    // range->parameters.push_back(new Parameter)

    Resolution(a);

    delete print;
}


void Analysis::Resolution(Ast* node)
{
    //std::cout << "resolviendo " << node->label << std::endl;
    if(node->label == "Block")
    {
        st.enterScope();
    }

    node->validate(st, context);
    for (Ast* child : node->children) {
        Resolution(child);
    }

    if(node->label == "Block")
    {
        st.exitScope();
    }
}

