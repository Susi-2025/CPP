
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
	: _contact_count(0), _add_count(0),  _oldest_index(0){}

void PhoneBook::addContact()
{
	std::cout << "\n-------------------------------" << std::endl;
	std::cout << "addContact called " << std::endl;
	if (_add_count >= 8)
	{
		_oldest_index = (_add_count) % 8;
		_contact_count = 8;
	}
	_Contacts[_oldest_index].setContactInfo();
	_oldest_index++;
	if (_contact_count < 8)
		_contact_count++;
	_add_count++;
}

void PhoneBook::searchContact()
{
	std::string index_input;

	std::cout << "\n-------------------------------" << std::endl;
	std::cout << "searchContact called " << std::endl;
	if (_contact_count == 0)
	{
		std::cout << "phonebook is empty " << std::endl;
		return ;
	}
	std::cout << "\n-------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    std::cout << "\n-------------------------------" << std::endl;
	for (int i = 0; i < _contact_count; i++)
	{
		std::cout << "|" << std::setw(10) << i
              << "|" << std::setw(10) << short_str(_Contacts[i].getFirstName())
              << "|" << std::setw(10) << short_str(_Contacts[i].getLastName())
              << "|" << std::setw(10) << short_str(_Contacts[i].getNickName())
              << "|" << std::endl;
	}
	std::cout << "\n-------------------------------" << std::endl;
	std::cout << "Input the index:" << std::endl;
	std::getline(std::cin, index_input);
	while (check_number(index_input, _contact_count) == 1)
	{
		std::cout << "Invalid index!. Index must be from 0 to "<< _contact_count - 1 << std::endl;
		std::cout << "Input the index again:" << std::endl;
		std::getline(std::cin, index_input);
	}
	int index = index_input[0] - '0';
	displayContact(index);
}

void PhoneBook::displayContact(int i)
{
	std::cout << "\n-------------------------------" << std::endl;
	std::cout << "displayContact called " << std::endl;
	std::cout << "Contact at index " << i << " :" << std::endl;
	std::cout << "First Name: " << _Contacts[i].getFirstName() << std::endl;
	std::cout << "Last Name: " << _Contacts[i].getLastName() << std::endl;
	std::cout << "Nick Name: " << _Contacts[i].getNickName() << std::endl;
	std::cout << "Phone Number: " << _Contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << _Contacts[i].getDarkestSecret() << std::endl;
	std::cout << "\n-------------------------------" << std::endl;
}

void PhoneBook::exitPhoneBook()
{
	std::cout << "\n-------------------------------" << std::endl;
	std::cout << "Exit the phonebook!!" << std::endl;
}

bool PhoneBook::check_number(std::string index_input, int no_contact)
{
	if (index_input.length() != 1)
		return 1;
	int i = index_input[0] - '0';
	if (i > no_contact - 1 || i < 0)
		return 1;
	return 0;
}

std::string PhoneBook::short_str(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + '.');
	else
		return str;
}