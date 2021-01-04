#include "SuperMutant.hpp"

SuperMutant::SuperMutant() \
	: Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &copy) \
	: Enemy(copy)
{
}

SuperMutant	&SuperMutant::operator=(const SuperMutant &copy)
{
	Enemy::operator=(copy);
	return (*this);
}

void	SuperMutant::takeDamage(int amount)
{
	amount	-= 3;
	Enemy::takeDamage(amount);
}