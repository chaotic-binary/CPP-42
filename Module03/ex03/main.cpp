#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int	main( void ) {
	srand(time(0));
	
	NinjaTrap FireNinja("FireNinja");
	NinjaTrap SnowNinja("SnowNinja");
	ScavTrap Ironman("Ironman");
	std::cout << std::endl;
	Ironman.takeDamage(5);
	SnowNinja.takeDamage(15);
	FireNinja.ninjaShoebox(SnowNinja);
	FireNinja.ninjaShoebox(FireNinja);
	SnowNinja.ninjaShoebox(Ironman);
	SnowNinja.beRepaired(200);
	return 0;
}
