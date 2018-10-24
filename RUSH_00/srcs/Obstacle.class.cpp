#include "Obstacle.class.hpp"

Obstacle::Obstacle(int lvl) : _currLevel(lvl)
{
	this->_refreshTime = clock();
	for (int i = 0; i < 10; i++)
		this->_alive[i] = -1;
}

Obstacle::Obstacle(Obstacle const &src)
{
	*this = src;
}

Obstacle::~Obstacle(void)
{

}

Obstacle	&Obstacle::operator=(Obstacle const &rhs)
{
	this->_currLevel = rhs._currLevel;
	this->_refreshTime = rhs._refreshTime;
	return (*this);
}

bool		Obstacle::checkTime()
{
	clock_t	now = clock();
	float elapsed_secs = (float(now - this->_refreshTime) / CLOCKS_PER_SEC) * 1000;

	if (elapsed_secs > (1100 - (this->_currLevel * 100)))
	{
		this->_refreshTime = now;
		return (true);
	}
	return (false);
}

void		Obstacle::setLevel(int lvl)
{
	this->_currLevel = lvl;
}

void	Obstacle::moveWave(Map &map, Heroes &h, Weapon &w, Wave &wave)
{
	for (int i = 0; i < 10; i++)
	{
		if (this->_alive[i] == -1)
			continue ;
		if (this->_ast[i].get_pos_y() < GRIDY - 1 && this->_ast[i].get_pos_y() >= 0)
			this->_ast[i].set_pos_y(this->_ast[i].get_pos_y() + 1);
		else
		{
			this->_alive[i] = -1;
			continue ;
		}
		if (this->_ast[i].get_pos_x() <= GRIDX - 1 && this->_ast[i].get_pos_x() > 0)
		{
			if (this->_ast[i].get_pos_x() - 1 == h.get_pos_x() &&
				this->_ast[i].get_pos_y() == h.get_pos_y())
				h.hitted(map);
			w.tryRemoveEntity(this->_ast[i].get_pos_x() - 1, this->_ast[i].get_pos_y());
			wave.tryRemoveEntity(this->_ast[i].get_pos_x() - 1, this->_ast[i].get_pos_y());
			this->_ast[i].set_pos_x(this->_ast[i].get_pos_x() - 1);
		}
		else
		{
			this->_alive[i] = -1;
			continue ;
		}
	}

	this->sendAsteroid();
}

void		Obstacle::sendAsteroid()
{
	int i;
	int	nb = this->getNbFreeIndex();

	if ((std::rand() % 100) < ((10 - (10 - nb)) * 7) && (i = this->getFreeIndex()) != -1)
	{
		this->_alive[i] = i;
		this->_ast[i].set_pos_x(GRIDX - 1);
		this->_ast[i].set_pos_y(std::rand() % ((int)(GRIDY / 4) * 3));
	}
}

int		Obstacle::getFreeIndex()
{
	for (int i = 0; i < 10; i++)
	{
		if (this->_alive[i] == -1)
		{
			return (i);
		}
	}
	return (-1);
}

int		Obstacle::getNbFreeIndex()
{
	int		count = 0;

	for (int i = 0; i < 10; i++)
	{
		if (this->_alive[i] == -1)
			++count;
	}
	return (count);
}


bool		Obstacle::tryRemoveEntity(int x, int y)
{
	if (x < 0 || y < 0 || x > GRIDX - 1 || y > GRIDY - 1)
		return (false);
	for (int i = 0; i < 10 ; i++)
	{
		if (this->_alive[i] != -1)
		{
			if (this->_ast[i].get_pos_x() == x &&
				this->_ast[i].get_pos_y() == y)
				return (true);
		}
	}
	return (false);
}

void	Obstacle::setCoordinate(Map &map)
{
	for (int i = 0; i < 10; i++)
		if (this->_alive[i] != -1)
			map.addEntity(&this->_ast[i]);
}
