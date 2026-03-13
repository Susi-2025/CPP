#include "Dog.hpp"

#include <iostream>

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_dog_brain = new Brain();
}

Dog::Dog(const std::string &type): Animal(type)
{
	std::cout << "Dog constructor called" << std::endl;
	_dog_brain = new Brain();
}
		
Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	_dog_brain = new Brain(*other._dog_brain);
}
	
Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete _dog_brain;
		_dog_brain = new Brain(*other._dog_brain);
	}
	return *this;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _dog_brain;
}
		
void Dog::makeSound() const
{
	std::cout << "Dog make sound Woof Woof" << std::endl;
}

Brain* Dog::getBrain() const
{
	return _dog_brain;
}