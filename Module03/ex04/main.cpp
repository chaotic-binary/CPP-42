#include "ScavTrap.hpp"
#include "SuperTrap.hpp"

int	main( void ) {
	SuperTrap SuperCat ("SuperCat");
	SuperTrap SuperHuman ("Bob");
	std::cout << std::endl;
	SuperCat.rangedAttack("Space");
	SuperCat.meleeAttack("World");
	SuperCat.takeDamage(5);
	SuperHuman.takeDamage(15);
	for (int i = 0; i < 3; ++i) {
		SuperCat.vaulthunter_dot_exe("Bob");
	}
	SuperCat.ninjaShoebox(SuperHuman);
	SuperHuman.ninjaShoebox(SuperHuman);
	NinjaTrap FireNinja("FireNinja");
	SuperHuman.ninjaShoebox(FireNinja);
	ScavTrap Ironman("Ironman");
	SuperCat.ninjaShoebox(Ironman);
	FragTrap BoringHuman ("John");
	SuperCat.ninjaShoebox(BoringHuman);
	SuperHuman.beRepaired(200);
	return 0;
}