#include "Serializer.hpp"

Serializer::Serializer(){
    // std::cout << "[Serializer] Default constructor is called" << std::endl;
}

Serializer::Serializer(const Serializer& s){
    (void)s;
    // std::cout << "[Serializer] Copy constructor is called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other){
    (void)other;
    return *this;
    // std::cout << "[Serializer] Assignment operator constructor is called" << std::endl;
}

Serializer::~Serializer(){
    // std::cout << "[Serializer] Distructor is called" << std::endl;
}

