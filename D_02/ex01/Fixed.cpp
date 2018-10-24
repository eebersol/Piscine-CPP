#include "Fixed.hpp"

const int Fixed::static_integer = 8;

Fixed::Fixed(void) : _integer(0)
{
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int integer): _integer(integer << static_integer)
{
	_integer = integer << static_integer;
	std::cout << "Int constructor called" << _integer <<  std::endl;
};

Fixed::Fixed(const float floating): _integer(roundf(floating * (1 << static_integer)))
{	
	std::cout << "Float constructor called" << std::endl;
};

Fixed::Fixed(Fixed const &p2) : _integer(p2._integer)
{	
	std::cout << "Copy constructor called" << std::endl;
	*this = p2;
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits(void) const
{
	return (this->_integer);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << raw << std::endl;
};

int Fixed::toInt(void) const
{
	return (int)(_integer) >> static_integer;
};

float Fixed::toFloat(void) const
{
	return (float)(_integer) / (1 << static_integer);
};


Fixed &Fixed::operator=(Fixed const & rhs)
{
     if(this == &rhs)
        return *this;
     this->_integer = rhs.getRawBits();
     return *this;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
};