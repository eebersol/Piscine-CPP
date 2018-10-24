#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <iostream>

class User 
{

	public:
		User();
		void create_user();
		void display_user();
		void preview_user(int index);
		void select_length(std::string value);

	private:
		std::string fname;
		std::string lname;
		std::string nname;
		std::string login;
		std::string paddress;
		std::string eaddress;
		std::string pnumber;
		std::string bdate;
		std::string fmeal;
		std::string ucolor;
		std::string dsecret;
};

#endif