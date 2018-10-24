#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){};

ClapTrap::ClapTrap(std::string name)
{
	set_name(name);
	std::cout << "ClapTrap Constructor" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const &rhs)
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
	std::cout << "ClapTrap Constructor Copy - Create " << _name << " level : " << _level << std::endl;
};

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destroyed." << std::endl;
};

void ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "ClapTrap " << _name <<  " attacks " << target <<  " at range, causing " << _ranged_attack_damage << " points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "ClapTrap " << _name <<  " attacks " << target <<  " at melee, causing " << _melee_attack_damage << " points of damage !" << std::endl;
}



void ClapTrap::takeDamage(unsigned int amount)
{
	amount -= _armor_damage_reduction;
	if (amount == 0)
		std::cout << "ClapTrap " << _name << " feels nothing." << std::endl;
	_hit_points -= amount;
	if (_hit_points  <= 0)
		std::cout << "ClapTrap " << _name << " take damage (" << amount << ") die !" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " take damage (" << amount << ") outch ! Still has" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
	if (_hit_points > 100)
		_hit_points = _max_hit_points;
	else
		std::cout << "ClapTrap " << _name << " gets healthier +" << amount << "HP new total : " << _hit_points << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & rhs)
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


/* GETTER */

int ClapTrap::get_max_hit_points() const {return (this->_max_hit_points);}
int ClapTrap::get_critical_damage() const {return (this->_critical_damage);}
int ClapTrap::get_max_energy_points() const {return (this->_max_energy_points);}
int ClapTrap::get_melee_attack_damage() const {return (this->_melee_attack_damage);}
int ClapTrap::get_ranged_attack_damage() const {return (this->_ranged_attack_damage);}
int ClapTrap::get_armor_damage_reduction() const {return (this->_armor_damage_reduction);}
int ClapTrap::get_hit_points() const {return (this->_hit_points);}
int ClapTrap::get_energy_points() const {return (this->_energy_points);}
int ClapTrap::get_level() const {return (this->_level);}
std::string ClapTrap::get_name() const {return (this->_name);}

/* SETTER */

void ClapTrap::set_max_hit_points(int value) { this->_max_hit_points = value; }
void ClapTrap::set_critical_damage(int value) { this->_critical_damage = value; }
void ClapTrap::set_max_energy_points(int value) { this->_max_energy_points = value; }
void ClapTrap::set_melee_attack_damage(int value) { this->_melee_attack_damage = value; }
void ClapTrap::set_ranged_attack_damage(int value) { this->_ranged_attack_damage = value; }
void ClapTrap::set_armor_damage_reduction(int value) { this->_armor_damage_reduction = value; }
void ClapTrap::set_hit_points(int value) { this->_hit_points = value; }
void ClapTrap::set_energy_points(int value) { this->_energy_points = value; }
void ClapTrap::set_level(int value) { this->_level = value; }
void ClapTrap::set_name(std::string value) { this->_name = value;}