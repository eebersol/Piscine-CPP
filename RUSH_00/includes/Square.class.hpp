#ifndef SQUARE_H
# define SQUARE_H

# include <ncurses.h>
# include "AEntity.class.hpp"

class Square
{

private:

	int		_x;
	int		_y;
	AEntity	*_entity;

public:

	static const int		width;
	static const int		height;

	Square(int x, int y);
	Square(Square const &src);
	~Square(void);
	Square	&operator=(Square const &rhs);

	void		setEntity(AEntity *entity);
	void		removeEntity();

	void		drawSquare(WINDOW *win) const;
	AEntity		*getEntity() const;


};

#endif

