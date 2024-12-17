#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class Serializer{

public:
    Serializer();
    Serializer(const Serializer& s);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
};

#ifndef