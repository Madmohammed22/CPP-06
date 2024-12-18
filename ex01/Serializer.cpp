#include "Serializer.hpp"

Serializer::Serializer(){
    std::cout << "[Serializer] Default constructor is called" << std::endl;
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
    std::cout << "[Serializer] Distructor is called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr){
    // if (ptr->cptr_t)
    //     return reinterpret_cast<std::uintptr_t>(&ptr->cptr_t);
    if(ptr->ptr_t){
        // uintptr_t ptrInteger = reinterpret_cast<std::uintptr_t>(&ptr->ptr_t);
        // ptrInteger += 0;
        // int *data = reinterpret_cast<int *>(ptrInteger);
        // std::cout << "Example : " << *data << std::endl;
        return reinterpret_cast<std::uintptr_t>(ptr->ptr_t);
    }
    return 0;
}

Data* Serializer::deserialize(uintptr_t raw){
    Data *data = new Data;
    // std::cout << raw << std::endl;
    // if (data->ptr_t != NULL){
    //     data->ptr_t = reinterpret_cast<int *>(raw);
    //     return data;
    // }
    // if (data->cptr_t != NULL){
    //     data->cptr_t = reinterpret_cast<char *>(raw);
    //     return data;
    // }
    // data->cptr_t = reinterpret_cast<char *>(raw);
    data->ptr_t = reinterpret_cast<int *>(raw);
    
    return data;
}