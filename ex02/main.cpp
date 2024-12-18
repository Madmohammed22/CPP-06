// #include "Base.hpp"
#include "A.hpp"

int main(int argc, char **argv){
    
    if (argc < 2 ){
        std::cout << "<convert> put some data to convert" << std::endl;
        return EXIT_FAILURE;
    }
    (void)argv;
    Base *base = new Base;
    base = base->generate();
    base->identify(base);
    return EXIT_SUCCESS;
}