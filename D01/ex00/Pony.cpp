#include "Pony.hpp"

Pony::Pony(std::string name, int poid)
{
	this->name = name;
	this->poid = poid;
};

Pony::~Pony()
{
	std::cout << "Pony " << this->name << " die" << std::endl;
};

void Pony::run(void)
{	
	std::cout << "Pony " << this->name << " run" << std::endl;
};


void Pony::sleep(void)
{	
	std::cout << "Pony " << this->name << " sleep" << std::endl;
};


void Pony::eat(void)
{
	if (this->poid < 200)
		std::cout << "Pony " << this->name << " eat" << std::endl;
	else
		std::cout << "Pony " << this->name << "sre too fat to eat" << std::endl;
}

