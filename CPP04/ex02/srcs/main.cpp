
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include <iostream>

int main()
{
	std::cout <<"---------Test for Normal Animal-----------" << std::endl;

	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();

	std::cout <<"---------Test for Wrong Animal-----------" << std::endl;

	// const WrongAnimal* alpha = new WrongAnimal();
	const WrongAnimal* v = new WrongCat();
	std::cout << v->getType() << " " << std::endl;
	v->makeSound(); //will output the cat sound!
	// alpha->makeSound();

	std::cout <<"---------Destructor Animals-----------" << std::endl;
	delete v;
	// delete alpha;
	delete i;
	delete j;
	// delete meta;

	std::cout << "\n---------Test 3: Array of 10 Animals (5 Dogs, 5 Cats)-----------\n" << std::endl;

    const int SIZE = 10;
    Animal* animals[SIZE];

    for (int i = 0; i < SIZE; i++) {
        if (i < SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n---------Making sounds from the array-----------\n" << std::endl;
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();

    std::cout << "\n---------Deleting array Animals (correct destructors called)-----------\n" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
		delete animals[i];
	}
	
	std::cout << "\n---------Test 4: Deep Copy - Dog-----------\n" << std::endl;
    {
        Dog original;
        original.setIdea(0, "I want to chase the ball");

        Dog copy(original);

        copy.setIdea(0, "I want to sleep");

        std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "Copy     idea[0]: " << copy.getIdea(0)     << std::endl;
        std::cout << "(Original must still show 'I want to chase the ball' - deep copy confirmed)" << std::endl;
    }

	std::cout << "\n---------Test 5: Deep Copy - Cat-----------\n" << std::endl;
    {
        Cat original;
        original.setIdea(0, "I want to knock things off shelves");

        Cat copy(original);

        copy.setIdea(0, "Nap time");

        std::cout << "Original idea[0]: " << original.getIdea(0) << std::endl;
        std::cout << "Copy     idea[0]: " << copy.getIdea(0)     << std::endl;
        std::cout << "(Original must still show 'I want to knock things off shelves' - deep copy confirmed)" << std::endl;
    }

	std::cout << "\n---------Test 6: Assignment Operator Deep Copy-----------\n" << std::endl;
    {
        Dog d1;
        d1.setIdea(0, "Fetch!");

        Dog d2;
        d2.setIdea(0, "Sleep");

        d1 = d2;
        d2.setIdea(0, "Eat");

        std::cout << "d1 idea[0]: " << d1.getIdea(0) << std::endl;
        std::cout << "d2 idea[0]: " << d2.getIdea(0) << std::endl;
        std::cout << "(d1 must still show 'Sleep' - deep copy confirmed)" << std::endl;
    }

	std::cout << "\n---------Test 7: Self-Assignment Safety-----------\n" << std::endl;
    {
        Dog d;
        d.setIdea(0, "Self assignment safe?");
        d = d;
        std::cout << "Self-assignment survived. idea[0]: " << d.getIdea(0) << std::endl;
    }

	std::cout << "\n---------Test 8: Polymorphic Delete (no leak)-----------\n" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
        std::cout << "(If Dog/Cat/Brain destructors printed above - no leak)" << std::endl;
    }

	return 0;
}