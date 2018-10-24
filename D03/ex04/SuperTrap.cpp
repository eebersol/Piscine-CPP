#include "SuperTrap.hpp"


SuperTrap::SuperTrap(void){};

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
	this->set_max_hit_points(100);
	this->set_critical_damage(20);
	this->set_max_energy_points(120);
	this->set_melee_attack_damage(60);
	this->set_ranged_attack_damage(20);
	this->set_armor_damage_reduction(5);
	this->set_hit_points(100);
	this->set_energy_points(120);
	this->set_level(1);
	this->set_name(name);
	_gunWizard_damage 				= 15;
	_oneShotWonder_damage			= 20;
	_laserInferno_damage 			= 25;
	_boomTrap_damage 				= 30;
	_fragmentedFragTrap_damage 		= 35;
	std::cout << "SuperTrap Constructor" << std::endl;
};

SuperTrap::SuperTrap(SuperTrap const & rhs) : ClapTrap(rhs),  FragTrap(rhs), NinjaTrap(rhs)
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
	std::cout << "SuperTrap Constructor Copy - Create " << _name << " level : " << _level << std::endl;
};

SuperTrap::~SuperTrap()
{
	std::cout << "SuperTrap " << this->_name << " destroyed." << std::endl;
};

void 	SuperTrap::challengeNewcomer(std::string const & target)
{
	int random = 0 + (rand() % (int)(3 - 0 + 1));
	std::string challenge[] = {
		"Eat your food with your feet.",
		"Do not talk about the day.",
		"Speak english about the day.",
		"Send nudes Bruuuhhhh."
	};

	std::cout << "SuperTrap " << _name <<  "challenge you " << target << "to : " << challenge[random] << " will you date ? " << std::endl;
} 

std::string const SuperTrap::getName() const
{
	return (this->_name);
}

SuperTrap &SuperTrap::operator=(SuperTrap const & rhs)
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

void SuperTrap::rangedAttack(std::string const & target)
{
	FragTrap::rangedAttack(target);
}

void SuperTrap::meleeAttack(std::string const & target)
{
	NinjaTrap::rangedAttack(target);
}