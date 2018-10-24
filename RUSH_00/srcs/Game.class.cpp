#include "Game.class.hpp"

Game::Game(void) : _wave(NULL), _heroes(NULL), _weapon(NULL), _obstacle(NULL)
{

}

Game::Game(Game const &src)
{
	*this = src;
}

Game::~Game(void)
{
}

Game	&Game::operator=(Game const &rhs)
{
	this->_wave = rhs._wave;
	this->_heroes = rhs._heroes;
	this->_weapon = rhs._weapon;
	this->_obstacle = rhs._obstacle;
	this->_bg = rhs._bg;
	return (*this);
}

void		Game::manageMoveHeroes(int keyCode)
{
	int life = 0;

	switch (keyCode)
	{
		case KEY_LEFT :
			this->_wave->tryRemoveEntity(this->_heroes->get_pos_x() - 1, this->_heroes->get_pos_y()) ? ++life : 0;
			this->_obstacle->tryRemoveEntity(this->_heroes->get_pos_x() - 1, this->_heroes->get_pos_y()) ? ++life : 0;
			this->_heroes->move(this->_map, left);
			break;
		case KEY_RIGHT :
			this->_wave->tryRemoveEntity(this->_heroes->get_pos_x() + 1, this->_heroes->get_pos_y()) ? ++life : 0;
			this->_obstacle->tryRemoveEntity(this->_heroes->get_pos_x() + 1, this->_heroes->get_pos_y()) ? ++life : 0;
			this->_heroes->move(this->_map, right);
			break;
		case KEY_UP :
			this->_wave->tryRemoveEntity(this->_heroes->get_pos_x(), this->_heroes->get_pos_y() - 1) ? ++life : 0;
			this->_obstacle->tryRemoveEntity(this->_heroes->get_pos_x(), this->_heroes->get_pos_y() - 1) ? ++life : 0;
			this->_heroes->move(this->_map, top);
			break;
		case KEY_DOWN :
			this->_wave->tryRemoveEntity(this->_heroes->get_pos_x(), this->_heroes->get_pos_y() + 1) ? ++life : 0;
			this->_obstacle->tryRemoveEntity(this->_heroes->get_pos_x(), this->_heroes->get_pos_y() + 1) ? ++life : 0;
			this->_heroes->move(this->_map, bottom);
			break;
		default : break;
	}
	life ? this->_heroes->hitted(this->_map) : (void)0;
}

bool		Game::editEntities(int keyCode)
{
	bool	need_refresh = false;

	this->_map.reset();
	if (keyCode == KEY_LEFT || keyCode == KEY_RIGHT || keyCode == KEY_UP || keyCode == KEY_DOWN)
	{
		this->_wave->setCoordinate(this->_map);
			this->_weapon->setCoordinate(this->_map);
		this->_obstacle->setCoordinate(this->_map);
		this->manageMoveHeroes(keyCode);
		need_refresh = true;
		this->_map.reset();
	}
	else if (keyCode == ESC || keyCode == SHOOT)
	{
		if (keyCode == ESC)
		{
			endwin();
			exit(1);
		}
		this->_wave->setCoordinate(this->_map);
		this->_obstacle->setCoordinate(this->_map);
		this->_weapon->newBullet("Heroes", 50, this->_heroes->get_pos_x(), this->_heroes->get_pos_y());
		this->_weapon->checkColison(*this->_wave, *this->_heroes, *this->_obstacle);
		this->_weapon->moveBullet(this->_map);
		need_refresh = true;
		this->_map.reset();
	}
	if (this->_wave->isAllDead())
	{
		if (this->_heroes->get_level() < 10)
		{
			this->_heroes->set_level(this->_heroes->get_level() + 1);
			this->_obstacle->setLevel(this->_heroes->get_level());
		}
		delete this->_wave;
		this->_wave = new Wave(this->_heroes->get_level());
	}
	else if (this->_wave->checkTime())
	{
		this->_map.addEntity(this->_heroes);
		this->_weapon->setCoordinate(this->_map);
		this->_obstacle->setCoordinate(this->_map);
		this->_wave->moveWave(this->_map, *this->_heroes, *this->_weapon, *this->_obstacle);
		need_refresh = true;
		this->_map.reset();
	}
	if (this->_weapon->checkTime())
	{
		this->_wave->setCoordinate(this->_map);
		this->_map.addEntity(this->_heroes);
		this->_obstacle->setCoordinate(this->_map);
		this->_weapon->checkColison(*this->_wave, *this->_heroes, *this->_obstacle);
		this->_weapon->moveBullet(this->_map);
		need_refresh = true;
		this->_map.reset();
	}
	if (this->_obstacle->checkTime())
	{
		this->_map.addEntity(this->_heroes);
		this->_wave->setCoordinate(this->_map);
		this->_weapon->setCoordinate(this->_map);
		this->_obstacle->moveWave(this->_map, *this->_heroes, *this->_weapon, *this->_wave);
		need_refresh = true;
		this->_map.reset();
	}
	if (this->_bg->checkTime())
	{
		this->_bg->move();
		need_refresh = true;
	}
	if (need_refresh)
	{
		this->_map.addEntity(this->_heroes);
		this->_wave->setCoordinate(this->_map);
		if (!this->_weapon->isAllDead())
			this->_weapon->setCoordinate(this->_map);
		this->_obstacle->setCoordinate(this->_map);
		this->_bg->setCoordinate(this->_map);
		return (true);
	}
	return (false);
}

void	Game::initGame()
{
	std::srand(time(nullptr));
	this->_weapon = new Weapon(50);
	this->_heroes = new Heroes(GRIDY - 2, (GRIDX / 2) - 1);
	this->_wave = new Wave(this->_heroes->get_level());
	this->_map.addEntity(this->_heroes);
	this->_wave->setCoordinate(this->_map);
	this->_obstacle = new Obstacle(this->_heroes->get_level());
	this->_bg = new Background();
	(void)this->_bg;
	this->_map.printTitle(std::to_string(this->_heroes->get_life()), "0000", "0", std::to_string(this->_heroes->get_level()));
	this->_map.drawMap();
}

void 	Game::gameStart()
{
	int keyCode;
	clock_t startTime = clock();
	clock_t elapsedSeconds;
	
	while (1) {
		keyCode = getch();
		elapsedSeconds = (clock() - startTime) / (double)(CLOCKS_PER_SEC);
		this->_map.printTitle(std::to_string(this->_heroes->get_life()), std::to_string(this->_heroes->get_score()), std::to_string(elapsedSeconds), std::to_string(this->_heroes->get_level()));
		if (this->editEntities(keyCode))
			this->_map.drawMap();
		if (this->_heroes->get_life() < 1)
			break;
	}
	this->_map.gameOver();
	while(1)
	{
		keyCode = getch();
		switch (keyCode)
		{
			case ESC :
				endwin();
				exit(1);
			default: break;
		}
	}
}
