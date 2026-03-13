
#include "../includes/Weapon.hpp"

#include <iostream>
#include <string>

Weapon::Weapon(): _type("default")
{
	std::cout << "Weapon Default constructor called " << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon "<< this->_type <<" Constructor called " << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon Destructor called " << std::endl;
} 

void Weapon::setType(std::string type)
{
	std::cout << "Weapon setType called " << std::endl;
	this->_type = type;
}

const std::string& Weapon::getType() const
{
	return (this->_type);
}