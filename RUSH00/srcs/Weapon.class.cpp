#include "Weapon.class.hpp"

Weapon::Weapon(float speed)
{
	this->_refreshTime = clock();
	this->_delayRound = speed;
	for (int i = 0; i < 100; i++)
		this->_alive[i] = -1;
}

Weapon::Weapon(Weapon const &src)
{
	*this = src;
}

Weapon::~Weapon(void)
{

}

Weapon	&Weapon::operator=(Weapon const &rhs)
{
	(void)rhs;
	return (*this);
}

int		Weapon::getNbFreeIndex()
{
	int		count = 0;

	for (int i = 0; i < 10; i++)
		if (this->_alive[i] == -1)
			++count;
	return (count);
}

int  Weapon::getFreeIndex()
{
	for (int i = 0; i < 100; i++)
		if (this->_alive[i] == -1)
			return (i);
	return (-1);
}


void Weapon::newBullet(std::string name, float _speed, int posX, int posY)
{
	int i;

	i = this->getFreeIndex();
	if (getNbFreeIndex() >= 1)
	{
		this->_bullet[i].set_pos_x(posX);
		this->_bullet[i].set_pos_y(posY);
		this->_bullet[i].set_name(name);
		this->_bullet[i].set_speed(_speed);
		this->_bullet[i].set_damage(100);
		if (name == "Heroes")
			this->_bullet[i].set_color(2);
		else
			this->_bullet[i].set_color(4);
		_alive[i] = 1;
		_nbSent++;
	}
}

void Weapon::moveBullet(Map &map)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_bullet[i].get_pos_y() - 1 >= 0 && this->_alive[i] != -1 && this->_bullet[i].get_name() == "Heroes")
		{
			this->_bullet[i].set_pos_y(this->_bullet[i].get_pos_y() - 1);
			map.addEntity(&this->_bullet[i]);
		}
		else if (this->_bullet[i].get_pos_y() + 1 < GRIDY && this->_alive[i] != -1 && this->_bullet[i].get_name() == "Enemy")
		{
			this->_bullet[i].set_pos_y(this->_bullet[i].get_pos_y() + 1);
			map.addEntity(&this->_bullet[i]);
		}
		else
			this->_alive[i] = -1;
	}

}

void	Weapon::setCoordinate(Map &map)
{
	for (int i = 0; i < 10; i++)
		if (this->_alive[i] != -1)
			map.addEntity(&this->_bullet[i]);
}

bool	Weapon::checkTime()
{
	clock_t	now = clock();
	float elapsed_secs = (float(now - this->_refreshTime) / CLOCKS_PER_SEC) * 1000;

	if (elapsed_secs > this->_delayRound)
	{
		this->_refreshTime = now;
		return (true);
	}
	return (false);
}

bool	Weapon::isAllDead()
{
	return (this->_nbSent == 100 && this->getNbFreeIndex() == 100);
}

void	Weapon::checkColison(Wave &wave, Heroes &h, Obstacle &obs)
{
	for (int i = 0; i < 100; i++)
	{
		if (this->_alive[i] != -1 && this->_bullet[i].get_pos_y() > 0 && this->_bullet[i].get_name() == "Heroes")
		{
			if (obs.tryRemoveEntity(this->_bullet[i].get_pos_x(), this->_bullet[i].get_pos_y() - 1))
				this->_alive[i] = -1;
			if (wave.tryRemoveEntity(this->_bullet[i].get_pos_x(), this->_bullet[i].get_pos_y() - 1))
			{
				h.set_score(h.get_score() + 10);
				this->_alive[i] = -1;
			}
		}
		if (this->_alive[i] != -1 && this->_bullet[i].get_pos_y() > 0 && this->_bullet[i].get_name() == "Enemy")
		{
			if (wave.tryRemoveEntity(this->_bullet[i].get_pos_x(), this->_bullet[i].get_pos_y() + 1))
				this->_alive[i] = -1;
			if (obs.tryRemoveEntity(this->_bullet[i].get_pos_x(), this->_bullet[i].get_pos_y() + 1))
				this->_alive[i] = -1;
			else if (h.tryRemoveEntity(this->_bullet[i].get_pos_x(), this->_bullet[i].get_pos_y() + 1))
			{
				h.set_life(h.get_life() - 1);	
				this->_alive[i] = -1;
			}
		}
	}
}

Bullet	Weapon::getBullet(int index)
{
	return (this->_bullet[index]);
}

bool	Weapon::tryRemoveEntity(int x, int y)
{
	if (x < 0 || y < 0 || x > GRIDX - 1 || y > GRIDY - 1)
		return (false);
	for (int i = 0;i < 10; i++)
	{
		if (this->_alive[i] != -1)
		{
			if (this->_bullet[i].get_pos_x() == x &&
				this->_bullet[i].get_pos_y() == y)
			{
				this->_alive[i] = -1;
				return (true);
			}
		}
	}
	return (false);
}