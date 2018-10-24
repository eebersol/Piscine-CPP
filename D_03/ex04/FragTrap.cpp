#include "FragTrap.hpp"


FragTrap::FragTrap(void){}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->set_max_hit_points(100);
	this->set_critical_damage(20);
	this->set_max_energy_points(100);
	this->set_melee_attack_damage(30);
	this->set_ranged_attack_damage(20);
	this->set_armor_damage_reduction(5);
	this->set_hit_points(100);
	this->set_energy_points(100);
	this->set_level(1);
	this->set_name(name);
	_gunWizard_damage 				= 15;
	_oneShotWonder_damage			= 20;
	_laserInferno_damage 			= 25;
	_boomTrap_damage 				= 30;
	_fragmentedFragTrap_damage 		= 35;
	std::cout << "Constructor" << std::endl;
};

FragTrap::FragTrap(FragTrap const & rhs) : ClapTrap(rhs)
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
	std::cout << "Frag Trap Constructor Copy - Crete " << _name << "  flevel : " << _level << std::endl;
};

FragTrap::~FragTrap()
{
	std::cout << "FR4G-TRAP : " << this->_name << " destroyed." << std::endl;
};

void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FragTrap " << _name <<  " attacks " << target <<  " at range, causing " << _ranged_attack_damage << " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FragTrap " << _name <<  " attacks " << target <<  " at melee, causing " << _melee_attack_damage << " points of damage !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	amount -= _armor_damage_reduction;
	if (amount == 0)
		std::cout << "FragTrap " << _name << " feels nothing." << std::endl;
	_hit_points -= amount;
	if (_hit_points  <= 0)
		std::cout << "FragTrap " << _name << " take damage (" << amount << ") die !" << std::endl;
	else
		std::cout << "FragTrap " << _name << " take damage (" << amount << ") outch ! Still has" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	_hit_points += amount;
	if (_hit_points > 100)
		_hit_points = _max_hit_points;
	else
		std::cout << "FragTrap " << _name << " gets healthier +" << amount << "HP new total : " << _hit_points << std::endl;
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