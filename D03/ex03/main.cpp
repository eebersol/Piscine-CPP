#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int main(void)
{
	std::cout << std::endl << std::endl << "Initialisation :  " << std::endl << std::endl;

	FragTrap clap("Clap");
	FragTrap robert("Robert");
	ScavTrap scav("TOTO");
	ScavTrap trap("LOLO");
	NinjaTrap koko("Naruto");
	NinjaTrap kiki("Sasuke");



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


	std::cout << std::endl << std::endl << "NinTrap  play : " << std::endl << std::endl;
	koko.ninjaShoebox(clap);
	koko.ninjaShoebox(kiki);
	koko.ninjaShoebox(scav);
	koko.ninjaShoebox(trap);

	std::cout << std::endl << std::endl << "Destroy Obj :" << std::endl << std::endl;
}