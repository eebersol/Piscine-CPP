#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & rhs); 
		~FragTrap();
		FragTrap &	operator=(FragTrap const & rhs);
		void vaulthunter_dot_execlang__(std::string const & target);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		FragTrap(void);
		void gunWizard(std::string const &target);
		void oneShotWonder(std::string const &target);
		void laserInferno(std::string const &target);
		void boomTrap(std::string const &target);
		void fragmentedFragTrap(std::string const &target);
};

#endif