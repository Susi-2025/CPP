
#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	std::cout << "-----------STANDARD TEST--------------" <<std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << "-----------EXTRA TEST--------------" <<std::endl;

	Fixed c( Fixed( 6.05f ) / Fixed( 2 ) );
	std::cout << c << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	std::cout << c++ << std::endl;
	std::cout << c << std::endl;

	std::cout << Fixed::min( a, c ) << std::endl;
	std::cout << Fixed::max( b, c ) << std::endl;

	std::cout << std::endl;

	std::cout << "-----------TEST with DIVIDE 0--------------" <<std::endl;
	Fixed d( Fixed( 6.05f ) / Fixed( 0 ) );

	return 0;
}