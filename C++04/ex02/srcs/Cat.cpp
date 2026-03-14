#include "Cat.hpp"
#include <iostream>

Cat::Cat(): AAnimal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_cat_brain = new Brain();
}

Cat::Cat(const std::string &type): AAnimal(type)
{
	std::cout << "Cat constructor called" << std::endl;
	_cat_brain = new Brain();
}
		
Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	_cat_brain = new Brain(*other._cat_brain);
}
	
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy assignment called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete _cat_brain;
		_cat_brain = new Brain(*other._cat_brain);
	}
	return *this;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _cat_brain;
}
		
void Cat::makeSound() const
{
	std::cout << "Cat make sound Meow Meow" << std::endl;
}

Brain* Cat::getBrain() const
{
	return _cat_brain;
}

bool Cat::hasBrain() const
{
	return (this->_cat_brain != nullptr);
}