
#include <iostream>
#include <cctype>
#include <iomanip>
#include "Phonebook.hpp"

Phonebook::Phonebook() : contact_count(0), oldest_index(0) {}

void Phonebook::addContact(){
    Contact newContact;

    std::cout << "Adding new contact" << std::endl;
    newContact.setContactInfo();

    if (contact_count < 8){
        contacts[contact_count] = newContact;
        contact_count++;
    }
    else {
        contacts[oldest_index] = newContact;
        oldest_index = (oldest_index + 1) % 8;
    }
    std::cout << "Contact added successfully" << std::endl;
}

std::string shorten(std::string s)
{
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}
void Phonebook::searchContact() const{
    if (contact_count == 0){
        std::cout << "Phonebook is empty" << std::endl;
        return;
    }
    std::cout << "\n-------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    std::cout << "\n-------------------------------" << std::endl;  
    for (int i = 0 ; i < contact_count; i++){
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << shorten(contacts[i].getFirstName())
                  << "|" << std::setw(10) << shorten(contacts[i].getLastName())
                  << "|" << std::setw(10) << shorten(contacts[i].getNickName())
                  << "|" << std::endl;
    }
    std::cout << "\n-------------------------------" << std::endl;

    std::cout << "Enter index to display: ";
    int index;
    std::cin >> index;

    if (std::cin.fail() || index < 0 || index >= contact_count) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid index!" << std::endl;
        return;
    }

    displayContact(index);
}

void Phonebook::displayContact(int index) const {
    std::cout << "\n----Contact Details---------------" << std::endl;
    std::cout << "First Name:" << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name:" << contacts[index].getLastName() << std::endl;
    std::cout << "Nick Name:" << contacts[index].getNickName() << std::endl;
    std::cout << "Phone Number:" << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret:" << contacts[index].getDarkestSecret() << std::endl;
}
