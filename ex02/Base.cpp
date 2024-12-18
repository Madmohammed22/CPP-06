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

Base* Base::generate(){
    Base* _Base = new Base;
    int number = returnNumber();

    if (number == 1){
        this->number = number;
        A* D = new A;
        Base *returnBase = static_cast<A*>(_Base);
        return returnBase; 
    }
    else if (number == 2){
        this->number = number;
        B* D = new B;
        Base *returnBase = static_cast<B*>(_Base);
        return returnBase; 
    }
    else{
        this->number = number;
        C* D = new C;
        Base *returnBase = static_cast<C*>(_Base);
        return returnBase;
    }
    return NULL;
}

void Base::identify(Base* p){
    int number = returnNumber();
    if (number == 1)
        static_cast<A*>(p)->function();
    else if (number == 2)
        static_cast<B*>(p)->function();
    else
        static_cast<C*>(p)->function();
}

void Base::identify(Base& p){
    // p.function();
    // static_cast<B>(p).
}