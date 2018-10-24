#ifndef WEAPON_H
# define WEAPON_H

#include "Bullet.class.hpp"
#include "SpaceShips.class.hpp"
#include "Wave.class.hpp"
#include "Heroes.class.hpp"
#include "Obstacle.class.hpp"

class Wave;

class Obstacle;

class Weapon
{

private:

	Bullet		_bullet[100];
	int			_alive[100];
	int			_nbSent;
	float		_delayRound;
	clock_t		_refreshTime;

public:

	Weapon(float _speed);
	Weapon(Weapon const &src);
	~Weapon(void);
	Weapon	&operator=(Weapon const &rhs);

	void newBullet(std::string name, float _speed, int posX, int posY);
	void moveBullet(Map &map);
	void setCoordinate(Map &map);
	int getFreeIndex();
	int getNbFreeIndex();
	Bullet	getBullet(int index);
	bool isAllDead();
	bool checkTime();
	void	checkColison(Wave &wave, Heroes &heroes, Obstacle &obstacle);
	bool	tryRemoveEntity(int x, int y);

};

#endif
