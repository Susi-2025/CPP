#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
	private:
		Brain* _cat_brain;

	public:
		Cat();
		Cat(const std::string &Cat_type);
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();

		void makeSound() const override;
		Brain* getBrain() const;
};