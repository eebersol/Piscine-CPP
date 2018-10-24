#ifndef ASTEROID_H
# define ASTEROID_H

#include "AEntity.class.hpp"

class Asteroid : public AEntity
{

public:

	Asteroid(void);
	Asteroid(Asteroid const &src);
	virtual ~Asteroid(void);
	Asteroid	&operator=(Asteroid const &rhs);

	std::string		draw() const;

};

#endif
