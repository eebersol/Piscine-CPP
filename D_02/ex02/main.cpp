#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	bool test;

	Fixed a1(12);
	Fixed a2(12);
	Fixed b1(3);
	Fixed b2(3);
	Fixed a;
	Fixed aa(10.1f);
	Fixed bb(10.2f);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << aa / bb<< std::endl;
	std::cout << aa + bb<< std::endl;
	std::cout << aa * bb<< std::endl;
	std::cout << aa - bb<< std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	test = a == b;
	std::cout << test << std::endl;


	std::cout << "Test :  > && < " << std::endl;
	std::cout << "B : ";
	std::cout << b << std::endl;
	std::cout << "12 > b ?" << std::endl;
	test = a1 > b;
	std::cout << test << std::endl;
	std::cout << "3 > b ?" << std::endl;
	test = b1 > b;
	std::cout << test << std::endl;
	std::cout << "A : ";
	std::cout << a << std::endl;
	std::cout << "12 < a ?" << std::endl;
	test = a1 < b;
	std::cout << test << std::endl;
	std::cout << "3 < a ?" << std::endl;
	test = b1 < b;
	std::cout << test << std::endl;


	std::cout << "Test :  >= && <= " << std::endl;
	std::cout << "B : ";
	std::cout << b2 << std::endl;
	std::cout << "12 >= b2 ?" << std::endl;
	test = a1 >= b2;
	std::cout << test << std::endl;
	std::cout << "3 >= b2 ?" << std::endl;
	test = b1 >= b2;
	std::cout << test << std::endl;
	
	std::cout << "A : ";
	std::cout << a2 << std::endl;
	std::cout << "12 <= a2 ?" << std::endl;
	test = a1 <= b2;
	std::cout << test << std::endl;
	std::cout << "3 <= a2 ?" << std::endl;
	test = b1 <= b2;
	std::cout << test << std::endl;
	return 0;
}