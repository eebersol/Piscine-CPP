#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): Aweapon(weapon), Aname(name)
{

};

HumanA::~HumanA()
{
};

void HumanA::attack()
{
	std::cout << this->Aname << " attacks with his " << this->Aweapon.getType() << std::endl;
}