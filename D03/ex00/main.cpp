#include "FragTrap.hpp"

int main(void)
{
	FragTrap clap("Clap");
	FragTrap robert("Robert");


	clap.rangedAttack("Robert");
	robert.takeDamage(20);
	clap.meleeAttack("Robert");
	robert.takeDamage(30);
	clap.meleeAttack("Robert");
	robert.takeDamage(5);
	clap.vaulthunter_dot_execlang__ ("Robert");
	clap.vaulthunter_dot_execlang__ ("Robert");
	clap.vaulthunter_dot_execlang__ ("Robert");

}