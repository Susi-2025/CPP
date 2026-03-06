
#include "../includes/Animal.hpp"

#include <iostream>

Animal::Animal() : type("default")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal " << other.type << " Copy Constructor called" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal " << other.type << " Copy Assignment Constructor called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << type << " Destructor called" << std::endl;
}

std::string Animal::getType() const
{	
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal " << type << " has the sound is: " << std::endl;
}