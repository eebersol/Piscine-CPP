#include "Zombie.hpp"

Zombie::Zombie() {
	type = "random";
};

Zombie::~Zombie()
{
	std::cout << "Zombie : " << name << " die." << std::endl;
};

void Zombie::announce()
{	
	std::cout << "<" <<  name << " (" << type << ")> Braiiiiiiinnnssss..." << std::endl;
};
