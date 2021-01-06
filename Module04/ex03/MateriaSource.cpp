#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = 0;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	_deepCopy(copy);
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	if (this != &copy)
		_deepCopy(copy);
	return (*this);
}

void			MateriaSource::learnMateria(AMateria* item)
{
	int i = -1;
	while (++i < 4)
	{
		if (!this->_materia[i])
		{
			this->_materia[i] = item->clone();
			return ;
		}
	}
	std::cout << "No room for new items\n";
}

AMateria* 		MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	std::cout << "Nothing found\n";
	return 0;
}

void			MateriaSource::_deepCopy(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
		if (this->_materia[i])
			delete this->_materia[i];
	for (int i = 0; i < 4; i++)
	{
		if (copy._materia[i])
			this->_materia[i] = copy._materia[i]->clone();
		else
			_materia[i] = NULL;
	}
}