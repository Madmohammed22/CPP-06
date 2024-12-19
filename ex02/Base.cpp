#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <typeinfo>

Base::~Base()
{
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

int returnNumber()
{
    int number = 0;
    srand(time(NULL));
    number = rand() % 3 + 1;
    return number;
}
/*
base-to-derived conversions are not allowed
with dynamic_cast unless the base class is polymorphic.
 */
Base *Base::generate()
{
    Base *_Base = new Base;
    int number = returnNumber();
    if (number == 1)
    {
        try
        {
            if (dynamic_cast<Base *>(new A))
            {
                std::cout << "FLAG 1" << std::endl;
                return new Base;
            }
        }
        catch (const std::bad_cast &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    if (number == 2)
    {
        try
        {
            if (dynamic_cast<Base *>(new B))
            {
                std::cout << "FLAG 2" << std::endl;
                return new Base;
            }
        }
        catch (const std::bad_cast &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    if (number == 3)
    {
        C *D = new C;
        try
        {
            if (dynamic_cast<Base *>(new C))
            {
                std::cout << "FLAG 3" << std::endl;
                return new Base;
            }
        }
        catch (const std::bad_cast &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return NULL;
}

void Base::identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        dynamic_cast<A *>(p)->function();
    else{
        std::cout << "ERROR A" << std::endl;
        return;
    }

    if (dynamic_cast<B *>(p))
        dynamic_cast<B *>(p)->function();
    else{
        std::cout << "ERROR B" << std::endl;
        return ;
    }
    if (dynamic_cast<C *>(p))
        dynamic_cast<C *>(p)->function();
    else{
        std::cout << "ERROR C" << std::endl;
        return;
    }
}

void Base::identify(Base &p)
{
    // p.function();
    // static_cast<B>(p).
}

/*
Base *Base::generate()
{
    Base *_Base = new Base;
    // if (dynamic_cast<Base *>(new A)){
    // if (dynamic_cast<A*>(_Base)){
    //     std::cout << "check it's allowed" << std::endl;
    //     return _Base;
    // }
    // else{
    //     std::cout << "ERROR" << std::endl;
    // }
    // return NULL;
    int number = returnNumber();
    if (number == 1)
    {
        A *D = new A;
        try
        {
            if (dynamic_cast<Base *>(new A))
            {
                std::cout << "I was here" << std::endl;
                return new Base;
            }

            Base *returnBase = dynamic_cast<A *>(_Base);
            std::cout << "I was here 1" << std::endl;
            return returnBase;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else if (number == 2)
    {
        B *D = new B;
        try
        {
            Base *returnBase = dynamic_cast<B *>(_Base);
            std::cout << "I was here 2" << std::endl;
            return returnBase;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
    {
        C *D = new C;
        try
        {
            Base *returnBase = dynamic_cast<C *>(_Base);
            std::cout << "I was here 3" << std::endl;
            return returnBase;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return NULL;
}
*/

/*

void Base::identify(Base *p)
{
    if (p)
    {
        int number = returnNumber();
        if (number == 1)
        {
            // dynamic_cast<void *>(p)->f
            dynamic_cast<A *>(p)->function();
        }
        else if (number == 2)
            dynamic_cast<B *>(p)->function();
        else
            dynamic_cast<C *>(p)->function();
    }
}
*/