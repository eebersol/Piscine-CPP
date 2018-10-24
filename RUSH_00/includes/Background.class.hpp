#ifndef BACKGROUND_H
# define BACKGROUND_H

# include "SpaceBackground.class.hpp"
# include "Map.class.hpp"

class Background
{

private:

	clock_t			_refreshTime;
	SpaceBackground	_bg[8];

public:

	Background(void);
	Background(Background const &src);
	~Background(void);
	Background	&operator=(Background const &rhs);

	bool	checkTime();
	void	move();
	void	setCoordinate(Map &map);


};

#endif
