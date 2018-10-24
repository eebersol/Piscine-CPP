#include "SpaceShips.class.hpp"

SpaceShips::SpaceShips() : AEntity()
{
};

SpaceShips::SpaceShips(SpaceShips const & rhs)
{
	*this = rhs;
}

SpaceShips::~SpaceShips()
{
};


SpaceShips &SpaceShips::operator=(SpaceShips const & rhs)
{
	if(this == &rhs)
		return *this;

	return *this;
};

void 	SpaceShips::move(Map & map, Direction d)
{
	if (d == left && get_pos_x() - 1 >= 0)
		set_pos_x(get_pos_x() - 1);
	else if (d == right && get_pos_x() + 1 < GRIDX)
		set_pos_x(get_pos_x() + 1);
	else if (d == bottom && get_pos_y() + 1 <= GRIDY - 1)
		set_pos_y(get_pos_y() + 1);
	else if (d == top && get_pos_y() - 1 >= 0)
		set_pos_y(get_pos_y() - 1);
	map.addEntity(this);
}

bool	SpaceShips::isNextEntities(Map &map, Direction d)
{

	if (d == left && this->get_pos_x() - 1 >= 0)
		return (map.isEntity(this->get_pos_x() - 1, this->get_pos_y()));
	else if (d == right && this->get_pos_x() + 1 < GRIDX)
		return (map.isEntity(this->get_pos_x() + 1, this->get_pos_y()));
	else if (d == bottom && this->get_pos_y() + 1 <= GRIDY - 1)
		return (map.isEntity(this->get_pos_x(), this->get_pos_y() + 1));
	else if (d == top && this->get_pos_y() - 1 >= 0)
		return (map.isEntity(this->get_pos_x(), this->get_pos_y() - 1));
	return (1);
}