#include"Stack.h"

#include <iostream>

Stack::Stack(int t) {  //:: scope resolution operator which tells compiler
                       //function belong class named Stack
    tos = t;
}
bool Stack::IsFull(
    Stack *s)  // return type classname::functionname(parameters)
{
    if (s->tos == MAX - 1) {
        return true;
    } else {
        return false;
    }
}
bool Stack::IsEmpty(Stack *s) {
    if (s->tos == -1)
        return true;
    else
        return false;
}
void Stack::push(Stack *s, float element) {
    if (IsFull(s)) {
        std::cout << "Stack is Full ! " << std::endl;
    } else {
        s->tos++;
        s->data[s->tos] = element;
    }
}
float Stack::pull(Stack *s) {
    float element;
    if (IsEmpty(s))
        std::cerr << "The Stack is empty " << std::endl;
    else {
        element = s->data[s->tos];
        s->tos--;
    }
    return element;
}
void Stack::display(Stack *s) {
    if (IsEmpty(s)) {
        float element;
        std::cerr << "Why ! Why ! Why!" << std::endl;
        std::cout << "Enter the number to be pushed NOW " << std::endl;
        std::cin >> element;
        push(s, element);
    }
    std::cout << "[";
    while (s->tos = -1) {
        std::cout << s->data[s->tos] << ",";
        s->tos--;
    }
    std::cout << "]" << std::endl;
}
