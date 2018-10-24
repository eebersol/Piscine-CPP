#include "Background.class.hpp"

Background::Background(void)
{
	this->_refreshTime = clock();
	this->_bg[0].set_pos_x(1);
	this->_bg[0].set_pos_y(2);
	
	this->_bg[1].set_pos_x(3);
	this->_bg[1].set_pos_y(20);
	
	this->_bg[2].set_pos_x(5);
	this->_bg[2].set_pos_y(8);
	
	this->_bg[3].set_pos_x(8);
	this->_bg[3].set_pos_y(17);
	
	this->_bg[4].set_pos_x(11);
	this->_bg[4].set_pos_y(1);

	this->_bg[5].set_pos_x(13);
	this->_bg[5].set_pos_y(11);

	this->_bg[6].set_pos_x(16);
	this->_bg[6].set_pos_y(5);

	this->_bg[7].set_pos_x(18);
	this->_bg[7].set_pos_y(21);
}

Background::Background(Background const &src)
{
	*this = src;
}
Background::~Background(void)
{

}

Background	&Background::operator=(Background const &rhs)
{
	(void)rhs;
	return (*this);
}
bool	Background::checkTime()
{
	clock_t	now = clock();
	float elapsed_secs = (float(now - this->_refreshTime) / CLOCKS_PER_SEC) * 1000;

	if (elapsed_secs > 20)
	{
		this->_refreshTime = now;
		return (true);
	}
	return (false);
}

void		Background::move()
{
	for (int i = 0; i < 8; i++)
	{
		if (this->_bg[i].get_pos_y() < GRIDY - 1)
			this->_bg[i].set_pos_y(this->_bg[i].get_pos_y() + 1);
		else
			this->_bg[i].set_pos_y(0);
	}
}

void		Background::setCoordinate(Map &map)
{
	for (int i = 0; i < 8; i++)
	{
		if (map.isEntity(this->_bg[i].get_pos_x(), this->_bg[i].get_pos_y()) == false)
			map.addEntity(&this->_bg[i]);
	}
}