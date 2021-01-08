#include "Character.hpp"

Character::Character()
{
}

Character::Character(std::string const & name) \
	: _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = 0;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
}

Character::Character(const Character &copy)
{
	_deepCopy(copy);
}

Character	&Character::operator=(const Character &copy)
{
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 4; i++)
	if (this->_materia[i])
		delete this->_materia[i];
	_deepCopy(copy);
	return (*this);
}

std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void				Character::_deepCopy(const Character &copy)
{
	this->_name = std::string(copy.getName());
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i])
			this->_materia[i] = copy._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
}

void 			Character::equip(AMateria* item)
{
	int i = -1;
	while (++i < 4)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = item;
			return ;
		}
	}
	std::cout << "No room for new items\n";
}

void 				Character::unequip(int i)
{
	if (isEquiped(i))
		this->_materia[i] = NULL;
}

void 				Character::use(int i, ICharacter& target)
{
	if (isEquiped(i))
		this->_materia[i]->use(target);
}

bool				Character::isEquiped(int i)
{
	if (i > 3 || i < 0)
	{
		std::cout << "Wrong index\n";
		return false;
	}
	if (this->_materia[i] == NULL)
	{
		std::cout << "There is nothing in this place.\n";
		return false;
	}
	return true;
}