#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include <sstream> //for std::stringstream 
#include <string>  //for std::string
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const char *name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);

	private:
		Weapon *weapon;
		std::string Bname;
};

#endif