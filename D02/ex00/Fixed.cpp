#include "Fixed.hpp"

Fixed::Fixed(void) : _integer(0)
{
	std::cout << "Default constructor called." << std::endl;
};

Fixed::Fixed(Fixed const &p2) : _integer(p2._integer)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = p2;
};

Fixed::~Fixed()
{
	std::cout << "Fixed destructor." << std::endl;
};

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_integer);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	std::cout << raw << std::endl;
};

Fixed &Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called."  << std::endl;
	if(this == &rhs)
		return *this;
	this->_integer = rhs.getRawBits();
	return *this;
};