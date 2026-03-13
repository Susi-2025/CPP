
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private:
		Contact _Contacts[8];
		int		_contact_count;
		int		_add_count;
		int		_oldest_index;
	public:
		PhoneBook();
		void addContact();
		void searchContact();
		void displayContact(int i);
		void exitPhoneBook();
		bool check_number(std::string index_input, int no_contact);
		std::string short_str(std::string str);
};

#endif