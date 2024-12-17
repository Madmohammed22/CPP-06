#include "Serializer.hpp"
#include <cstdint>

int main(int argc, char **argv){
    
    if (argc < 2 ){
        std::cout << "<convert> put some data to convert" << std::endl;
        return EXIT_FAILURE;
    }
    Serializer s;
    Data* data = new Data;
    int data_struct = atoi(argv[1]);
    int data_test = data_struct * 0;
    data->ptr_t = &data_struct;
    // data->cptr_t = strdup("this is just a test...");
    uintptr_t data_t = s.serialize(data);
    // unsigned int n1 = __INT_MAX__;
    // unsigned long n2 = __INT32_MAX__;
    Data* test_data = new Data;
    test_data->ptr_t = &data_test;
    data_t = s.serialize(data); 

    // std::cout << data_t << std::endl;
    // return EXIT_FAILURE;
    // char *desrialize_data = reinterpret_cast<char *>(data);
    Data *new_Data = new Data;
    new_Data = s.deserialize(data_t);

    // char *desrialize_data2 = reinterpret_cast<char *>(data);
    // std::cout << new_Data->cptr_t << std::endl;
    std::cout << *new_Data->ptr_t << std::endl;

    return EXIT_SUCCESS;
}