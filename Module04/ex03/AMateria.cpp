#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const &type) \
	: _type(type), _xp(0)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const AMateria &copy) \
	: _type(copy._type), _xp(copy._xp)
{
}

AMateria	&AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
	{
		this->_xp = copy._xp;
	}
	return (*this);
}

std::string	const		&AMateria::getType(void) const
{
	return (this->_type);
}

unsigned int			AMateria::getXP(void) const
{
	return (this->_xp);
}

void				AMateria::use(ICharacter& target)
{
	(void)target;
	this->_xp += 10;
}