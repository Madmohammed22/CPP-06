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
    data->ptr_t = &data_struct;
    // data->cptr_t = strdup("this is just a test...");
    uintptr_t data_t = s.serialize(data);
    uint32_t x = 2;
    uint32_t y = 3;
    // ((uintptr_t)x >> 8) + y
    data_t = 10 + (x* 0 + y * 0);
    std::cout << data_t << std::endl;
    return EXIT_FAILURE;
    // char *desrialize_data = reinterpret_cast<char *>(data);
    Data *new_Data = new Data;
    new_Data = s.deserialize(data_t);

    // char *desrialize_data2 = reinterpret_cast<char *>(data);
    // std::cout << new_Data->cptr_t << std::endl;
    std::cout << *new_Data->ptr_t << std::endl;

    return EXIT_SUCCESS;
}