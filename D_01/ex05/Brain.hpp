#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <sstream>

class Brain
{
	public:
		Brain();
		~Brain();
		std::string identify();
	
	private:
		std::string	adress;
		void 	set_adress();
};

#endif