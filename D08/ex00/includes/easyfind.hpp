#ifndef EASYFIND_HPP
#define EASYFIND_HPP

# include <stdexcept>
# include <iostream>
# include <string>
# include <list>

template <typename T>
void easyfind (T & container, int i)
{
	typename T::const_iterator p;

	p = std::find(container.begin(), container.end(), i);
	if (p != container.end()) {
		std::cout << "Value find in list." << std::endl;
	}
	else
	{
		throw (std::string("Value not found in list."));
	}
}

#endif