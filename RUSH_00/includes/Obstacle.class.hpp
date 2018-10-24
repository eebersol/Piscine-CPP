#ifndef OBSTACL_H
# define OBSTACL_H

# include "Asteroid.class.hpp"
# include "Map.class.hpp"
# include "Wave.class.hpp"

class Wave;
class Weapon;

class Obstacle
{

private:

	Asteroid	_ast[10];
	int			_alive[10];
	int			_currLevel;
	clock_t		_refreshTime;

public:

	Obstacle(int lvl);
	Obstacle(Obstacle const &src);
	~Obstacle(void);
	Obstacle	&operator=(Obstacle const &rhs);

	void		setLevel(int lvl);
	bool		checkTime();
	int		getFreeIndex();
	int		getNbFreeIndex();
	bool	tryRemoveEntity(int x, int y);
	void	moveWave(Map &map, Heroes &h, Weapon &w, Wave &wave);

	void	sendAsteroid();
	void	setCoordinate(Map &map);

};

#endif
