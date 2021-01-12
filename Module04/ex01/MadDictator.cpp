#include "MadDictator.hpp"

MadDictator::MadDictator() \
	: Enemy(100, "Mad Dictator")
{
	std::cout << "* Obey! *\n";
}

MadDictator::~MadDictator()
{
	std::cout << "* chokes in blood *\n";
}

MadDictator::MadDictator(const MadDictator &copy) \
	: Enemy(copy)
{
	std::cout << "* Obey! *\n";
}

MadDictator	&MadDictator::operator=(const MadDictator &copy)
{
	Enemy::operator=(copy);
	return (*this);
}
