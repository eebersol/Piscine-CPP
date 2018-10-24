#include "Asteroid.class.hpp"

Asteroid::Asteroid(void)
{

}

Asteroid::Asteroid(Asteroid const &src)
{
	*this = src;
}

Asteroid::~Asteroid(void)
{

}

Asteroid	&Asteroid::operator=(Asteroid const &rhs)
{
	(void)rhs;
	return (*this);
}

std::string		Asteroid::draw() const
{
	return (" /-~-\\\n{    }\n\\-^-/ ");
}

