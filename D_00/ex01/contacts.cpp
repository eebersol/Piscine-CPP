#include "User.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <array>


int main() 
{
	User myInstance[7];
	int current_class;
	int i;

	current_class = 0;
	std::cout << "> : ";
	for (std::string line; std::getline(std::cin, line);)
	{
		if (line == "ADD" && current_class < 7)
		{
			myInstance[current_class].create_user();
			current_class++;
		}
		else if (line == "ADD" && current_class >= 7)
			std::cout << "Conact list full";
		else if (line == "SEARCH")		
		{
			std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
			for (i = 0; i < current_class; i++)
				myInstance[i].preview_user(i+1);
			std::cout << "Select index :";
			std::string index;
			std::getline(std::cin, index);
			if (std::isdigit(index[0]))
				i = stoi(index) - 1;
			else
				i = -1;
			if (i >= 0 && i <= 7 && i < current_class)
				myInstance[i].display_user();
			else
				std::cout << "Invalid Index";
		}
		else if (line == "EXIT")		
			break;
		else
			std::cout << "Command not found : " << line;
		std::cout << std::endl << "> : ";
	}
    return 0;
}
