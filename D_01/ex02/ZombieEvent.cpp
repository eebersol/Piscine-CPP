#include "ZombieEvent.hpp"
#include "Zombie.hpp"

ZombieEvent::ZombieEvent() {
};

ZombieEvent::~ZombieEvent()
{
};

void ZombieEvent::setZombieType(std::string type)
{	
	this->type = type;
};

Zombie *ZombieEvent::newZombie(std::string name)
{	
	Zombie *newZombie;

	newZombie = new(Zombie);
	newZombie->type = this->type;
	newZombie->name = name;
	return(newZombie);
};
