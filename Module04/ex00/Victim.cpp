#include "Victim.hpp"

Victim::Victim() : _name("Victim")
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::Victim(const std::string &name) : _name(name)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

Victim::Victim(const Victim &copy) : _name(copy._name)
{
}

Victim	&Victim::operator=(const Victim &copy)
{
	this->_name = copy._name;
	return (*this);
}

const std::string&		Victim::getName(void) const
{
	return (this->_name);
}

void	Victim::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Victim const &victim)
{
	os << "I'm " << victim.getName() << " and I like otters!" << std::endl;
	return (os);
}