#include "Stack.hpp"

Stack::Stack() : top(-1){
}

Stack::Stack(Stack &s){
    this->top = s.top;
}

Stack &Stack::operator=(Stack &other){
    if (this == &other)
        return *this;
    this->top = other.top;
    return *this;
}

Stack::~Stack(){
}

void Stack::push(char c){
    if (this->top >= __INT_MAX__)
        return;
    ch[++top] = c; 
}

char Stack::pop(){
    if (this->getTop() < 0){
        std::cout << "Empty Stack" << std::endl;
        _exit(EXIT_FAILURE);
    }
    return this->ch[top--];
}

char Stack::peek(){
    if (this->getTop() < 0){
        std::cout << "Empty Stack" << std::endl;
        _exit(EXIT_FAILURE);
    }
    return this->ch[top];
}

int Stack::getTop(){
    return this->top;
}