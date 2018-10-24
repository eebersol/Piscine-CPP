#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

#include <iostream>
#include <vector>
#include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int iteration);
		~ZombieHorde(void);
		void announce(void);

	private:
		int 					n;
		std::vector<Zombie*> 	*list_zombie;
		std::string randomizeName(void);
};

#endif