#include "RadScorpion.hpp"

RadScorpion::RadScorpion() \
	: Enemy(80, "Rad Scorpion")
{
	std::cout << "* click click click *\n";
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *\n";
}

RadScorpion::RadScorpion(const RadScorpion &copy) \
	: Enemy(copy)
{
	std::cout << "* click click click *\n";
}

RadScorpion	&RadScorpion::operator=(const RadScorpion &copy)
{
	Enemy::operator=(copy);
	return (*this);
}
