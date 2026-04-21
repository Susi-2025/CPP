#include "Identify.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"

void identify(Base* p){
    if(dynamic_cast<A*>(p))
        std::cout << "A";
    else if(dynamic_cast<B*>(p))
        std::cout << "B";
    else if (dynamic_cast<C*>(p))
        std::cout << "C";
}

void identify(Base& p){
    try{
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A";
        return;
    } catch (std::bad_cast&) {}

    try{
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B";
        return;
    } catch (std::bad_cast&) {}

    try{
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C";
        return;
    } catch (std::bad_cast&) {}
}