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
    Resolution(a);
}


void Analysis::Resolution(Ast* node)
{
    //std::cout << "resolviendo " << node->label << std::endl;
    if(node->label == "Block")
    {
        st.enterScope();
    }

    node->validate(st);
    for (Ast* child : node->children) {
        Resolution(child);
    }

    if(node->label == "Block")
    {
        st.exitScope();
    }
}

