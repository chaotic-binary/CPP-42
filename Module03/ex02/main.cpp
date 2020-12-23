#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main( void ) {
	FragTrap CruelCat ("CruelCat");
	ScavTrap BoringHuman ("Bob");
	std::cout << std::endl;
	CruelCat.rangedAttack("wall");
	BoringHuman.meleeAttack("his boss");
	CruelCat.takeDamage(5);
	BoringHuman.takeDamage(3);
	BoringHuman.takeDamage(15);
	for (int i = 0; i < 5; ++i) {
	CruelCat.vaulthunter_dot_exe("Bob");
	}
	for (int i = 0; i < 3; ++i) {
		BoringHuman.challengeNewcomer("some guy");
	}
	BoringHuman.beRepaired(200);
	CruelCat.takeDamage(25);
	CruelCat.beRepaired(200);
	return 0;
}