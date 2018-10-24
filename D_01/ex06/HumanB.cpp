#include "HumanB.hpp"

HumanB::HumanB(const char *name): Bname(name)
{
};

HumanB::~HumanB()
{
};

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << this->Bname << " attacks with his " << this->weapon->type << std::endl;
}