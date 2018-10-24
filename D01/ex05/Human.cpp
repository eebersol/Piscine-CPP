#include "Human.hpp"

Human::Human()
{
	Brain *brain;
	this->brain = new Brain;
};

Human::~Human()
{
};

std::string Human::identify()
{
	return ((this->brain->identify()));
}

Brain 	Human::getBrain()
{
	return (*this->brain);
}