#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
		std::string getType() const;
		virtual void makeSound() const;
};

class WrongCat: public WrongAnimal{
	public:
		WrongCat();
		void makeSound() const override;
};

#endif