#include <iostream>
#include <string>

#ifndef ERROR_HPP
#define ERROR_HPP

void sem_error(const std::string &s, int line)
{
    std::cout << "Line " << line << ": Error: " << s << std::endl;
}

void sem_warning(const std::string &s, int line)
{
    std::cout << "Line " << line << ": Warning: " << s << std::endl;
}
#endif