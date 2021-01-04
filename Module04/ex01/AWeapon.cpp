#include "AWeapon.hpp"

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) \
	: _name(name), _dmg(damage), _ap(apcost)
{
}

AWeapon::~AWeapon()
{
}

AWeapon::AWeapon(const AWeapon &copy) \
	: _name(copy._name), _dmg(copy._dmg), _ap(copy._ap)
{
}

AWeapon	&AWeapon::operator=(const AWeapon &copy)
{
	this->_name = copy._name;
	this->_ap = copy._ap;
	this->_dmg = copy._dmg;
	return (*this);
}

std::string const & AWeapon::getName() const
{
	return (this->_name);
}

int	AWeapon::getDamage() const
{
	return (this->_dmg);
}

int	AWeapon::getAPCost() const
{
	return (this->_ap);
}