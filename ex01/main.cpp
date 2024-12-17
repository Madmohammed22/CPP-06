#include "ScalarConverter.hpp"
#include "Stack.hpp"
int main(int argc, char **argv){
    
    if (argc < 2 ){
        std::cout << "<convert> put some data to convert" << std::endl;
        return EXIT_FAILURE;
    }

    ScalarConverter Scalar;
    std::string input = argv[1];
    Scalar.convert(input);
    // float positive_infinity = -inff;
    // std::cout << positive_infinity << std::endl;
    return EXIT_SUCCESS;
}