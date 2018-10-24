#include <iostream>

int main(int ac, char **av)
{
	int 	i;
	size_t 	j;

	if (ac >= 2)
	{
		for (i = 1; i < ac ; i++)
		{
			for (j = 0; j < std::strlen(av[i]) ; j++)
				std::cout << (char) toupper(av[i][j]);
		}
		std::cout << std::endl;
	}
	else
		std::cout  << " * LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
