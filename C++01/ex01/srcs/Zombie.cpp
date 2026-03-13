
#include "../includes/Zombie.hpp"

#include <iostream>
#include <string>

Zombie::Zombie(): _name("default")
{
	std::cout << "Default constructor called " << std::endl;
}

Zombie::Zombie(std::string name)
{
	_name = name;
	std::cout << "Zombie "<< this->_name <<" Constructor called " << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie "<< this->_name <<" Destructor called " << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name)
{
	this->_name = name;
}