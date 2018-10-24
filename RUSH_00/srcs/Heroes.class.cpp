#include "Heroes.class.hpp"

Heroes::Heroes()
{
};


Heroes::Heroes(int pos_y, int pos_x)
{
	set_pos_y(pos_y);
	set_pos_x(pos_x);
	set_score(0);
	set_life(3);
	set_level(1);
	set_color(6);
}

Heroes::Heroes(Heroes const & rhs)
{
	*this = rhs;
}

Heroes::~Heroes()
{

};

Heroes &Heroes::operator=(Heroes const & rhs)
{
	if (this == &rhs)
		return (*this);
	this->_pos_x = rhs.get_pos_x();
	this->_pos_y = rhs.get_pos_y();
	return (*this);
};


std::string Heroes::draw() const
{
	return " .''. \n.'oo'.\n|.--.|\n";

}

void Heroes::hitted(Map &map)
{
	this->set_pos_x((GRIDX / 2) - 1);
	this->set_pos_y(GRIDY - 2);
	this->set_life(this->get_life() - 1);
	map.addEntity(this);
}


bool	Heroes::tryRemoveEntity(int x, int y)
{
	if (x < 0 || y < 0 || x > GRIDX - 1 || y > GRIDY - 1)
		return (false);
	for (int i = 0;i < 10; i++)
	{

			if (this->get_pos_x() == x &&
				this->get_pos_y() == y)
			{
				return (true);
			}
	}
	return (false);
}
