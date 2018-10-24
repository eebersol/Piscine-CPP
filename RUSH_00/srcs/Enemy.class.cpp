#include "Enemy.class.hpp"

Enemy::Enemy() : SpaceShips()
{
	set_color(6);
};

Enemy::Enemy(Enemy const & rhs)
{
	*this = rhs;
}

Enemy::~Enemy()
{
};

Enemy &Enemy::operator=(Enemy const & rhs)
{
	(void)rhs;
	return (*this);
};


std::string Enemy::draw() const
{
	return "|    |\n|====|\n|    |";

}

