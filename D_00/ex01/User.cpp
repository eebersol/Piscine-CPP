#include "User.hpp"

User::User(void) {
    return ;
};

void User::create_user()
{	
	std::cout << " -- new contact --" << std::endl;
	std::cout << "00/10 - first name : " ;
	std::getline(std::cin, fname);
	std::cout << "01/10 - last name : ";
	std::getline(std::cin, lname);
	std::cout << "02/10 - nickname : ";
	std::getline(std::cin, nname);
	std::cout << "03/10 - login : ";
	std::getline(std::cin, login);
	std::cout << "04/10 - postal address : ";
	std::getline(std::cin, paddress);
	std::cout << "05/10 - email address: ";
	std::getline(std::cin, eaddress);
	std::cout << "06/10 - phone number: ";
	std::getline(std::cin, pnumber);
	std::cout << "07/10 - birthday date : ";
	std::getline(std::cin, bdate);
	std::cout << "08/10 - favorite meal : ";
	std::getline(std::cin, fmeal);
	std::cout << "09/10 - underwear color : ";
	std::getline(std::cin, ucolor);
	std::cout << "10/10 - darkest secret :";
	std::getline(std::cin, dsecret);
};

void User::display_user()
{	
	std::cout << "first name: " ;
	std::cout << fname << std::endl;
	std::cout << "last name: ";
	std::cout << lname << std::endl;
	std::cout << "nickname: ";
	std::cout << nname << std::endl;
	std::cout << "login : ";
	std::cout << login << std::endl;
	std::cout << "postal address: ";
	std::cout << paddress << std::endl;
	std::cout << "email address: ";
	std::cout << eaddress << std::endl;
	std::cout << "phone number: ";
	std::cout << pnumber << std::endl;
	std::cout << "birthday date: ";
	std::cout << bdate << std::endl;
	std::cout << "favorite meal: ";
	std::cout << fmeal << std::endl;
	std::cout << "underwear color: ";
	std::cout << ucolor << std::endl;
	std::cout << "darkest secret: ";
	std::cout << dsecret << std::endl;
};

void User::select_length(std::string value)
{
	if (value.size() > 10)
		std::cout << value.substr(0, 9) << '.';
	else
	{
		while (value.size() < 10)
			value += ' ';
		std::cout << value;
	}
	std::cout << "|";
}

void User::preview_user(int index)
{
	if (!fname.empty() && !lname.empty() && !nname.empty())
	{
		std::cout << "|      ";
		std::cout << index;
		std::cout << "   |";
		select_length(fname);
		select_length(lname);
		select_length(nname);
		std::cout << std::endl;
	}
};
