#include "AAnimal.hpp"
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

    AAnimal* animals[10];
    for (int i = 0; i < 5; i++)
        animals[i] = new Cat();
    
    for (int i = 5; i < 10; i++)
        animals[i] = new Dog();
  
    //Check type
    std::cout << "-------Check Type---------" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << "Type of Animal at " << i << " position has type: "
        << animals[i]->getType() << std::endl;
    std::cout << std::endl;

    //Make sound
    std::cout << "-------Make Sound---------" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Animal at " << i << " position has sound: ";
        animals[i]->makeSound();
    }
    std::cout << std::endl;

    std::cout << "-------Test Deep Copy---------" << std::endl;

    Dog* dog2 = new Dog("Chi Hua Hua");
    dog2->getBrain()->setIdea("Human is Best", 0);

    Dog copiedDog2 = *dog2; // Copy constructor works

    copiedDog2.getBrain()->setIdea("Dog is best friend", 0);

    // Verify deep copy
    std::cout << "Original Dog idea 0: "
            << dog2->getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea 0: "
            << copiedDog2.getBrain()->getIdea(0) << std::endl;

    delete dog2;

    std::cout << "-------Clean up---------" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }
    std::cout << std::endl;
    return 0;
}