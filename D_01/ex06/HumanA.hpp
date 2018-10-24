#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <sstream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();

	private:
		Weapon &Aweapon;
		std::string Aname;
};

#endif