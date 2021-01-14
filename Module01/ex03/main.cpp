#include "ZombieHorde.hpp"

int	main(void)
{
	srand(time(0));

	ZombieHorde horde(3);
	horde.announce();

	std::cout << std::endl;

	ZombieHorde invalid(-1);
	invalid.announce();
	return (0);
}
