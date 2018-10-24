#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
	public:
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const &rhs); 
		~NinjaTrap();
		std::string const getName() const;
		NinjaTrap &	operator=(NinjaTrap const & rhs);
		void ninjaShoebox(FragTrap const & target);
		void ninjaShoebox(ScavTrap const & target);
		void ninjaShoebox(NinjaTrap const & target);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		NinjaTrap(void);


};

#endif