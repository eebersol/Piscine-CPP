#include "Zombie.hpp"
#include "ZombieHorde.hpp"

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
	ZombieHorde 	*horde;
	Zombie 			*zombie;

	std::cout << std::endl;

	std::cout << " -- Zombie : create and announce ZombieA -- " << std::endl << std::endl;
	zombie 			= new(Zombie);
	zombie->type 	= "sauteur";
	zombie->name.assign("ZombieA");
	zombie->announce();
	delete(zombie);

	std::cout << std::endl;

	std::cout << " -- Zombie Horde : create 10 -- " << std::endl;
	std::cout << std::endl;

	horde 	= new ZombieHorde(10);
	horde->announce();
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

	delete(horde);
}