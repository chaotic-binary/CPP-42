
#include "Peon.hpp"

Peon::Peon() : Victim("Peon")
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const std::string &name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(const Peon &copy) : Victim(copy)
{
	std::cout << "Zog zog." << std::endl;
}

Peon	&Peon::operator=(const Peon &copy)
{
	Victim::operator=(copy);
	return (*this);
}

void	Peon::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a pink pony!" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Peon const &peon)
{
	os << "I'm " << peon.getName() << " and I like otters!" << std::endl;
	return (os);
}