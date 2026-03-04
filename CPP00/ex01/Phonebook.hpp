
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook{
private:
    Contact contacts[8];
    int contact_count;
    int oldest_index;

public:
    Phonebook();
    void addContact();
    void searchContact() const;
    void displayContact(int index) const;
    // std::string truncateString(const std::string& str) const;
};

#endif