#include "ScalarConverter.hpp"
#include "Stack.hpp"
int main(int argc, char **argv){
    if (argc == 1){
        std::cout << "<convert> put some data to convert" << std::endl;
        return EXIT_FAILURE;
    }   
    ScalarConverter Scalar;
    std::string input = argv[1];
    Scalar.convert(input);
}