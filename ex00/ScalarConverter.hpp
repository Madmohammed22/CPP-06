#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
#include <limits>
#include "Stack.hpp"

class Stack;

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &s);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public: Stack* _stack;
    Stack* returnBasedOnCondtion(char c);

public:
    static void convert(std::string str);
    // void pushStringToStack(std::string str, Stack* _stack);

public:
    static void displayChar(std::string);
    static void displayInt(std::string str);
    static void displayFloat(std::string str);
    static void displayDouble(std::string str);
};

#endif