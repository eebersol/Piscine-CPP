#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>

class ScavTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & rhs); 
		~ScavTrap();
		ScavTrap &	operator=(ScavTrap const & rhs);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void challengeNewcomer(std::string const & target);
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

	private:
		ScavTrap(void);
		int _max_hit_points;
		int _critical_damage;
		int _max_energy_points;
		int _melee_attack_damage;
		int _ranged_attack_damage;
		int _armor_damage_reduction;
		int _hit_points;
		int _energy_points;
		int _level;
		std::string _name;
};

#endif