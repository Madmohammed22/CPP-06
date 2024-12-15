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
    if (strrchr(str.c_str(), 'f') != 0){
        std::cout << "char: '*'" << std::endl;
        return;
    }

    if (str.length() != 1){
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = str[0] - 48;
    if (c >= 0 && c <= 32)
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: "<< c << std::endl;
}

bool is_digits(std::string str)
{
    for (size_t i = 0; i < str.length(); i++) {
        int check = isdigit(str[i]);
        if (!check)
            return false;
    }
    return true;
}
int countAppearcanceOfChar(std::string s, char c) {
  int count = 0;

  for (size_t i = 0; i < s.length(); i++)
    if (s[i] == c) count++;

  return count;
}


Stack* ScalarConverter::returnBasedOnCondtion(char c){
    (void)c;
    for (int i = 0; i < this->_stack->getTop(); i++){
        this->_stack->pop();
    }
    return this->_stack;
}

// The only  think that I can relay on when it comes to handle
// Int cast is the string must conatins these rules
// (0.0) || (0.0f) || (0) || (-0.0) || (-42) || (+42) || (-42.0)
// fi9 ma3ana atabi
// so + and - should not be exist
bool checkStackIfValidToContinue(Stack *_stack, char ch){
    int count = 0;
    for (int i = 0; i < _stack->getTop(); i++){
        if ((_stack->peek() == ch)){
            count++;
        }
        _stack->pop();
    }
    if (count == 1)
        return true;
    std::cout << "I was here" << std::endl;
    return false;
}

bool pushStringToStack(std::string str, Stack* _stack){
    Stack *_reversedStack = new Stack();
    for (int i = str.length(); i >= 0; i--)
        _stack->push(str[i]);
    if (!checkStackIfValidToContinue(_stack, '-'))
        return false;
    size_t size = _stack->getTop();
    for (int i = 0; i < (int)size; i++){
        _reversedStack->push(_stack->peek());        
        _stack->pop();
    }
    
    return true;
}

void ScalarConverter::displayInt(std::string str)
{
    Stack* _stack = new Stack();
    if (pushStringToStack(str, _stack) == false)
        return;
    if (strrchr(str.c_str(), 'f') != 0){
        str = str.substr(0, strrchr(str.c_str(), 'f') - str.c_str());
        int n = atoi(str.c_str());
        std::cout << "int: " << n << std::endl;
        return;
    }
    
    if (is_digits(str) == false){
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int n = atoi(str.c_str());
    std::cout << "int: " << n << std::endl;
}

void ScalarConverter::displayFloat(std::string str)
{
    if (str.compare("nan") == 0){
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (strrchr(str.c_str(), 'f') != 0){
        str = str.substr(0, strrchr(str.c_str(), 'f') - str.c_str() + 1);
        float n = atof(str.c_str());
        printf("float: %.1ff\n", n);
        return;
    }
    if (is_digits(str) == false){
        std::cout << "float: impossible" << std::endl;
        return;
    }
    float n = atof(str.c_str());
    printf("float: %.1ff\n", n);
}

void ScalarConverter::displayDouble(std::string str)
{
    if (str.compare("nan") == 0){
        std::cout << "double: nan" << std::endl;
        return;
    }

    if (strrchr(str.c_str(), 'f') != 0){
        str = str.substr(0, strrchr(str.c_str(), 'f') - str.c_str() + 1);
        float n = atof(str.c_str());
        printf("float: %.1f\n", n);
        return;
    }
    if (is_digits(str) == false){
        std::cout << "double: impossible" << std::endl;
        return;
    }
    float n = atof(str.c_str());
    printf("double: %.1f\n", n);
}

void ScalarConverter::convert(std::string str)
{
    displayChar(str);
    displayInt(str);
    displayFloat(str);
    displayDouble(str);
}