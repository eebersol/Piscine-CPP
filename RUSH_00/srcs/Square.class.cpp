#include "Square.class.hpp"

const int		Square::width = 6;
const int		Square::height = 3;

Square::Square(int x, int y) : _x(x), _y(y), _entity(NULL)
{

}

Square::Square(Square const &src)
{
	*this = src;
}

Square::~Square(void)
{

}

Square	&Square::operator=(Square const &rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_entity = rhs._entity;
	return (*this);
}

void		Square::setEntity(AEntity *entity)
{
	this->_entity = entity;
}

AEntity		*Square::getEntity() const
{
	return (this->_entity);
}

void		Square::removeEntity()
{
	this->_entity = NULL;
}

void	Square::drawSquare(WINDOW *win) const
{
	std::string		s;
	int				pos;

	if (this->_entity)
	{
		s = this->_entity->draw();
		for (int i = 0; i < 3; i++)
		{
			pos = s.find('\n');
			wattron(win, COLOR_PAIR(this->_entity->get_color()));
			wmove(win, this->_y + i, this->_x);
			waddstr(win , s.substr(0, pos).c_str());
			s.erase(0, pos + 1);
		}
		wattroff(win, COLOR_PAIR(this->_entity->get_color()));
	}
	else
	{
		mvwprintw(win, this->_y, this->_x, "      ");
		mvwprintw(win, this->_y + 1, this->_x, "      ");
		mvwprintw(win, this->_y + 2, this->_x, "       ");
	}
	wrefresh(win);
}
