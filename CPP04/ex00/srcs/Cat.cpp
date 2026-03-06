
#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy Assignment Constructor called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meo Meo" << std::endl;
}
