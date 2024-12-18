#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){
    std::cout << "[Base] Distructor is called" << std::endl;
}

int hashit(std::string name_form)
{
    std::string arr[4] = {"A", "B", "C", ""};
    int i = 0;
    while (name_form != arr[i] && !arr[i].empty())
        i++;
    return i + 1;
}

int returnNumber(){
    int number = 0;
    srand (time(NULL));
    number = rand() % 3 + 1;
    return number;
}

// void Base::function(){
//     std::cout << "From A class" << std::endl;
// }

Base* Base::generate(){
    Base* _Base = new Base;
    int number = returnNumber();
    if (number == 1)
        A* D = new A;
    else if (number == 2)
        B* D = new B;
    else
        C* D = new C;
    if (static_cast<B*>(_Base)){
       return _Base;
    }
    return NULL;
}

void Base::identify(Base* p){
    static_cast<B*>(p)->function();   
}

void Base::identify(Base& p){
    // p.function();
}