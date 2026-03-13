
#include "../includes/Harl.hpp"

#include <iostream>

void Harl::debug(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special"
 				<< " ketchup burger. I really do! " << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << " I cannot believe adding extra bacon costs more money. You didn’t put "
 	<< "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for "
		<< "years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::unknown(void)
{
	std::cout << "Probaly complaining about insignificant problems" << std::endl;
}

void Harl::complain(std::string level)
{
	int no = UNKNOWN;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "UNKNOWN"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			no = i;
			break;
		}
	}
	switch(no)
	{
		case DEBUG: debug(); /* fall through */
		case INFO: info(); /* fall through */
		case WARNING: warning(); /* fall through */
		case ERROR: error(); break;
		default: unknown(); 
	}
}