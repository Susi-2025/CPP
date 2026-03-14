#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): _type("default")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type): _type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}
		
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = other;
}
	
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	if (this != &other)
		_type = other.getType();
	return *this;
}
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
		
std::string WrongAnimal::getType() const
{
	return (_type);
}
// void WrongAnimal::setType(const std::string &type)
// {
// 	std::cout << "WrongAnimal setType called" << std::endl;
// 	_type = type;
// }

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes some sound" << std::endl;
}
