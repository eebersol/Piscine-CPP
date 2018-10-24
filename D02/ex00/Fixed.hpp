#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &p2); 
		~Fixed();
		Fixed &	operator=(Fixed const & rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _integer;
		static const int static_integer = 8;
};

#endif