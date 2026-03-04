
#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact() : isEmpty(true) {}

void Contact::setContactInfo() {
    // clear any leftover newline from previous input
    std::cin.ignore(10000, '\n');
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    while(firstName.empty()){
        std::cout << "It is empty. Enter again: ";
        std::getline(std::cin, firstName);
    }

    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
    while(lastName.empty()){
        std::cout << "It is empty. Enter again: ";
        std::getline(std::cin, lastName);
    }

    std::cout << "Enter nick name: ";
    std::getline(std::cin, nickName);
    while(nickName.empty()){
        std::cout << "It is empty. Enter again: ";
        std::getline(std::cin, nickName);
    }

    std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
    while(phoneNumber.empty()){
        std::cout << "It is empty. Enter again: ";
        std::getline(std::cin, phoneNumber);
    }

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
    while(darkestSecret.empty()){
        std::cout << "It is empty. Enter again: ";
        std::getline(std::cin, darkestSecret);
    }
    isEmpty = false;
}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickName() const { return nickName; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
bool Contact::isContactEmpty() const { return isEmpty; }
