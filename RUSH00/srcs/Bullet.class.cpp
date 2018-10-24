#include "Bullet.class.hpp"

Bullet::Bullet()
{
};

Bullet::Bullet(Map &map, std::string name, int damage, int color, float speed, int posX, int posY)
{
	this->_refreshTimeBullet = clock();
	_name 	= name;
	_damage = damage;
	_color 	= color;
	this->_delayBullet 	=  speed;
	set_pos_x(posX);
	set_pos_y(posY);
	set_color(color);
	map.addEntity(this);
}

Bullet::Bullet(Bullet const & rhs)
{
	*this = rhs;
}

Bullet::~Bullet()
{

};

Bullet &Bullet::operator=(Bullet const & rhs)
{
	this->_posY = rhs._posY;
	this->_posX = rhs._posX;
	this->_name = rhs._name;
	this->_damage = rhs._damage;
	this->_speed = rhs._speed;
	this->_delayBullet = rhs._delayBullet;
	this->_refreshTimeBullet = rhs._refreshTimeBullet;
	return (*this);
};

std::string Bullet::draw() const
{
	if (this->get_name() == "Heroes")
		return "  42  \n      \n      ";
	else
		return "|     \n      \n     |";

}


/* SETTER */
void Bullet::set_name(std::string value) {this->_name = value;};
void Bullet::set_alive(int value) {this->_alive[value] = 1;};
void Bullet::set_damage(int value) {this->_damage = value;};
void Bullet::set_speed(float value)  {this->_speed = value;};
void Bullet::set_refreshTimeBullet()  {this->_refreshTimeBullet = clock();};
/* GETTER */
std::string Bullet::get_name(void) const {return this->_name;};
int Bullet::get_damage(void) const {return this->_damage;};
int Bullet::get_color(void) const {return this->_color;};
float Bullet::get_speed(void) const {return this->_delayBullet;};
