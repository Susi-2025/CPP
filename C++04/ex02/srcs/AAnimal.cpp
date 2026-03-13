#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(): _type("default")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string &type): _type(type)
{
	std::cout << "AAnimal constructor called" << std::endl;
}
		
AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}
	
AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal copy assignment called" << std::endl;
	if (this != &other)
		_type = other.getType();
	return *this;
}
AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}
		
std::string AAnimal::getType() const
{
	return (_type);
}
void AAnimal::setType(const std::string &type)
{
	std::cout << "AAnimal setType called" << std::endl;
	_type = type;
}

void AAnimal::makeSound() const
{
	std::cout << "Some generic AAnimal sound" << std::endl;
}
