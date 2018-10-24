#include "ScavTrap.hpp"


ScavTrap::ScavTrap(void){}

ScavTrap::ScavTrap(std::string name): _name(name)
{
	set_max_hit_points(100);
	set_critical_damage(0);
	set_max_energy_points(50);
	set_melee_attack_damage(20);
	set_ranged_attack_damage(15);
	set_armor_damage_reduction(3);
	set_hit_points(100);
	set_energy_points(50);
	set_level(1);
	set_name(name);
	std::cout << "ScavTrap Constructor" << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const & rhs)
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

	std::cout << "ScavTrap Constructor Copy - Crete " << _name << "level : " << _level << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroyed." << std::endl;
};


void ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "ScavTrap " << _name <<  " attacks " << target <<  " at range, causing " << _ranged_attack_damage << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "ScavTrap " << _name <<  " attacks " << target <<  " at melee, causing " << _melee_attack_damage << " points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	amount -= _armor_damage_reduction;
	if (amount == 0)
		std::cout << "ScavTrap " << _name << " feels nothing." << std::endl;
	_hit_points -= amount;
	if (_hit_points  <= 0)
		std::cout << "ScavTrap " << _name << "take damage (" << amount << ") die !" << std::endl;
	else
		std::cout << "ScavTrap " << _name << "take damage (" << amount << ") outch ! Still has" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
	if (_hit_points > 100)
		_hit_points = _max_hit_points;
	else
		std::cout << "ScavTrap " << _name << " gets healthier +" << amount << "HP new total : " << _hit_points << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const & rhs)
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

void 	ScavTrap::challengeNewcomer(std::string const & target)
{
	int random = 0 + (rand() % (int)(3 - 0 + 1));
	std::string challenge[] = {
		"Eat your food with your feet.",
		"Do not talk about the day.",
		"Speak english about the day.",
		"Send nudes."
	};

	std::cout << "ScavTrap " << _name <<  "challenge you " << target << "to : " << challenge[random] << " will you date ? " << std::endl;
} 

/* GETTER */

int ScavTrap::get_max_hit_points() const {return (this->_max_hit_points);}
int ScavTrap::get_critical_damage() const {return (this->_critical_damage);}
int ScavTrap::get_max_energy_points() const {return (this->_max_energy_points);}
int ScavTrap::get_melee_attack_damage() const {return (this->_melee_attack_damage);}
int ScavTrap::get_ranged_attack_damage() const {return (this->_ranged_attack_damage);}
int ScavTrap::get_armor_damage_reduction() const {return (this->_armor_damage_reduction);}
int ScavTrap::get_hit_points() const {return (this->_hit_points);}
int ScavTrap::get_energy_points() const {return (this->_energy_points);}
int ScavTrap::get_level() const {return (this->_level);}
std::string ScavTrap::get_name() const {return (this->_name);}

/* SETTER */

void ScavTrap::set_max_hit_points(int value) { this->_max_hit_points = value; }
void ScavTrap::set_critical_damage(int value) { this->_critical_damage = value; }
void ScavTrap::set_max_energy_points(int value) { this->_max_energy_points = value; }
void ScavTrap::set_melee_attack_damage(int value) { this->_melee_attack_damage = value; }
void ScavTrap::set_ranged_attack_damage(int value) { this->_ranged_attack_damage = value; }
void ScavTrap::set_armor_damage_reduction(int value) { this->_armor_damage_reduction = value; }
void ScavTrap::set_hit_points(int value) { this->_hit_points = value; }
void ScavTrap::set_energy_points(int value) { this->_energy_points = value; }
void ScavTrap::set_level(int value) { this->_level = value; }
void ScavTrap::set_name(std::string value) { this->_name = value;}
