#include <iostream>

int main(void)
{
	std::string str 				= "HI THIS IS BRAIN";
	std::string *pointerString 		= &str;
	std::string &basicString 		= str;


	std::cout << "Pointer str   :" << *pointerString << std::endl;
	std::cout << "Reference str : " << basicString  << std::endl;
}