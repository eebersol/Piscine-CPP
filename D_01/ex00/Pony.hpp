#ifndef PONY_HPP
#define PONY_HPP

#include <iostream>

class Pony
{

	public:
		Pony(std::string name, int poid);
		~Pony();
		void run(void);
		void eat(void);
		void sleep(void);

	private:
		int 		poid;
		std::string name;

};

#endif