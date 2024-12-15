#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &s);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

public:
    static void convert(std::string str);

public:
    static char castToChar(std::string str);
    static int castToInt(std::string str);
    static float castToFloat(std::string str);
    static double castToDouble(std::string str);

public:
    static void displayChar(std::string str);
    static void displayInt(std::string str);
    static void displayFloat(std::string str);
    static void displayDouble(std::string str);
};

#endif