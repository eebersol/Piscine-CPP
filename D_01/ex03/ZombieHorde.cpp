#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int iteration)
 {
 	Zombie *newZombie;
 	list_zombie = new std::vector<Zombie*>();

 	n = iteration;
	if (iteration < 0)
		std::cout << "Invalid number of zombie" << std::endl;
	else
	{
		for (int i = 0; i < n; i++)
		{
			newZombie = new Zombie;
			newZombie->type = "Basic Horde";
			newZombie->name.assign(randomizeName());
			list_zombie->push_back(newZombie);
		}
	}	
};

ZombieHorde::~ZombieHorde()
{
	Zombie 	*newZombie;

	for (int i = n - 1; i > 0; i--)
	{
		newZombie = list_zombie->at(i);
		delete(newZombie);
	}
	std::cout << "annihilated horde" << std::endl;
};

std::string ZombieHorde::randomizeName(void)
{
	std::string NameArray[10] = { "Budz", "Pain", "Konan", "Nagato", "Itachi", "Tobi", "Madara", "Naruto", "Danzou", "Kakashi" };
	std::string name;

	return NameArray[(0 + (rand() % (int)(9 - 0 + 1)))];
}

void ZombieHorde::announce()
{
	Zombie 	*newZombie;

	for (int i = 0; i < n; i++)
	{
		newZombie = list_zombie->at(i);
		newZombie->announce();
	}
};
