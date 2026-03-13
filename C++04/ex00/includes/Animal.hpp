#pragma once
#include <string>

class Animal
{
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string getType() const;
		void setType(std::string const &type);
		
		virtual void makeSound() const;

};