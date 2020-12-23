#include "FragTrap.hpp"

int	main( void ) {
	FragTrap CruelCat ("CruelCat");
    FragTrap BoringHuman ("Bob");
	CruelCat.rangedAttack("wall");
	BoringHuman.meleeAttack("his boss");
	CruelCat.takeDamage(5);
	BoringHuman.takeDamage(15);
	for (int i = 0; i < 5; ++i) {
		CruelCat.vaulthunter_dot_exe("Bob");
	}
	BoringHuman.beRepaired(200);
	CruelCat.takeDamage(25);
	CruelCat.beRepaired(200);
	/*CruelCat.takeDamage(25);
	CruelCat.beRepaired(200);
	CruelCat.beRepaired(200);
	CruelCat.beRepaired(200);*/
	return 0;
}