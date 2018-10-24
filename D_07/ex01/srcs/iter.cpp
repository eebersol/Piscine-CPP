#include <iostream>




#include <iostream>
#include <string.h>


template <class T>
void iter(T* tab, unsigned int nb, void (*f)(T & a)) {
		for (unsigned int i = 0; i < nb; i++)
			f(tab[i]);
}

template <class T>
void toUpper(T &raw)
{
	raw = raw + 32;
}


int main( void ) 
{
	char b[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
	::iter(b, 7, ::toUpper);

	std::cout << b[0];
	std::cout << b[1];
	std::cout << b[2];
	std::cout << b[3];
	std::cout << b[4];
	std::cout << b[5];
	std::cout << b[6];
	std::cout << b[7] << std::endl;
	return 0;	

}