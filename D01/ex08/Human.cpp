#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	std::cout << "Human melee attack " << target << std::endl;
};

void Human::rangedAttack(std::string const & target)
{
	std::cout << "Human ranged attack " << target << std::endl;
};

void Human::intimidatingShout(std::string const & target)
{
	std::cout << "Human try to intimidate " << target << std::endl;
};

void Human::action(std::string const & action_name, std::string const & target)
{
	int i;
	void (Human::*FuncPtr[3])(std::string const & t) = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
	std::string funcName[3] = {"meleeAttack", "rangedAttack", "intimidatingShout"};
	
	for (i = 0; i < 3; i++)
	{
		if (funcName[i] == action_name)
			(this->*FuncPtr[i])(target);
	}
};


