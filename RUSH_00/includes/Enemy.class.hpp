#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "SpaceShips.class.hpp"

class Enemy : public SpaceShips
{
	public:
		Enemy();
		Enemy(Enemy const & rhs);
		virtual ~Enemy();
		Enemy &operator=(Enemy const & rhs);
		virtual std::string draw() const;

};

#endif