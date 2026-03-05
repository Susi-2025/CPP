
#include <iostream>
#ifndef FIXED_HPP
#define	FIXED_HPP

class Fixed{
	private:
		int	_rawBits;
		static const int _fracBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		Fixed(const float float_value);
		Fixed(const int int_value);

		int toInt(void) const;
		float toFloat(void) const;

		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed& operator++(); //pre-increment
		Fixed operator++(int); // post-increment
		Fixed& operator--(); // pre-decrement
		Fixed operator--(int); //post-decrement
		
		static Fixed& min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed& max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);
		
		
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif