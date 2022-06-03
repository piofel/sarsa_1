#pragma once

#include <string>
#include <vector>

#include "Numeric_types.hpp"

class Diagnostic_tools
{
    public:
        template<class T> static void print(const std::string& variable_name, const T& variable);
        template<class T> static void print(const std::string& variable_name, const std::vector<T>& variable);
};

template<class T>
void Diagnostic_tools::print(const std::string& variable_name, const T& variable)
{
    std::cout << "Variable " << variable_name << " has value: " << variable << '\n';
}

template<class T>
void Diagnostic_tools::print(const std::string& variable_name, const std::vector<T>& variable)
{
    std::cout << "Variable " << variable_name << " has value:\n";
    for (UInt i = 0; i<variable.size(); ++i)
        std::cout << variable[i] << " at index " << i << '\n';
}