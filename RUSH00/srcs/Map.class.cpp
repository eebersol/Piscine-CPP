#include "Map.class.hpp"

Map::Map(void)
{
	int		x = 1;
	int		y = 1;

	for (int y1 = 0; y1 < GRIDY; y1++)
	{
		x = 1;
		for (int x1 = 0; x1 < GRIDX; x1++)
		{
			this->_grid[y1][x1] = new Square(x, y);
			x += Square::width;
		}
		y += Square::height;
	}
	initscr();
	keypad(stdscr, TRUE);

	this->_win = subwin(stdscr, GRIDY * Square::height + 2, GRIDX * Square::width + 2, 1, 1);
	this->_panel = subwin(stdscr, 5, 122, 78, 1);
	
	box(this->_win, ACS_VLINE, ACS_HLINE);
	box(this->_panel, ACS_VLINE, ACS_HLINE);

	wrefresh(this->_panel);
	wrefresh(this->_win);
	
	printTitle("3", "0", "0000", "0");
	this->welcome();
	getch();
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, TRUE);

}

Map::Map(Map const &src)
{
	*this = src;
}

void Map::welcome()
{
	werase(this->_win);
	box(this->_win, ACS_VLINE, ACS_HLINE);
	mvwprintw(this->_win, 35, 29 , ("####### #######         ######  ####### ####### ######  #######"));
	mvwprintw(this->_win, 36, 29 , ("#          #            #     # #          #    #     # #     # "));
	mvwprintw(this->_win, 37, 29 , ("#          #            #     # #          #    #     # #     # "));
	mvwprintw(this->_win, 38, 29 , ("#####      #            ######  #####      #    ######  #     # "));
	mvwprintw(this->_win, 39, 29 , ("#          #            #   #   #          #    #   #   #     # "));
	mvwprintw(this->_win, 40, 29 , ("#          #            #    #  #          #    #    #  #     # "));
	mvwprintw(this->_win, 41, 29 , ("#          #    ####### #     # #######    #    #     # #######"));

	wrefresh(this->_win);
}
void Map::gameOver()
{
	werase(this->_win);
	box(this->_win, ACS_VLINE, ACS_HLINE);
	mvwprintw(this->_win, 35, 25 , (" #####     #    #     # #######         ####### #     # ####### ######  "));
	mvwprintw(this->_win, 36, 25 , ("#     #   # #   ##   ## #               #     # #     # #       #     # "));
	mvwprintw(this->_win, 37, 25 , ("#        #   #  # # # # #               #     # #     # #       #     # "));
	mvwprintw(this->_win, 38, 25 , ("#  #### #     # #  #  # #####           #     # #     # #####   ######  "));
	mvwprintw(this->_win, 39, 25 , ("#     # ####### #     # #               #     #  #   #  #       #   #   "));
	mvwprintw(this->_win, 40, 25 , ("#     # #     # #     # #               #     #   # #   #       #    #  "));
	mvwprintw(this->_win, 41, 25 , (" #####  #     # #     # ####### ####### #######    #    ####### #     # "));

	wrefresh(this->_win);
}

void Map::printTitle(std::string Lvalue, std::string Svalue, std::string Tvalue, std::string LvLvalue)
{
	werase(this->_panel);
	box(this->_panel, ACS_VLINE, ACS_HLINE);
	mvwprintw(this->_panel, 2, 28 , ("| Life : " + Lvalue).c_str());
	mvwprintw(this->_panel, 2, 39 , ("| Level : " + LvLvalue).c_str());
	mvwprintw(this->_panel, 2, 51 , ("| Score : " + Svalue).c_str());
	mvwprintw(this->_panel, 2, 64 , ("| Time : " + Tvalue).c_str());
	mvwprintw(this->_panel, 2, 77 , "|");

	wrefresh(this->_panel);
}

Map::~Map(void)
{
	for (int y1 = 0; y1 < GRIDY; y1++)
		for (int x1 = 0; x1 < GRIDX; x1++)
			delete this->_grid[y1][x1];
	delwin(this->_win);
	endwin();
}

Map	&Map::operator=(Map const &rhs)
{
	this->_win = rhs._win;
	this->_panel = rhs._panel;
	for (int y1 = 0; y1 < GRIDY; y1++)
	{
		for (int x1 = 0; x1 < GRIDX; x1++)
			this->_grid[y1][x1] = rhs._grid[y1][x1];
	}
	return (*this);
}

void		Map::drawMap()
{
	for (int y1 = 0; y1 < GRIDY; y1++)
	{
		for (int x1 = 0; x1 < GRIDX; x1++)
			this->_grid[y1][x1]->drawSquare(this->_win);
		box(this->_win, ACS_VLINE, ACS_HLINE);
		wrefresh(this->_win);
	}
}

void		Map::reset()
{
	for (int y1 = 0; y1 < GRIDY; y1++)
	{
		for (int x1 = 0; x1 < GRIDX; x1++)
			this->_grid[y1][x1]->removeEntity();
	}
}

void		Map::addEntity(AEntity *e)
{
	this->_grid[e->get_pos_y()][e->get_pos_x()]->setEntity(e);
}

bool	Map::isEntity(int x, int y)
{
	return (this->_grid[y][x]->getEntity() != NULL);
}
