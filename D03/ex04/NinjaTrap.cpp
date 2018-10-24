#include "NinjaTrap.hpp"


NinjaTrap::NinjaTrap(void){}
NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	set_max_hit_points(60);
	set_critical_damage(20);
	set_max_energy_points(120);
	set_melee_attack_damage(60);
	set_ranged_attack_damage(5);
	set_armor_damage_reduction(0);
	set_hit_points(60);
	set_energy_points(120);
	set_level(1);
	set_name(name);
	_gunWizard_damage 				= 15;
	_oneShotWonder_damage			= 20;
	_laserInferno_damage 			= 25;
	_boomTrap_damage 				= 30;
	_fragmentedFragTrap_damage 		= 35;


	std::cout << "NinjaTrap Constructor" << std::endl;
};

NinjaTrap::NinjaTrap(NinjaTrap const & rhs) : ClapTrap(rhs)
{
	_max_hit_points 				= rhs.get_max_hit_points();
	_critical_damage 				= rhs.get_critical_damage();
	_max_energy_points 				= rhs.get_max_energy_points();
	_melee_attack_damage 			= rhs.get_melee_attack_damage();
	_ranged_attack_damage 			= rhs.get_ranged_attack_damage();
	_armor_damage_reduction 		= rhs.get_armor_damage_reduction();;
	_hit_points						= rhs.get_hit_points();
	_energy_points					= rhs.get_energy_points();
	_level							= rhs.get_level();
	_name 							= rhs.get_name();

	std::cout << "NinjaTrap Constructor Copy - Create " << _name << " level : " << _level << std::endl;
};

NinjaTrap::~NinjaTrap()
{
	std::cout << "NinjaTrap " << this->_name << " destroyed." << std::endl;
};

void NinjaTrap::rangedAttack(std::string const & target)
{
	std::cout << "NinjaTrap " << _name <<  " attacks " << target <<  " at range, causing " << _ranged_attack_damage << " points of damage !" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout << "NinjaTrap " << _name <<  " attacks " << target <<  " at melee, causing " << _melee_attack_damage << " points of damage !" << std::endl;
}



void NinjaTrap::takeDamage(unsigned int amount)
{
	amount -= _armor_damage_reduction;
	if (amount == 0)
		std::cout << "NinjaTrap " << _name << " feels nothing." << std::endl;
	_hit_points -= amount;
	if (_hit_points  <= 0)
		std::cout << "NinjaTrap " << _name << " take damage (" << amount << ") die !" << std::endl;
	else
		std::cout << "NinjaTrap " << _name << " take damage (" << amount << ") outch ! Still has" << std::endl;
}

void NinjaTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
	if (_hit_points > 100)
		_hit_points = _max_hit_points;
	else
		std::cout << "NinjaTrap " << _name << " gets healthier +" << amount << "HP new total : " << _hit_points << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTrap const & target)
{
	std::cout << "NinjaTrap : " << _name << " try to run away infront " << target.get_name() << std::endl;
};

void NinjaTrap::ninjaShoebox(ScavTrap const & target)
{
	std::cout << "NinjaTrap : " << _name << " try to negociate with " << target.get_name() << std::endl;
};

void NinjaTrap::ninjaShoebox(NinjaTrap const & target)
{
	std::cout << "NinjaTrap : " << _name << " try to eat " << target.get_name() << std::endl;
};

std::string const NinjaTrap::getName() const
{
	return (this->_name);
}


NinjaTrap &NinjaTrap::operator=(NinjaTrap const & rhs)
{
	if(this == &rhs)
		return *this;
	this->_name 					= rhs._name;
	this->_max_hit_points 			= rhs._max_hit_points;
	this->_hit_points 				= rhs._hit_points;
	this->_max_energy_points 		= rhs._max_energy_points;
	this->_energy_points 			= rhs._energy_points;
	this->_melee_attack_damage 		= rhs._melee_attack_damage;
	this->_ranged_attack_damage 	= rhs._ranged_attack_damage;
	this->_armor_damage_reduction 	= rhs._armor_damage_reduction;
	this->_level 					= rhs._level;
	this->_critical_damage 			= rhs._critical_damage;
	return *this;
};
