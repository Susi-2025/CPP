#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating animals ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    if (meta == nullptr || j == nullptr || i == nullptr) {
        std::cout << "[ERROR] Memory allocation failed!" << std::endl;
        delete meta;
        delete j;
        delete i;
        return 1;
    }
    
    std::cout << "\n=== Testing getType() ===" << std::endl;
    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;
    std::cout << "meta->getType(): " << meta->getType() << std::endl;

    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    i->makeSound();  // Cat sound
    j->makeSound();  // Dog sound
    meta->makeSound(); // Animal sound

    std::cout << "\n=== Testing copy constructor ===" << std::endl;
    Dog originalDog;
    Dog copiedDog(originalDog); // copy constructor
    copiedDog.makeSound();

    Cat originalCat;
    Cat copiedCat(originalCat); // copy constructor
    copiedCat.makeSound();

    std::cout << "\n=== Testing copy assignment ===" << std::endl;
    Dog assignDog;
    assignDog = originalDog;  // copy assignment
    assignDog.makeSound();

    Cat assignCat;
    assignCat = originalCat;  // copy assignment
    assignCat.makeSound();

    std::cout << "\n=== Cleaning up Animal Meta===" << std::endl;
    delete meta;
	std::cout << "\n=== Cleaning up Dog J===" << std::endl;
    delete j;
	std::cout << "\n=== Cleaning up Cat I===" << std::endl;
    delete i;
	std::cout << "\n=== Cleaning up Origin and Copy===" << std::endl;

	std::cout << "=== WrongAnimal Test ===" << std::endl;

    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* wrong = new WrongCat();

    std::cout << "\n=== Testing getType() ===" << std::endl;
    std::cout << "meta->getType(): " << meta2->getType() << std::endl;
    std::cout << "wrong->getType(): " << wrong->getType() << std::endl;

    std::cout << "\n=== Testing makeSound() ===" << std::endl;
    meta2->makeSound();   // calls WrongAnimal sound
    wrong->makeSound();  // calls WrongAnimal sound, NOT WrongCat!

    std::cout << "\n=== Cleaning up ===" << std::endl;
    delete meta2;
    delete wrong;

    return 0;
}