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
		/* Comparaison operator */
			bool operator>(Fixed const & rhs)  const;
			bool operator<(Fixed const & rhs)  const;
			bool operator>=(Fixed const & rhs) const;
			bool operator<=(Fixed const & rhs) const;
			bool operator==(Fixed const & rhs) const;
			bool operator!=(Fixed const & rhs) const;
		/* arithmetic operator */
			Fixed operator+(Fixed const & rhs) const;
			Fixed operator-(Fixed const & rhs) const;
			Fixed operator*(Fixed const & rhs) const;
			Fixed operator/(Fixed const & rhs) const;
		/* increment operator */
			Fixed 	 operator++(int);
			Fixed 	& operator++();
			Fixed 	 operator--(int);
			Fixed 	& operator--();
		/* non-member function */
			static const Fixed	& min(Fixed const & lhs, Fixed const & rhs);
 			static const Fixed	& max(Fixed const & lhs, Fixed const & rhs);
	private:
		static const int static_integer;
		int _integer;


};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif