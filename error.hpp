#include <iostream>
#include <string>

#ifndef ERROR_HPP
#define ERROR_HPP

void sem_error(const std::string &s, int line);

void sem_warning(const std::string &s, int line);

#endif