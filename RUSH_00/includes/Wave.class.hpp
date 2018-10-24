#ifndef WAVE_H
# define WAVE_H

#include "Enemy.class.hpp"
#include "Heroes.class.hpp"
#include "Weapon.class.hpp"
#include "Obstacle.class.hpp"

class Weapon;

class Wave
{

private:

	Enemy		_enemy[10];
	int			_alive[10];
	int			_nbSent;
	clock_t		_refreshTime;
	clock_t		_refreshTimeRound;
	int			_currLevel;

public:

	Wave(void);
	Wave(int lvl);
	Wave(Wave const &src);
	~Wave(void);
	Wave	&operator=(Wave const &rhs);

	void	moveWave(Map &map, Heroes &h, Weapon &w, Obstacle &obs);
	bool	checkTime();
	bool	checkTimeRound();
	void	setCoordinate(Map &map);
	int		getFreeIndex();
	int		getNbFreeIndex();
	bool	isAllDead();
	bool	isEntity(int x, int y);
	bool	tryRemoveEntity(int x, int y);
	void	setLevel(int lvl);

	void	sendOne();
	void	sendTwo();
	void	sendThree();

};

#endif
