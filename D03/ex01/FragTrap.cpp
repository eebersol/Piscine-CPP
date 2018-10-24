#include "FragTrap.hpp"

FragTrap::FragTrap(void){}

FragTrap::FragTrap(std::string name)
{
	set_max_hit_points(100);
	set_critical_damage(20);
	set_max_energy_points(100);
	set_melee_attack_damage(30);
	set_ranged_attack_damage(20);
	set_armor_damage_reduction(5);
	set_hit_points(100);
	set_energy_points(100);
	set_level(1);
	set_name(name);
	_gunWizard_damage 				= 15;
	_oneShotWonder_damage			= 20;
	_laserInferno_damage 			= 25;
	_boomTrap_damage 				= 30;
	_fragmentedFragTrap_damage 		= 35;
	std::cout << "Constructor" << std::endl;
};

FragTrap::FragTrap(FragTrap const & rhs)
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

	std::cout << "Constructor Copy - Crete " << _name << "level : " << _level << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TRAP destroyed." << std::endl;
};


void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << _name <<  " attacks " << target <<  " at range, causing " << _ranged_attack_damage << " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP " << _name <<  " attacks " << target <<  " at melee, causing " << _melee_attack_damage << " points of damage !" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const & rhs)
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

void FragTrap::takeDamage(unsigned int amount)
{
	amount -= _armor_damage_reduction;
	if (amount == 0)
		std::cout << "FR4G-TP " << _name << " feels nothing." << std::endl;
	_hit_points -= amount;
	if (_hit_points  <= 0)
		std::cout << "FR4G-TP " << _name << "take damage (" << amount << ") die !" << std::endl;
	else
		std::cout << "FR4G-TP " << _name << "take damage (" << amount << ") outch ! Still has" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
	if (_hit_points > 100)
		_hit_points = _max_hit_points;
	else
		std::cout << "FR4G-TP " << _name << " gets healthier +" << amount << "HP new total : " << _hit_points << std::endl;
}

void 	FragTrap::vaulthunter_dot_execlang__(std::string const & target)
{
	int random = 0 + (rand() % (int)(4 - 0 + 1));
	void (FragTrap::*FuncPtr[5])(std::string const & t) = {&FragTrap::gunWizard, &FragTrap::oneShotWonder, &FragTrap::laserInferno, &FragTrap::boomTrap, &FragTrap::fragmentedFragTrap};
	std::string funcName[5] = {"gunWizard", "oneShotWonder", "laserInferno", "boomTrap", "fragmentedFragTrap"};

	_energy_points -= 25;
	if (_energy_points < 0)
		std::cout << "FR4G-TP " << _name << " no more energy." << std::endl;
	else
		(this->*FuncPtr[random])(target);
	random = 0;
}

void FragTrap::gunWizard(std::string const & target)
{
	std::cout << "FR4G-TP " << _name <<  " attacks " << target <<  " cast the spell Gun Wizard - inflicts " << _gunWizard_damage << " points of damage !" << std::endl;
};

void FragTrap::oneShotWonder(std::string const & target)
{
	int random = random = 0 + (rand() % (int)(100 - 0 + 1));
	if (random > 70)
		std::cout << "[Critical Strike] FR4G-TP " << _name <<  " attacks " << target <<  " cast the spell One Shot Wonder - inflicts " << _oneShotWonder_damage + _critical_damage << " points of damage !" << std::endl;
	else if (random > 30)
		std::cout << "[Success] FR4G-TP " << _name <<  " attacks " << target <<  " cast the spell One Shot Wonder - inflicts " << _oneShotWonder_damage << " points of damage !" << std::endl;
	else
	{
		std::cout << "[Echec Critique] FR4G-TP " << _name <<  " attacks " << target <<  " cast the spell Shot Wonder but this one explodes and inflicts " << _oneShotWonder_damage + _critical_damage << " points of damage to ! " << _name << std::endl;
		_hit_points -= _oneShotWonder_damage + _critical_damage;
		if (_hit_points < 0)
			std::cout << "FR4G-TP died from the explosin." << std::endl;
	}

};

void FragTrap::laserInferno(std::string const & target)
{
	std::cout << "FR4G-TP " << _name <<  " attacks " << target <<  " cast the spell Laser Inferno - inflicts " << _laserInferno_damage << " points of damage !" << std::endl;
};

void FragTrap::boomTrap(std::string const & target)
{
	std::cout << "FR4G-TP " << _name <<  " attacks " << target <<  " cast the spell Boom Trap Damage - inflicts " << _boomTrap_damage << " points of damage !" << std::endl;
};

void FragTrap::fragmentedFragTrap(std::string const & target)
{
	std::cout << "FR4G-TP " << _name <<  " attacks " << target <<  " cast the spell Fragmented Frag Trap - inflicts " << _fragmentedFragTrap_damage << " points of damage !" << std::endl;
};


/* GETTER */

int FragTrap::get_max_hit_points() const {return (this->_max_hit_points);}
int FragTrap::get_critical_damage() const {return (this->_critical_damage);}
int FragTrap::get_max_energy_points() const {return (this->_max_energy_points);}
int FragTrap::get_melee_attack_damage() const {return (this->_melee_attack_damage);}
int FragTrap::get_ranged_attack_damage() const {return (this->_ranged_attack_damage);}
int FragTrap::get_armor_damage_reduction() const {return (this->_armor_damage_reduction);}
int FragTrap::get_hit_points() const {return (this->_hit_points);}
int FragTrap::get_energy_points() const {return (this->_energy_points);}
int FragTrap::get_level() const {return (this->_level);}
std::string FragTrap::get_name() const {return (this->_name);}

/* SETTER */

void FragTrap::set_max_hit_points(int value) { this->_max_hit_points = value; }
void FragTrap::set_critical_damage(int value) { this->_critical_damage = value; }
void FragTrap::set_max_energy_points(int value) { this->_max_energy_points = value; }
void FragTrap::set_melee_attack_damage(int value) { this->_melee_attack_damage = value; }
void FragTrap::set_ranged_attack_damage(int value) { this->_ranged_attack_damage = value; }
void FragTrap::set_armor_damage_reduction(int value) { this->_armor_damage_reduction = value; }
void FragTrap::set_hit_points(int value) { this->_hit_points = value; }
void FragTrap::set_energy_points(int value) { this->_energy_points = value; }
void FragTrap::set_level(int value) { this->_level = value; }
void FragTrap::set_name(std::string value) { this->_name = value;}

