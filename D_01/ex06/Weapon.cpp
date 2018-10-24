#include "Weapon.hpp"

Weapon::Weapon(std ::string type)
{
	this->type = type;
};

Weapon::~Weapon()
{
};


const std::string Weapon::getType() const
{
	const std::string ttype = this->type;
	return (ttype);

};

void  Weapon::setType(std::string type)
{
	this->type = type;
};