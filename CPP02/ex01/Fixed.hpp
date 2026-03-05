#include <iostream>
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
	private:
		int _rawBits;
		static const int _fracBits = 8;
	public:
		Fixed();
		Fixed(const int int_rawBits);
		Fixed(const float float_rawBits);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		
		~Fixed();
		float toFloat( void ) const;
		int toInt( void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif