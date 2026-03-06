
#include "../includes/Animal.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout <<"---------Test for Normal Animal-----------" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout <<"---------Test for Wrong Animal-----------" << std::endl;

	const WrongAnimal* alpha = new WrongAnimal();
	const WrongAnimal* v = new WrongCat();
	std::cout << v->getType() << " " << std::endl;
	v->makeSound(); //will output the cat sound!
	alpha->makeSound();

	std::cout <<"---------Destructor Animals-----------" << std::endl;
	delete v;
	delete alpha;
	delete i;
	delete j;
	delete meta;

	return 0;
}