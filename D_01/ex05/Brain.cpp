#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "In Brain constructor" << std::endl;
	set_adress();
};

Brain::~Brain()
{
	std::cout << "In Brain destructor" << std::endl;
};

void Brain::set_adress()
{
	std::stringstream ss;
	void *a = (this);

	ss << a;  
	this->adress = ss.str();
};

std::string Brain::identify()
{
	return(this->adress);
}
