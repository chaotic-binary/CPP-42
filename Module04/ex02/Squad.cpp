#include "Squad.hpp"

Squad::Squad() \
	: _unitCount(0), _units(nullptr)
{
}

Squad::~Squad()
{
	t_unitlist *tmp;
	t_unitlist *unitptr = this->_units;
	while (unitptr)
	{
		delete unitptr->unit;
		tmp = unitptr->next;
		delete unitptr;
		unitptr = tmp;
	}
	this->_units = nullptr;
	this->_unitCount = 0;
}

Squad::Squad(const Squad &copy)
{
	deepCopy(copy);
}

Squad	&Squad::operator=(const Squad &copy)
{
	if (this != &copy)
	{
		deepCopy(copy);
	}
	return (*this);
}

int				Squad::getCount() const
{
	return (this->_unitCount);
}

ISpaceMarine*	Squad::getUnit(int index) const
{
	if (this->_unitCount <= index)
		return (nullptr);
	t_unitlist *unitptr = this->_units;
	for (int i = 0; i < index; ++i)
		unitptr = unitptr->next;
	return (unitptr->unit);
}

int				Squad::push(ISpaceMarine* unit)
{
	if (!unit)
		return (_unitCount);
	if (!this->_units)
	{
		this->_units = new t_unitlist;
		this->_units->unit = unit;
		this->_units->next = nullptr;
		return (++_unitCount);
	}
	t_unitlist *unitptr = this->_units;
	for (int i = 0; i < _unitCount; ++i)
	{
		if (unit == unitptr->unit)
			return (_unitCount);
		if (unitptr->next)
			unitptr = unitptr->next;
	}
	unitptr->next = new t_unitlist;
	unitptr->next->unit = unit;
	unitptr->next->next = nullptr;

	/*unitptr = this->_units;
	while (unitptr)
	{	std::cout << "Unit :";
		unitptr->unit->battleCry();
	unitptr = unitptr->next;}*/
	return (++_unitCount);
}

void			Squad::deepCopy(const Squad &copy)
{
	t_unitlist *tmp;
	t_unitlist *unitptr = this->_units;
	while (unitptr)
	{
		tmp = unitptr->next;
		delete unitptr;
		unitptr = tmp;
	}
	this->_units = nullptr;
	this->_unitCount = 0;
	t_unitlist *copyptr = copy._units;
	for (int i = 0; i < copy._unitCount; ++i)
	{
		this->push(copyptr->unit->clone());
		copyptr = copyptr->next;
	}
}

