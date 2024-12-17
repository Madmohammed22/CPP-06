#include "Serializer.hpp"
#include <cstdint>

int main(int argc, char **argv){
    
    if (argc < 2 ){
        std::cout << "<convert> put some data to convert" << std::endl;
        return EXIT_FAILURE;
    }
    (void)argv;
    Serializer s;
    Data* d = new Data;
    int data_struct = __INT_MAX__;
    d->ptr_t = &data_struct;
    d->cptr_t = strdup("this is just a test");
    uintptr_t data = s.serialize(d);
    // char *desrialize_data = reinterpret_cast<char *>(data);
    Data *new_Data = new Data;
    new_Data = s.deserialize(data);

    // char *desrialize_data2 = reinterpret_cast<char *>(data);
    std::cout << new_Data->cptr_t << std::endl;
    return EXIT_SUCCESS;
}