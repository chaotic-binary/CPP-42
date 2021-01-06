#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(std::string const & name);
	Character(const Character &copy);
	virtual ~Character();
	Character &operator=(const Character &copy);

	std::string const 	&getName() const;
	void 				equip(AMateria*);
	void 				unequip(int);
	void 				use(int i, ICharacter& target);

private:

	AMateria		*_materia[4];
	std::string		_name;
	void			_deepCopy(const Character &);
	bool			isEquiped(int i);
};

#endif
