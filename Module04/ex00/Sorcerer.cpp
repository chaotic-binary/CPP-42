#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(const std::string &name, const std::string &title) :
	_name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &copy) : \
	_name(copy._name), _title(copy._title)
{
}

Sorcerer	&Sorcerer::operator=(const Sorcerer &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_title = copy._title;
	}
	return (*this);
}

const std::string&		Sorcerer::getName() const
{
	return (this->_name);
}

const std::string&		Sorcerer::getTitle() const
{
	return (this->_title);
}

void	Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::ostream	&operator<<(std::ostream &os, Sorcerer const &sorcerer)
{
	os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies!" << std::endl;
	return (os);
}