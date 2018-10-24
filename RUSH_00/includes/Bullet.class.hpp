#ifndef BULLET_HPP
# define BULLET_HPP

# include <ctime>
# include "SpaceShips.class.hpp"
# include "Map.class.hpp"


class Bullet : public AEntity
{

	public:
		Bullet();
		Bullet(Map &map, std::string name, int damage, int color, float speed, int posX, int posY);
		Bullet(Bullet const & src);
		virtual ~Bullet();
		Bullet & operator=( Bullet const & rhs );
		std::string draw() const;
		/* SETTER */
		void set_name(std::string value);
		void set_damage(int value);
		void set_speed(float value);
		void set_refreshTimeBullet();
		void set_alive(int value);
		/* GETTER */
		std::string get_name(void) const;
		int get_damage(void) const;
		int get_color(void) const;
		float get_speed(void) const;

	protected:
		int 		_posY;
		int 		_posX;

	private:
		int 		_alive[100];
		std::string _name;
		int			_damage;
		float 		_speed;
		float		 _delayBullet;
		clock_t  	_refreshTimeBullet;

};

#endif