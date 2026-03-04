
#ifndef FIX_HPP
#define FIX_HPP

#include <string>

class Fixed{
	private:
		int _rawBits;
		static const int _fractionalBits = 8;
	public:
		Fixed();
		// Fixed(int num_value, int num_frac_bits);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw);
};

#endif