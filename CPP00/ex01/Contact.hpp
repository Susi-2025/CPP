
#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class Contact{
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
    bool isEmpty;
public:
    Contact();
    void setContactInfo();
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    bool isContactEmpty() const;
};
#endif