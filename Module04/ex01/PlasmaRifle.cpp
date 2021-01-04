#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() \
	: AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &copy) \
	: AWeapon(copy)
{
}

PlasmaRifle	&PlasmaRifle::operator=(const PlasmaRifle &copy)
{
	AWeapon::operator=(copy);
	return (*this);
}

void	PlasmaRifle::attack(void) const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}