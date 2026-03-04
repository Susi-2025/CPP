#include <iostream>
#include <string>

int main()
{
	std::string str_ini = "HI THIS IS BRAIN";
	std::string* stringPTR = &str_ini;
	std::string& stringREF = str_ini;

	std::cout << "Memory address of str_ini: " << &str_ini << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "The value of str_ini: " << str_ini << std::endl;
	std::cout << "The value of stringPTR: " << *stringPTR << std::endl;
	std::cout << "The value of stringREF: " << stringREF << std::endl;
	return 0;
}