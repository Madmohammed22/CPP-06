#include "ScalarConverter.hpp"
ScalarConverter::ScalarConverter()
{
    // std::cout << "[ScalarConverter] Default constructor is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &s)
{
    (void)s;
    std::cout << "[ScalarConverter] Copy constructor is called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    std::cout << "[ScalarConverter] Assignment operator constructor is called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    // std::cout << "[ScalarConverter] Distructor is called" << std::endl;
}

void ScalarConverter::displayChar(std::string str)
{
    if (strrchr(str.c_str(), 'f') != 0)
    {
        std::cout << "char: '*'" << std::endl;
        return;
    }

    if (str.length() != 1)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = str[0] - 48;
    if (c >= 0 && c <= 32)
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: " << c << std::endl;
}
void ScalarConverter::displayFloat(std::string str)
{
    if (str.compare("nan") == 0)
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (strrchr(str.c_str(), 'f') != 0)
    {
        str = str.substr(0, strrchr(str.c_str(), 'f') - str.c_str() + 1);
        float n = atof(str.c_str());
        printf("float: %.1ff\n", n);
        return;
    }
    // if (is_digits(str) == false)
    // {
    //     std::cout << "float: impossible" << std::endl;
    //     return;
    // }
    float n = atof(str.c_str());
    printf("float: %.1ff\n", n);
}

void ScalarConverter::displayDouble(std::string str)
{
    if (str.compare("nan") == 0)
    {
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (strrchr(str.c_str(), 'f') != 0)
    {
        str = str.substr(0, strrchr(str.c_str(), 'f') - str.c_str() + 1);
        float n = atof(str.c_str());
        printf("float: %.1f\n", n);
        return;
    }
    // if (is_digits(str) == false)
    // {
    //     std::cout << "double: impossible" << std::endl;
    //     return;
    // }
    float n = atof(str.c_str());
    printf("double: %.1f\n", n);
}
