#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent {

	public:
		ZombieEvent();
		~ZombieEvent();
		void setZombieType(std::string);
		Zombie* newZombie(std::string name);
	
	private:
		std::string type;
};

#endif