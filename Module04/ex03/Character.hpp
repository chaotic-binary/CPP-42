#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
#include "ICharacter.hpp"

class Character
{
public:
	Character();
	Character(const Character &copy);
	~Character();
	Character &operator=(const Character &copy);

private:
};

#endif
