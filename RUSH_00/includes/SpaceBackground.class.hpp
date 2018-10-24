#ifndef SPACE_BACKGROUND_H
# define SPACE_BACKGROUND_H

#include "AEntity.class.hpp"

class SpaceBackground : public AEntity
{

private:

public:

	SpaceBackground(void);
	SpaceBackground(SpaceBackground const &src);
	virtual ~SpaceBackground(void);
	SpaceBackground	&operator=(SpaceBackground const &rhs);

	virtual std::string		draw() const;

};

#endif
