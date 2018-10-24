#include "Wave.class.hpp"

Wave::Wave(void) : _nbSent(0), _currLevel(1)
{
	this->_refreshTime = clock();
	this->_refreshTimeRound = clock();
	for (int i = 0; i < 10; i++)
		this->_alive[i] = -1;
}

Wave::Wave(int lvl) : _nbSent(0), _currLevel(lvl)
{
	this->_refreshTime = clock();
	this->_refreshTimeRound = clock();
	for (int i = 0; i < 10; i++)
		this->_alive[i] = -1;
}


Wave::Wave(Wave const &src)
{
	*this = src;
}

Wave::~Wave(void)
{

}

Wave	&Wave::operator=(Wave const &rhs)
{
	(void)rhs;
	return (*this);
}

bool	Wave::checkTime()
{
	clock_t	now = clock();
	float elapsed_secs = (float(now - this->_refreshTime) / CLOCKS_PER_SEC) * 1000;

	if (elapsed_secs > (950 - (this->_currLevel * 90)))
	{
		this->_refreshTime = now;
		return (true);
	}
	return (false);
}

bool	Wave::checkTimeRound()
{
	clock_t	now = clock();
	float elapsed_secs = (float(now - this->_refreshTimeRound) / CLOCKS_PER_SEC) * 1000;

	if (elapsed_secs > (1700 - (this->_currLevel * 100)))
	{
		this->_refreshTimeRound = now;
		return (true);
	}
	return (false);
}

void	Wave::moveWave(Map &map, Heroes &h, Weapon &w, Obstacle &obs)
{
	int		ret;

	for (int i = 0; i < 10; i++)
	{
		if (this->_alive[i] == -1)
			continue ;
		if (this->_enemy[i].get_pos_y() < GRIDY - 1)
		{
			if (this->_enemy[i].get_pos_x() == h.get_pos_x() &&
				this->_enemy[i].get_pos_y() + 1 == h.get_pos_y())
				h.hitted(map);
			if (w.tryRemoveEntity(this->_enemy[i].get_pos_x(), this->_enemy[i].get_pos_y() + 1))
			{
				h.set_score(h.get_score() + 10);
				this->_alive[i] = -1;
				continue ;
			}
			this->_enemy[i].set_pos_y(this->_enemy[i].get_pos_y() + 1);
		}
		else
		{
			this->_alive[i] = -1;
			continue ;
		}
		ret = std::rand() % 4;
		if (!ret)
		{
			if (this->_enemy[i].get_pos_x() - 1 == h.get_pos_x() &&
				this->_enemy[i].get_pos_y() == h.get_pos_y())
				h.hitted(map);
			else if (w.tryRemoveEntity(this->_enemy[i].get_pos_x() - 1, this->_enemy[i].get_pos_y()) || 
					obs.tryRemoveEntity(this->_enemy[i].get_pos_x() - 1, this->_enemy[i].get_pos_y()))
				this->_alive[i] = -1;
			else
			{
				if (!(std::rand() % 2))
				{
					w.newBullet("Enemy", 50, this->_enemy[i].get_pos_x(), this->_enemy[i].get_pos_y());
					w.checkColison(*this, h, obs);
					w.moveBullet(map);
				}
				this->_enemy[i].move(map, left);
			}
		}
		else if (ret == 1)
		{
			if (this->_enemy[i].get_pos_x() + 1 == h.get_pos_x() &&
				this->_enemy[i].get_pos_y() == h.get_pos_y())
				h.hitted(map);
			if (w.tryRemoveEntity(this->_enemy[i].get_pos_x() + 1, this->_enemy[i].get_pos_y()) || 
					obs.tryRemoveEntity(this->_enemy[i].get_pos_x() + 1, this->_enemy[i].get_pos_y()))
				this->_alive[i] = -1;
			else
			{
				if (!(std::rand() % 2))
				{
					w.newBullet("Enemy", 50, this->_enemy[i].get_pos_x(), this->_enemy[i].get_pos_y());
					w.checkColison(*this, h, obs);
					w.moveBullet(map);
				}
				this->_enemy[i].move(map, right);
			}
		}
		else
			map.addEntity(&this->_enemy[i]);
	}

	if (this->checkTimeRound() && this->_nbSent < 10)
	{
		ret = std::rand() % 3;
		if (!ret)
			this->sendTwo();
		else if (ret == 1)
			this->sendOne();
		else
			this->sendThree();
		this->setCoordinate(map);
	}
}

void	Wave::setCoordinate(Map &map)
{
	for (int i = 0; i < 10; i++)
		if (this->_alive[i] != -1)
			map.addEntity(&this->_enemy[i]);
}

int		Wave::getFreeIndex()
{
	for (int i = 0; i < 10; i++)
		if (this->_alive[i] == -1)
			return (i);
	return (-1);
}

int		Wave::getNbFreeIndex()
{
	int		count = 0;

	for (int i = 0; i < 10; i++)
		if (this->_alive[i] == -1)
			++count;
	return (count);
}

void	Wave::sendOne()
{
	if (this->getNbFreeIndex() < 1)
		return ;
	int		index = this->getFreeIndex();
	this->_alive[index] = index;
	this->_enemy[index].set_pos_x(GRIDX / 2);
	this->_enemy[index].set_pos_y(0);
	this->_nbSent++;
}

void	Wave::sendTwo()
{
	if (this->getNbFreeIndex() < 2)
		return ;
	int		index = this->getFreeIndex();
	this->_alive[index] = index;
	this->_enemy[index].set_pos_x(GRIDX / 4);
	this->_enemy[index].set_pos_y(0);

	index = this->getFreeIndex();
	this->_alive[index] = index;
	this->_enemy[index].set_pos_x((GRIDX / 4) * 3);
	this->_enemy[index].set_pos_y(0);
	this->_nbSent += 2;
}

void	Wave::sendThree()
{

	if (this->getNbFreeIndex() < 3)
		return ;
	int		index = this->getFreeIndex();
	this->_alive[index] = index;
	this->_enemy[index].set_pos_x(GRIDX / 4);
	this->_enemy[index].set_pos_y(0);

	index = this->getFreeIndex();
	this->_alive[index] = index;
	this->_enemy[index].set_pos_x((GRIDX / 4) * 2);
	this->_enemy[index].set_pos_y(0);

	index = this->getFreeIndex();
	this->_alive[index] = index;
	this->_enemy[index].set_pos_x((GRIDX / 4) * 3);
	this->_enemy[index].set_pos_y(0);
	this->_nbSent += 3;
}

bool	Wave::isAllDead()
{
	return (this->_nbSent >= 10 && this->getNbFreeIndex() == 10);
}

bool	Wave::isEntity(int x, int y)
{
	for (int i = 0;i < 10; i++)
	{
		if (this->_alive[i] != -1)
		{
			if (this->_enemy[i].get_pos_x() == x &&
				this->_enemy[i].get_pos_y() == y)
				return (true);
		}
	}
	return (false);
}

bool	Wave::tryRemoveEntity(int x, int y)
{
	if (x < 0 || y < 0 || x > GRIDX - 1 || y > GRIDY - 1)
		return (false);
	for (int i = 0;i < 10; i++)
	{
		if (this->_alive[i] != -1)
		{
			if (this->_enemy[i].get_pos_x() == x &&
				this->_enemy[i].get_pos_y() == y)
			{
				this->_alive[i] = -1;
				return (true);
			}
		}
	}
	return (false);
}

void	Wave::setLevel(int lvl)
{
	this->_currLevel = lvl;
}
