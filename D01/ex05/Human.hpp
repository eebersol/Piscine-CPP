#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include <sstream> //for std::stringstream 
#include "Brain.hpp"

class Human
{
	public:
		Human();
		~Human();
		std::string identify();
		Brain getBrain();

	private:
		Brain *brain;

};

#endif