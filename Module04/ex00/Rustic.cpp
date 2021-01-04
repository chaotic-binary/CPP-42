
#include "Rustic.hpp"

Rustic::Rustic() : Victim("Rustic")
{
	std::cout << "Pssss" << std::endl;
}

Rustic::Rustic(const std::string &name) : Victim(name)
{
	std::cout << "Pssss" << std::endl;
}

Rustic::~Rustic()
{
	std::cout << "Ohhh..." << std::endl;
}

Rustic::Rustic(const Rustic &copy) : Victim(copy)
{
	std::cout << "Pssss" << std::endl;
}

Rustic	&Rustic::operator=(const Rustic &copy)
{
	Victim::operator=(copy);
	return (*this);
}

void	Rustic::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a cloud!" << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Rustic const &rustic)
{
	os << "I'm " << rustic.getName() << " and I like food!" << std::endl;
	return (os);
}