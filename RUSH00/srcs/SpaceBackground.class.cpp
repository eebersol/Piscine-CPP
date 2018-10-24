#include "SpaceBackground.class.hpp"

SpaceBackground::SpaceBackground(void)
{

}

SpaceBackground::SpaceBackground(SpaceBackground const &src)
{
	*this = src;
}

SpaceBackground::~SpaceBackground(void)
{

}

SpaceBackground	&SpaceBackground::operator=(SpaceBackground const &rhs)
{
	(void)rhs;
	return (*this);
}

std::string		SpaceBackground::draw() const
{
	return ("      \n      \n.     ");
}
