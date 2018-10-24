#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & rhs); 
		~ClapTrap();
		ClapTrap &	operator=(ClapTrap const & rhs);\
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		/* SETTER */
		void set_max_hit_points(int value);
		void set_critical_damage(int value);
		void set_max_energy_points(int value);
		void set_melee_attack_damage(int value);
		void set_ranged_attack_damage(int value);
		void set_armor_damage_reduction(int value);
		void set_hit_points(int value);
		void set_energy_points(int value);
		void set_level(int value);
		void set_name(std::string);
		/* GETTER */
		int get_max_hit_points() const;
		int get_critical_damage() const;
		int get_max_energy_points() const;
		int get_melee_attack_damage() const;
		int get_ranged_attack_damage() const;
		int get_armor_damage_reduction() const;
		int get_hit_points() const;
		int get_energy_points() const;
		int get_level() const;
		std::string get_name() const;

	protected:
		int _max_hit_points;
		int _critical_damage;
		int _max_energy_points;
		int _melee_attack_damage;
		int _ranged_attack_damage;
		int _armor_damage_reduction;
		int _gunWizard_damage;
		int _oneShotWonder_damage;
		int _laserInferno_damage;
		int _boomTrap_damage;
		int _fragmentedFragTrap_damage;
		int _hit_points;
		int _energy_points;
		int _level;
		std::string _name;
};

#endif