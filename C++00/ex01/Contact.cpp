
#include "Contact.hpp"
#include <iostream>


void Contact::setContactInfo()
{
	// std::cout << "setContactInfo called " << std::endl;
	std::string firstname;
	std::cout << "First Name is: " << std::endl;
	std::getline(std::cin, firstname);
	while (firstname.empty())
	{
		std::cout << "It is empty. Input again: " << std::endl;
		std::getline(std::cin, firstname);
	}
	_firstname = firstname;

	std::string lastname;
	std::cout << "Last Name is: " << std::endl;
	std::getline(std::cin, lastname);
	while (lastname.empty())
	{
		std::cout << "It is empty. Input again: " << std::endl;
		std::getline(std::cin, lastname);
	}
	_lastname = lastname;
	
	std::string nickname;
	std::cout << "Nick Name is: " << std::endl;
	std::getline(std::cin, nickname);
	while (nickname.empty())
	{
		std::cout << "It is empty. Input again: " << std::endl;
		std::getline(std::cin, nickname);
	}
	_nickname = nickname;

	std::string phonenumber;
	std::cout << "Phone Number is: " << std::endl;
	std::getline(std::cin, phonenumber);
	while(valid_phone(phonenumber))
	{
		std::cout << "Phone Number must be number. Input again:" << std::endl;
		std::getline(std::cin, phonenumber);
	}
	_phonenumber = phonenumber;

	std::string darkestsecret;
	std::cout << "Darkest Secret is: " << std::endl;
	std::getline(std::cin, darkestsecret);
	while (darkestsecret.empty())
	{
		std::cout << "It is empty. Input again: " << std::endl;
		std::getline(std::cin, darkestsecret);
	}
	_darkestsecret = darkestsecret;
}

std::string Contact::getFirstName() const
{
	return _firstname;
}
		
std::string Contact::getLastName() const
{
	return _lastname;
}
	
std::string Contact::getNickName() const
{
	return _nickname;
}
std::string Contact::getPhoneNumber() const
{
	return _phonenumber;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestsecret;
}

bool Contact::valid_phone(std::string phone)
{
	if (phone.empty())
		return 1;
	for (size_t i = 0; i < phone.length(); i++)
	{
		int no = phone[i] - '0';
		if (no < 0 || no > 9)
			return 1;
	}
	return 0;
}