
#include <iostream>
#include "Fix.hpp"

Fixed::Fixed() : _rawBits(0){
	std::cout << "Default Constructor Called" << std::endl;
}

// Fixed::Fixed(int num_value, int num_frac_bits){
// 	_num_value = num_value;
// 	_num_frac_bits = num_frac_bits;
// 	std::cout << "Fixed Parameterized Constructor Called" << std::endl;
// }

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