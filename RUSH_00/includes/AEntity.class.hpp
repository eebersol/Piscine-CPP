#ifndef AENTITY_H
# define AENTITY_H

# include <string>

enum Direction {left, right, top, bottom};

class AEntity
{

public:

	AEntity(void);
	AEntity(AEntity const &src);
	virtual ~AEntity(void);
	AEntity	&operator=(AEntity const &rhs);

	virtual std::string		draw() const = 0;

	/* SETTER */
		void set_pos_y(int value);
		void set_pos_x(int value);
		void set_color(int value);
		void set_level(int value);
		void set_score(int value);
		void set_life(int value);
	/* GETTER */
		int get_score() const;
		int get_color() const;
		int get_level() const;
		int get_pos_x() const;
		int get_pos_y() const;
		int get_life()  const;
	protected:
		int _pos_x;
		int _pos_y;
		int _color;
		int _level;
		int _score;
		int _life;
};

#endif
