#include "span.hpp"
#include <stdexcept>
#include <iostream>
# include <list>

// template <class T>
// class Array;


int main()
{
    Span sp = Span(6);

    sp.addNumber(1);
    sp.addNumber(100);
    sp.addNumber(10000);
    sp.addNumber(17);
    sp.addNumber(11056);
    sp.addNumber(780);


    try {
    	std::cout << sp.longestSpan() << std::endl;
   	}
   	catch (std::string e) {
        std::cout << e << std::endl;
    }
    try {
    	std::cout << sp.shortestSpan() << std::endl;
    }
   	 catch (std::string e) {
        std::cout << e << std::endl;
    }
}