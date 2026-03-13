
#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

int main()
{
	std::string command;

	PhoneBook phonebook;

	while(true)
	{
		std::cout << "Input the command: ADD, SEARCH or EXIT: " << std::endl;
		std::getline(std::cin, command);

		for (size_t i = 0; i < command.length(); i++)
			command[i] = toupper(command[i]);

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
		{
			phonebook.exitPhoneBook();
			break;
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}