#ifndef GAME_H
# define GAME_H

# include "Wave.class.hpp"
# include "Heroes.class.hpp"
# include "Weapon.class.hpp"
# include "Obstacle.class.hpp"
# include "Background.class.hpp"

#define SHOOT 		32
#define ESC 		27
#define MAXENEMY	10

class Game
{

private:

	Map				_map;
	Wave			*_wave;
	Heroes			*_heroes;
	Weapon			*_weapon;
	Obstacle		*_obstacle;
	Background		*_bg;

public:

	Game(void);
	Game(Game const &src);
	~Game(void);
	Game	&operator=(Game const &rhs);
	void 	gameStart();
	void	initGame();
	bool	editEntities(int keyCode);
	void	manageMoveHeroes(int keyCode);


};

#endif
