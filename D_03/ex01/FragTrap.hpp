#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>

class FragTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(FragTrap const & rhs); 
		~FragTrap();
		FragTrap &	operator=(FragTrap const & rhs);
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_execlang__(std::string const & target);
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
		FragTrap(void);
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

		void gunWizard(std::string const &target);
		void oneShotWonder(std::string const &target);
		void laserInferno(std::string const &target);
		void boomTrap(std::string const &target);
		void fragmentedFragTrap(std::string const &target);
	};

#endif