#ifndef HEROES_HPP
#define HEROES_HPP

#include "SpaceShips.class.hpp"

class Heroes : public SpaceShips
{
	private:
	
		Heroes();

	public:
		Heroes(int pos_y, int pos_x);
		Heroes(Heroes const & rhs);
		virtual ~Heroes();
		Heroes &operator=(Heroes const & rhs);
		void	hitted(Map &map);
		bool 	tryRemoveEntity(int x, int y);
		virtual std::string draw() const;
};

#endif