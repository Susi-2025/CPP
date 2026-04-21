
#include "Generate.hpp"
#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void){
    static bool seed = false;
    if (!seed){
        std::srand(std::time(NULL));
        seed = true;
    }
    int random = std::rand()%3;

    switch(random){
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}