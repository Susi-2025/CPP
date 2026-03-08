
#ifndef BUREUACAT_HPP
#define BUREUACAT_HPP

#include <string>

class Bureaucat
{
    private:
        std::string _name;
        int _grade;
    public:
        Bureaucat();
        Bureaucat(const Bureaucat& other);
        Bureaucat& operator=(const Bureaucat& other);
        ~Bureaucat();

        std::string getName();
        int getGrade();
        bool GradeTooHighException();
        bool GradeTooLowException();
        Bureaucat& operator++();
        Bureaucat& operator--();
};

// std::ostream &operator<<(std::ostream &out, const Bureaucat &bureaucat);

#endif