#include "Serializer.hpp"

Serializer::Serializer(){
    // std::cout << "[Serializer] Default constructor is called" << std::endl;
}

Serializer::Serializer(const Serializer& s){
    (void)s;
    // std::cout << "[Serializer] Copy constructor is called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& other){
    if (this == &other){
        return *this;
    }
    return *this;
    // std::cout << "[Serializer] Assignment operator constructor is called" << std::endl;
}

Serializer::~Serializer(){
    // std::cout << "[Serializer] Distructor is called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr){
    // *ptr->ptr_t = 10;
    // uintptr_t data = reinterpret_cast<std::uintptr_t>(ptr->cptr_t);
    uintptr_t data = reinterpret_cast<std::uintptr_t>(ptr->ptr_t);
    return data;
}

Data* Serializer::deserialize(uintptr_t raw){
    Data *data = new Data;
    // data->cptr_t = reinterpret_cast<char *>(raw);
    data->ptr_t = reinterpret_cast<int *>(raw);
    return data;
}