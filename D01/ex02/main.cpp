#include "Zombie.hpp"
#include "ZombieEvent.hpp"

void 	randomChump()
{
	Zombie newZombie;
	std::string name;
	std::string NameArray[10] = { "Budz", "Pain", "Konan", "Nagato", "Itachi", "Tobi", "Madara", "Naruto", "Danzou", "Kakashi" };

	newZombie.name = name.assign(NameArray[(0 + (rand() % (int)(9 - 0 + 1)))]);
	newZombie.announce();
}

int main(void)
{
	ZombieEvent 	*eventZombie;
	Zombie 			*zombie;

	std::cout << std::endl;

	std::cout << " -- Zombie : create and announce ZombieA -- " << std::endl << std::endl;
	zombie 			= new(Zombie);
	zombie->type 	= "sauteur";
	zombie->name.assign("ZombieA");
	zombie->announce();
	delete(zombie);

	std::cout << std::endl;

	std::cout << " -- Zombie Event : newZombie -- " << std::endl;
	std::cout << std::endl;

	eventZombie 	= new(ZombieEvent);

	eventZombie->setZombieType("poilus");
	zombie = eventZombie->newZombie("ZombieB");
	zombie->announce();
	std::cout << "zombie B created with type : " << zombie->type << std::endl;
	delete(zombie);
	
	std::cout << std::endl;

	eventZombie->setZombieType("enrage");
	zombie 		= eventZombie->newZombie("ZombieC");
	zombie->announce();
	std::cout << "zombie C created with type : " << zombie->type << std::endl;
	delete(zombie);
	delete(eventZombie);

	std::cout << std::endl;

	std::cout << " -- Create random zombie on the stack. -- " << std::endl;
	std::cout << std::endl << "Random 1 : ";
	randomChump();
	std::cout << std::endl << "Random 2 : ";
	randomChump();
	std::cout << std::endl << "Random 3 : ";
	randomChump();
	std::cout << std::endl << "Random 4 : ";
	randomChump();
	std::cout << std::endl << "Random 5 : ";
	randomChump();
	std::cout << std::endl;


}