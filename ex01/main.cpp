#include "Serializer.hpp"
#include <cstdint>

struct s_main
{
    int height;
    int width;
};

int main(int argc, char **argv){
    
    if (argc < 2 ){
        std::cout << "<convert> put some data to convert" << std::endl;
        return EXIT_FAILURE;
    }

    {
        s_main struct_data = {100, 200};
        char buffer_first[sizeof(struct_data)];
        memcpy(buffer_first, &struct_data, sizeof(struct_data));
        std::cout << *((int *)buffer_first) << std::endl;
        
        uintptr_t holder = reinterpret_cast<uintptr_t>(&buffer_first + 1);
        // holder += 0;
        std::cout << *reinterpret_cast<int *>(holder) << std::endl;
        return 0;
        Serializer s;
        Data* data = new Data {};
        int input = atoi(argv[1]);
        data->ptr_t = &input;
        data->cptr_t = strdup("this is just a test");
        char buffer[sizeof(data)];
        std::cout << sizeof(data) << std::endl;
        memcpy(buffer, &data, sizeof(data));
        std::cout << *((int *)buffer)<< std::endl;
        std::cout << "Output : " << data->cptr_t << std::endl;
        
        uintptr_t result = s.serialize(data);
        data = s.deserialize(result);
        std::cout << "Output : " << *data->ptr_t << std::endl;
        return (EXIT_SUCCESS);
    }

    {
        Serializer s;
        Data* data = new Data;
        int input = atoi(argv[1]);
        data->ptr_t = &input;
        uintptr_t result = s.serialize(data);
        data = s.deserialize(result);
        std::cout << "Output : " << *data->ptr_t << std::endl;
        return EXIT_SUCCESS;
    }
    std::cout << "-----------------------------" << std::endl;

    {
        Serializer s;
        Data* data = new Data;
        data->cptr_t = strdup(argv[1]);
        data = s.deserialize(s.serialize(data));
        std::cout << "Output : " << data->cptr_t << std::endl;
        return EXIT_SUCCESS;
    }
}
