
#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat Default Constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat Copy Assignment Constructor called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meo Meo" << std::endl;
}

void Cat::setIdea(int i, std::string idea)
{
	std::cout << "Set Cat Idea at position " << i << std::endl;
	this->brain->setIdea(i, idea);
}

std::string Cat::getIdea(int i) const
{
	std::cout << "Get Cat Idea at position " << i << std::endl;
	return this->brain->getIdea(i);
}
