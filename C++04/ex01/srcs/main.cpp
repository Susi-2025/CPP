#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>
// #include <string>

int main()
{
    std::cout << "-------Brain setIdeas---------" << std::endl;
    Brain Beta;    // For Dogs
    Brain Alpha;   // For Cats

    for (int i = 0; i < 100; i++)
    {
        Beta.setIdea("Dog idea " + std::to_string(i), i);
        Alpha.setIdea("Cat idea " + std::to_string(i), i);
    }
    std::cout << std::endl;

    std::cout << "-------Brain getIdeas---------" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Beta idea " << i << ": " << Beta.getIdea(i) << std::endl;
        std::cout << "Alpha idea " << i << ": " << Alpha.getIdea(i) << std::endl;
    }
    std::cout << std::endl;

    Animal* array[10];
    for (int i = 0; i < 5; i++)
        array[i] = new Dog();
    
    for (int i = 5; i < 10; i++)
        array[i] = new Cat();
  
    //Check type
    std::cout << "-------Check Type---------" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << "Type of Animal at " << i << " position has type: "
        << array[i]->getType() << std::endl;
    std::cout << std::endl;

    //Make sound
    std::cout << "-------Make Sound---------" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Animal at " << i << " position has sound: ";
        array[i]->makeSound();
    }
    std::cout << std::endl;

    std::cout << "-------Test Deep Copy---------" << std::endl;

    Dog* originalDog = new Dog("Husky");
    originalDog->getBrain()->setIdea("Human is Best", 0);

    Dog copiedDog = *originalDog; // Copy constructor works

    copiedDog.getBrain()->setIdea("Dog is best friend", 0);

    // Verify deep copy
    std::cout << "Original Dog idea 0: "
            << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea 0: "
            << copiedDog.getBrain()->getIdea(0) << std::endl;

    delete originalDog;

    std::cout << "-------Clean up---------" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        delete array[i];
    }
    std::cout << std::endl;
    return 0;
}