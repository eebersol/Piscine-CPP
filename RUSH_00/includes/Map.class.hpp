#ifndef MAP_H
# define MAP_H

# include "Square.class.hpp"

# define GRIDX	20
# define GRIDY	25
# define ENTER  65

class Map
{

private:

	WINDOW 		*_win;
	WINDOW 		*_panel;
	Square		*_grid[GRIDY][GRIDX];

public:

	Map(void);
	Map(Map const &src);
	~Map(void);
	Map	&operator=(Map const &rhs);

	void	initMap();
	void	drawMap();
	void	reset();
	void	addEntity(AEntity *e);
	bool	isEntity(int x, int y);
	void 	printTitle(std::string Lvalue, std::string Svalue, std::string Tvalue, std::string LvLvalue);
	void	gameOver();
	void	welcome();
};

#endif
