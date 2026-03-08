
#include "Bureuacat.hpp"

#include <iostream>

Bureaucat::Bureaucat(): _name("default"), _grade(1) {
    std::cout<< "Bureeaucat default constructor called" << std::endl;
}

Bureaucat::Bureaucat(const Bureaucat& other)
{
    std::cout << "Bureaucat copy constructor called" << std::endl;
    *this = other;
}

Bureaucat& Bureaucat::operator=(const Bureaucat& other)
{
    std::cout << "Bureaucat copy assignment operator called"  << std::endl;
    if (this != &other)
    {
        this->_name = other._name;
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucat::~Bureaucat()
{
    std::cout << "Bureaucat destructor called" << std::endl;
}

std::string Bureaucat::getName()
{
    std::cout << "GetName functions called" << std::endl;
    return _name;
}

int Bureaucat::getGrade()
{
    std::cout << "GetGrade functions called" << std::endl;
    return _grade;
}

bool Bureaucat::GradeTooHighException()
{
    if (this->_grade > 150)
    {
        std::cout << "Bureaucat grade is over 150" << std::endl;
        return 1;
    }
    return 0;
}

bool Bureaucat::GradeTooLowException()
{
    if (this->_grade < 1)
    {
        std::cout << "Bureaucat grade is lower than 1" << std::endl;
        return 1;
    }
    return 0;
}

Bureaucat& Bureaucat::operator++()
{
    int res;
    _grade = this->getGrade() + 1;
    return *this;
}

// std::ostream& Bureaucat(std::ostream &out, const Bureaucat &Bureaucat)
// {

// }