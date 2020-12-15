#include "ZombieEvent.hpp"

int	main(void)
{
	ZombieEvent event = ZombieEvent();

	std::cout << "Zombies on the Heap:\n";
	Zombie* zombie1 = event.newZombie("First");
	zombie1->announce();

	event.setZombieType("Lazy");
	Zombie* zombie2 = event.newZombie("Uuuuu");
	zombie2->announce();
	
	event.setZombieType("Strange");
	Zombie* zombie3 = event.newZombie("Shshshsh");
	zombie3->announce();

	std::cout << "\nRandom zombies on the Stack:\n";
	for (int i = 0; i < 7; i++)
	{
		event.randomChump();
		std::cout << std::endl;
	}
	std::cout << "Say Goodbye to the Zombies on the Heap:\n";
	delete zombie1;
	delete zombie2;
	delete zombie3;
	return (0);
}