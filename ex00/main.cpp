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
    // int a = 5;
//   int b = 10;
//   std::cout << std::fixed;
//   std::cout << std::setprecision(2);
//   std::cout << atof("44") << "\n";
}