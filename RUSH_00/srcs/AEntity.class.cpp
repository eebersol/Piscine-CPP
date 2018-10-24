# include "AEntity.class.hpp"

AEntity::AEntity(void) : _pos_x(0), _pos_y(0)
{

}

AEntity::AEntity(AEntity const &src)
{
	*this = src;
}

AEntity::~AEntity(void)
{

}

AEntity	&AEntity::operator=(AEntity const &rhs)
{
	(void)rhs;
	return (*this);
}

/* GETTER */
int AEntity::get_pos_x() const {return (this->_pos_x);}
int AEntity::get_pos_y() const {return (this->_pos_y);}
int AEntity::get_color() const {return (this->_color);}
int AEntity::get_level() const {return (this->_level);}
int AEntity::get_score() const {return (this->_score);}
int AEntity::get_life()  const {return (this->_life);}
/* SETTER */
void AEntity::set_color(int value) { this->_color = value; }
void AEntity::set_pos_x(int value) { this->_pos_x = value; }
void AEntity::set_pos_y(int value) { this->_pos_y = value; }
void AEntity::set_level(int value) { this->_level = value; }
void AEntity::set_score(int value) { this->_score = value; }
void AEntity::set_life(int value)  { this->_life  = value; }

