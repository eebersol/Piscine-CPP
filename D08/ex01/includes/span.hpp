#ifndef SPAN_HPP
#define SPAN_HPP


# include <stdexcept>
# include <iostream>
# include <string>
# include <list>
# include <vector>

class Span {
	private:
		int 				_place;
		int 				_size;
		std::vector<int> 	v;
		std::vector<int> 	_diffA;

	public:
		Span(unsigned int i);
		~Span(void);
		void addNumber (unsigned int i);
		std::string longestSpan(void);
		std::string  shortestSpan(void);
		int intComp(int mlhs, int mrhs);
		int keepBestValue(std::vector<int> tryV);
		void calc(std::vector<int> vector, std::vector<int>::iterator yt);
};

#endif