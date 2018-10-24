#include "span.hpp"

Span::Span(unsigned int n)
{
  v.reserve(n);
  _size = n;
  _place = n;
}

Span::~Span() {


};

void Span::addNumber (unsigned int i)
{
	if (_place > 0)
	{
		_place--;
		v.push_back(i);
	}
	else
		throw(std::string("No  more place."));
}

int Span::intComp(int lhs, int rhs) {
  return lhs < rhs;
}



int	Span::keepBestValue(std::vector<int> tryV)
{
	int result; 

	std::vector<int>::iterator min = std::min_element(std::begin(tryV), std::end(tryV));          
	result = tryV.at(std::distance(std::begin(tryV), min));
	return (result);
}


std::string Span::shortestSpan(void)
{	

	if (v.size() <= 1)
		throw(std::string("Invalid number size."));
	int d;
	int c;
	int b;
	int refInt;
	std::vector<int>::iterator it;
	std::vector<int>::iterator yt;

	for (it = v.begin(); it != v.end(); it++)
	{
		c = std::distance(v.begin(), it);
		refInt = v.at(c);
		for (yt = it+1; yt != v.end(); yt++)
		{
			b = std::distance(v.begin(), yt);
			d = refInt - v.at(b);
			if (d < 0)
				d *= -1;
			_diffA.push_back(d);
		}
	}
	std::cout << "Shortest span are : ";
	return std::to_string(keepBestValue(_diffA));
}
std::string Span::longestSpan(void)
{	
	int result;

	if (v.size() <= 1)
		throw(std::string("Invalid number size."));
	std::vector<int>::iterator min = std::min_element(std::begin(v), std::end(v));
	std::vector<int>::iterator max = std::max_element(std::begin(v), std::end(v));              
	result = v.at(std::distance(std::begin(v), max)) - v.at(std::distance(std::begin(v), min));    
	std::cout << "Longest span are : ";
	return std::to_string(result);
}