#include "Animal.hpp"
#include <iostream>

Animal::Animal(): _type("default")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type): _type(type)
{
	std::cout << "Animal constructor called" << std::endl;
}
		
Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}
	
Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal copy assignment called" << std::endl;
	if (this != &other)
		_type = other.getType();
	return *this;
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
		
std::string Animal::getType() const
{
	return (_type);
}
// void Animal::setType(const std::string &type)
// {
// 	std::cout << "Animal setType called" << std::endl;
// 	_type = type;
// }

void Animal::makeSound() const
{
	std::cout << "Some generic animal sound" << std::endl;
}
