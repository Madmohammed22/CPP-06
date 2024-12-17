#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdlib>
#include <string.h>
#include <cstdint>

struct Data
{
    int *ptr_t;
    char *cptr_t;

};


class Serializer{

public:
    Serializer();
    Serializer(const Serializer& s);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};

#endif