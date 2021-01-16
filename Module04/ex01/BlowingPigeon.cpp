#include "BlowingPigeon.hpp"

BlowingPigeon::BlowingPigeon() \
	: AWeapon("Blowing Pigeon", 15, 20)
{}

BlowingPigeon::~BlowingPigeon()
{}

BlowingPigeon::BlowingPigeon(const BlowingPigeon &copy) \
	: AWeapon(copy)
{}

BlowingPigeon	&BlowingPigeon::operator=(const BlowingPigeon &copy)
{
	AWeapon::operator=(copy);
	return (*this);
}

void	BlowingPigeon::attack(void) const
{
	std::cout << "* coo coo coo *\n";
}