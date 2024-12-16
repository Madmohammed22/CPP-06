#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter() : was_int(0), was_float(0)
{
    // std::cout << "[ScalarConverter] Default constructor is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &s)
{
    this->was_int = s.was_int;
    this->was_float = s.was_float;
    // std::cout << "[ScalarConverter] Copy constructor is called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this == &other)
        return *this;
    // std::cout << "[ScalarConverter] Assignment operator constructor is called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    // std::cout << "[ScalarConverter] Distructor is called" << std::endl;
}

