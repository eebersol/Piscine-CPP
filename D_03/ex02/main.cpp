#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	std::cout << std::endl << std::endl << "Initialisation :  " << std::endl << std::endl;

	FragTrap clap("Clap");
	FragTrap robert("Robert");
	ScavTrap scav("TOTO");
	ScavTrap trap("LOLO");
	ClapTrap *the_true = new FragTrap("THETRUE");



	std::cout << std::endl << std::endl << "FR4G-TRAP play : " << std::endl << std::endl;
	clap.rangedAttack("Robert");
	robert.takeDamage(20);
	clap.meleeAttack("Robert");
	robert.takeDamage(30);
	clap.meleeAttack("Robert");
	robert.takeDamage(5);
	clap.vaulthunter_dot_execlang__ ("Robert");
	clap.vaulthunter_dot_execlang__ ("Robert");
	clap.vaulthunter_dot_execlang__ ("Robert");

	std::cout << std::endl << std::endl << "ScavTrap play  " << std::endl << std::endl;
	scav.rangedAttack("LOLO");
	trap.takeDamage(20);
	scav.meleeAttack("LOLO");
	trap.takeDamage(30);
	scav.meleeAttack("LOLO");
	trap.takeDamage(5);
	scav.challengeNewcomer("LOLO");
	trap.challengeNewcomer("TOTO");

	std::cout << std::endl << std::endl << "ClapTrap play  " << std::endl << std::endl;
	the_true->rangedAttack("LOLO");
	the_true->takeDamage(20);
	the_true->meleeAttack("LOLO");
	the_true->takeDamage(30);
	the_true->meleeAttack("LOLO");
	the_true->takeDamage(5);

	std::cout << std::endl << std::endl << "Destroy Obj :" << std::endl << std::endl;
}