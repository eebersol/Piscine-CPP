#include "Fixed.hpp"

const int Fixed::static_integer = 8;

Fixed::Fixed(void) : _integer(0)
{
};

Fixed::Fixed(const int integer): _integer(integer << static_integer)
{
	_integer = integer << static_integer;
};

Fixed::Fixed(const float floating): _integer(roundf(floating * (1 << static_integer)))
{	
};

Fixed::Fixed(Fixed const &p2) : _integer(p2._integer)
{	
	*this = p2;
};

Fixed::~Fixed()
{
};

int Fixed::getRawBits(void) const
{
	return (this->_integer);
}

void Fixed::setRawBits(int const raw)
{
	this->_integer = raw;
};

int Fixed::toInt(void) const
{
	return (int)(_integer) >> static_integer;
};

float Fixed::toFloat(void) const
{
	return (float)(this->_integer) / (1 << static_integer);
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


/* Comparaison operator */
bool Fixed::operator>(Fixed const & rhs) const {
	return (this->_integer > rhs._integer);
};

bool Fixed::operator<(Fixed const & rhs) const {
	return (this->_integer < rhs._integer);
};

bool Fixed::operator>=(Fixed const & rhs) const {
	return (this->_integer >= rhs.getRawBits());
};

bool Fixed::operator<=(Fixed const & rhs) const {
	return (this->_integer <= rhs.getRawBits());
};

bool Fixed::operator==(Fixed const & rhs) const {
	return (this->_integer == rhs.getRawBits());
};

bool Fixed::operator!=(Fixed const & rhs) const {
	return !(this->_integer == rhs.getRawBits());
};


/* arithmetic operator */
Fixed Fixed::operator+(Fixed const & rhs) const{
	Fixed tmp;

	tmp.setRawBits(this->_integer + rhs.getRawBits());
	return (tmp);
};

Fixed Fixed::operator-(Fixed const & rhs) const {
	Fixed tmp;

	tmp.setRawBits(this->_integer - rhs.getRawBits());
	return (tmp);
};

Fixed Fixed::operator*(Fixed const & rhs) const {
	Fixed tmp;

	tmp.setRawBits(this->_integer * rhs.getRawBits());
	tmp._integer = tmp.toFloat();
	return (tmp);
};

Fixed Fixed::operator/(Fixed const & rhs) const {
	Fixed tmp;

	tmp.setRawBits(this->_integer / rhs.getRawBits());
	tmp._integer = tmp.toFloat();
	return (tmp);
};

/* increment operator */
Fixed 	 Fixed::operator++(int){
	Fixed ret(*this);
	this->operator++();
	return ret;
};

Fixed 	& Fixed::operator++(){
	this->_integer += 1;
	return *this;
};

Fixed 	 Fixed::operator--(int){
	Fixed ret(*this);
	this->operator--();
	return ret; 
};

Fixed 	& Fixed::operator--(){
	this->_integer -= 1;
	return *this;
};

/* No-member function */

Fixed	const & Fixed::min(Fixed const & lhs, Fixed const & rhs){
	if (lhs.operator<(rhs))
		return (lhs);
	else
		return(rhs);
};

Fixed	const & Fixed::max(Fixed const & lhs, Fixed const & rhs){
	if (lhs.operator>(rhs))
		return (lhs);
	else
		return(rhs);
};

