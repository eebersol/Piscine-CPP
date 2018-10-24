#include "Pony.hpp"

void 	ponyOnTheStack(void)
{
	Pony whitePony("Zeus", 180);

	whitePony.run();
	whitePony.eat();
	whitePony.sleep();
	return ;
}

void 	ponyOnTheHeap(void)
{
	Pony *blackPony;

	blackPony = new Pony("Hades", 500);
	blackPony->run();
	blackPony->eat();
	blackPony->sleep();
	delete(blackPony);
	return ;
}

int		main( void ) 
{
	ponyOnTheStack();
	ponyOnTheHeap();
	return (0);
}