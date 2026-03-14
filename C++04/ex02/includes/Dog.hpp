#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
{
	private:
		Brain* _dog_brain = nullptr;
		
	public:
		Dog();
		Dog(const std::string &dog_type);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const override;
		Brain* getBrain() const;
		bool hasBrain() const;
};