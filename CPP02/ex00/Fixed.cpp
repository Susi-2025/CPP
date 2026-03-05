
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0){
	std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy Constructor Called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy Assignment Constructor Called" << std::endl;
	this->_rawBits = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor Called" << std::endl;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits( int const raw){
	_rawBits = raw;
}