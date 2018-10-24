#ifndef SpaceShips_HPP
#define SpaceShips_HPP

#include "AEntity.class.hpp"
#include "Map.class.hpp"


class SpaceShips : public AEntity
{
	public:
		SpaceShips();
		SpaceShips(SpaceShips const & rhs);
		virtual ~SpaceShips();
		SpaceShips &operator=(SpaceShips const & rhs);
		void move(Map & map, Direction d);

		bool	isNextEntities(Map &map, Direction d);
		virtual std::string draw() const = 0;

};

#endif