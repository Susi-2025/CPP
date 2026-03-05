#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
	: _rawBits(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_rawBits){
	_rawBits = int_rawBits << _fracBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_rawBits){
	_rawBits = roundf(float_rawBits * ( 1<< _fracBits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = other._rawBits;
}

Fixed& Fixed::operator=(const Fixed &other){
	if(this != &other)
		_rawBits= other._rawBits;
	std::cout << "Copy assignment constructor called" << std::endl;
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const{
	return(float)_rawBits / (1 << _fracBits);
}

int Fixed::toInt(void) const {
	return (_rawBits >> _fracBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}