

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{	

	typedef std::stack<T> 	_st;
	public:
		typedef typename _st::container_type::iterator iterator;

		MutantStack<T>(void) { }
		~MutantStack<T>(void) { }
		iterator begin()
		{
			return this->_st::c.begin();
		}
		iterator end()
		{
			return this->_st::c.end();
		}
};

#endif