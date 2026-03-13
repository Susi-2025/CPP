
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string _type;
	
	public:
		Weapon();
		Weapon(std::string name);
		~Weapon();

		void setType(std::string type);
		const std::string& getType() const;
};

#endif