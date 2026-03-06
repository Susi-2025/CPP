
#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

#include <iostream>
Dog::Dog()
{
	std::cout << "Dog Default Constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

void Dog::setIdea(int i, std::string idea)
{
	std::cout << "Set Dog Idea at position " << i << std::endl;
	this->brain->setIdea(i, idea);

};

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog Copy Assignment Constructor called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}


std::string Dog::getIdea(int i) const
{
	std::cout << "Get Dog Idea at position " << i << std::endl;
	return this->brain->getIdea(i);
};

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
	delete brain;
}