#include "ScalarConverter.hpp"

bool is_digits(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        int check = isdigit(str[i]);
        if (!check)
            return false;
    }
    return true;
}
int countAppearcanceOfChar(std::string s, char c)
{
    int count = 0;

    for (size_t i = 0; i < s.length(); i++)
        if (s[i] == c)
            count++;

    return count;
}

Stack *ScalarConverter::returnBasedOnCondtion(char c)
{
    (void)c;
    for (int i = 0; i < this->_stack->getTop(); i++)
    {
        this->_stack->pop();
    }
    return this->_stack;
}

// The only  think that I can relay on when it comes to handle
// Int cast is the string must conatins these rules
// (0.0) || (0.0f) || (0) || (-0.0) || (-42) || (+42) || (-42.0)
// fi9 ma3ana atabi
// so + and - should not be exist
int countSpecificChar(Stack *_stack, char ch)
{
    int count = 0;
    for (int i = 0; i < _stack->getTop(); i++)
    {
        if (_stack->peek() == ch)
            count++;
        _stack->pop();
    }
    return count;
}
bool checkStackIfValidToContinue(Stack *_stack, char ch)
{
    std::cout << "after size :" << _stack->getTop() << std::endl;
    (void)ch;
    for (int i = 0; i < _stack->getTop(); i++)
    {
        // if (!((isdigit(_stack->peek()) == 1) || _stack->peek() == ch || _stack->peek() == '+' || _stack->peek() == '.'))
        // {
        //     return false;
        // }
        // if (_stack->peek() == ch || _stack->peek() == '+' || _stack->peek() == '.'){
        //     count++;
        // }
        _stack->pop();
    }
    std::cout << "befor size :" << _stack->getTop() << std::endl;
    if (countSpecificChar(_stack, '-') == 1)
    {
        return true;
    }
    std::cout << "I was here" << std::endl;
    return false;
}

bool pushStringToStack(std::string str, Stack *_stack)
{
    Stack *_reversedStack = new Stack();
    for (int i = str.length(); i >= 0; i--)
        _stack->push(str[i]);
    
    Stack *test = new Stack();
    test = test->cloneStack(_stack);
    for (int i = 0; i < test->getTop(); i++){
        std::cout << "[" << test->peek() << "]" << std::endl;
        test->pop();
    }
    if (!checkStackIfValidToContinue(_stack, '-'))
        return false;
    size_t size = _stack->getTop();
    for (int i = 0; i < (int)size; i++)
    {
        _reversedStack->push(_stack->peek());
        _stack->pop();
    }

    return true;
}

void ScalarConverter::displayInt(std::string str)
{
    Stack *_stack = new Stack();
    if (pushStringToStack(str, _stack) == false)
    {
        std::cout << "[INVALID]" << std::endl;
        return;
    }
    else
        std::cout << "[VALID]" << std::endl;

      
    if (strrchr(str.c_str(), 'f') != 0)
    {
        str = str.substr(0, strrchr(str.c_str(), 'f') - str.c_str());
        int n = atoi(str.c_str());
        std::cout << "int: " << n << std::endl;
        return;
    }

    if (is_digits(str) == false)
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int n = atoi(str.c_str());
    std::cout << "int: " << n << std::endl;
}

void ScalarConverter::convert(std::string str)
{
    displayInt(str);
    // displayChar(str);
    // displayFloat(str);
    // displayDouble(str);
}