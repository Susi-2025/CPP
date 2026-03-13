
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	: _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->_rawBits = other._rawBits;
	return *this;
}
	
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int int_rawBits)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = int_rawBits << _fracBits;
	
}
	
Fixed::Fixed(const float float_rawBits)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(float_rawBits * (1 << _fracBits));
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	float out = _rawBits /(float) (1 << _fracBits);
	return out;
}

int Fixed::toInt(void) const
{
	int out = _rawBits >> _fracBits;
	return out;
}

//comparison operator
bool Fixed::operator>(const Fixed& other) const{
	return _rawBits > other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const{
	return _rawBits >= other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const{
	return _rawBits < other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const{
	return _rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const{
	return _rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const{
	return _rawBits != other._rawBits;
}

//arithmetic operator
Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits + other._rawBits);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_rawBits - other._rawBits);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_rawBits * other._rawBits) >> _fracBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	if (other._rawBits == 0)
	{
		std::cout << "Divide with zero" << std::endl;
		return Fixed(0);
	}
	result.setRawBits((this->_rawBits << _fracBits)/ other._rawBits);
	return result;
}

//increment/decrement operator
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

//min max operator
Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return second;
	else
		return first;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return second;
	else
		return first;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return first;
	else
		return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	if (first.getRawBits() > second.getRawBits())
		return first;
	else
		return second;
}

std::ostream &operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}