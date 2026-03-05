
#include <iostream>
#include <cmath>
#include "Fixed.hpp"

//Constructors and  Destructor
Fixed::Fixed() : _rawBits(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = other._rawBits;
}

Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assigment constructor called" << std::endl;
	this->_rawBits = other._rawBits;
	return *this;
}

Fixed::Fixed(const int int_value){
	std::cout << "Int constructor called" << std::endl;
	_rawBits = int_value << _fracBits;
}

Fixed::Fixed(const float float_value){
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(float_value *(1 << _fracBits));
}

// Conversion functions
int Fixed::toInt(void) const{
	return (_rawBits >> _fracBits);
}

float Fixed::toFloat(void) const{
	return (float)(_rawBits) /(1 << _fracBits);
}

// Comparison operator
bool Fixed::operator>(const Fixed &other) const{
	return (this->_rawBits > other._rawBits);
}

bool Fixed::operator>=(const Fixed &other) const{
	return (this->_rawBits >= other._rawBits);
}

bool Fixed::operator<(const Fixed &other) const{
	return (this->_rawBits < other._rawBits);
}

bool Fixed::operator<=(const Fixed &other) const{
	return (this->_rawBits <= other._rawBits);
}

bool Fixed::operator==(const Fixed &other) const{
	return (this->_rawBits == other._rawBits);
}

bool Fixed::operator!=(const Fixed &other) const{
	return (this->_rawBits != other._rawBits);
}

//Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const{
	Fixed out;
	out._rawBits = this->_rawBits + other._rawBits;
	return (out);
}

Fixed Fixed::operator-(const Fixed &other) const{
	Fixed out;
	out._rawBits = this->_rawBits - other._rawBits;
	return out;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed out;
	out._rawBits = (this->_rawBits * other._rawBits) >> _fracBits;
	return (out);
}

Fixed Fixed::operator/(const Fixed &other) const{
	if (other._rawBits == 0){
		std::cout<< "Error: division by zero" << std::endl;
		return Fixed(0);
	}
	Fixed out;
	out._rawBits = (this->_rawBits << _fracBits) / other._rawBits;
	return out;
}

//Increment/Decrement operators

Fixed& Fixed::operator++(){
	this->_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed temp(*this);
	this->_rawBits++;
	return temp;
}

Fixed& Fixed::operator--(){
	this->_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed temp(*this);
	this->_rawBits--;
	return temp;
}

// Min/Max functions
Fixed& Fixed::min(Fixed& fixed1, Fixed& fixed2){
	if (fixed1._rawBits < fixed2._rawBits)
		return (fixed1);
	else
		return (fixed2);
}

const Fixed& Fixed::min(const Fixed& fixed1, const Fixed& fixed2){
	if (fixed1._rawBits < fixed2._rawBits)
		return (fixed1);
	else
		return (fixed2);
}

Fixed& Fixed::max(Fixed& fixed1, Fixed& fixed2){
	if (fixed1._rawBits > fixed2._rawBits)
		return (fixed1);
	else
		return (fixed2);
}

const Fixed& Fixed::max(const Fixed& fixed1, const Fixed& fixed2){
	if (fixed1._rawBits > fixed2._rawBits)
		return (fixed1);
	else
		return (fixed2);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	out << fixed.toFloat();
	return out;
}