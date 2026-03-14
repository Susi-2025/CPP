#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
// #include <string>

int main()
{    std::cout << "========== TEST 1: Basic Animal Polymorphism ==========" << std::endl;
    {
        // This cannot be done now, AAnimal is an abstract class:
        // const AAnimal* meta = new (std::nothrow) AAnimal();
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
    
        if (j == nullptr || i == nullptr) {
            std::cout << "[ERROR] Memory allocation failed!" << std::endl;
            delete j;
            delete i;
            return 1;
        }
        
        std::cout << "\n[Types]" << std::endl;
        std::cout << "j   : " << j->getType() << std::endl;
        std::cout << "i   : " << i->getType() << std::endl;
    
        std::cout << "\n[Sounds]" << std::endl;
        j->makeSound();
        i->makeSound();

        std::cout << "\n[Cleanup]" << std::endl;
        delete i;
        delete j;
    }
    std::cout << "\n========== ALL TESTS DONE ==========\n" << std::endl;
    return 0;
}