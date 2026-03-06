#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const;
};

class Dog: public Animal{
	public:
		Dog();
		void makeSound() const override;
};

class Cat: public Animal{
	public:
		Cat();
		void makeSound() const override;
};

#endif