#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
	public:

		Fixed(void);
		Fixed(const int integer);
		Fixed(const float floating);
		Fixed(Fixed const &p2); 
		~Fixed();
		Fixed &	operator=(Fixed const & rhs);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		static const int static_integer;
		int _integer;

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif