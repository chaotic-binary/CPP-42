#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	virtual ~MateriaSource();
	MateriaSource &operator=(const MateriaSource &copy);

	virtual void		learnMateria(AMateria*);
	virtual AMateria*	createMateria(std::string const & type);

private:
	AMateria		*_materia[4];
	void			_deepCopy(const MateriaSource &copy);
};

#endif
