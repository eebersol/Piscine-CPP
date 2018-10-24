#include "easyfind.hpp"
#include <stdexcept>
#include <iostream>
# include <list>
// template <class T>
// class Array;




void create_list(int search)
{
    std::list<int>  list_int;

    list_int.push_back(1);
    list_int.push_back(2);
    list_int.push_back(3);
    list_int.push_back(4);
    list_int.push_back(5);
    list_int.push_back(6);
    list_int.push_back(7);

    try {
        easyfind<std::list<int> >(list_int, search);
    }
    catch (std::string e) {
        std::cout << e << std::endl;
    }
}

int main() 
{
    create_list(1);
    create_list(10);
    create_list(3);

    return 0;
}
