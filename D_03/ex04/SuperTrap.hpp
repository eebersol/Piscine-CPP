#ifndef SuperTrap_HPP
#define SuperTrap_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, NinjaTrap
{
	public:
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const & rhs); 
		~SuperTrap();
		SuperTrap &	operator=(SuperTrap const & rhs);
		std::string const getName() const;
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(std::string const & target);
	private:
		SuperTrap(void);
};

#endif