#ifndef MADDICTATOR_HPP
# define MADDICTATOR_HPP

# include <iostream>
# include "Enemy.hpp"

class MadDictator : public Enemy
{
public:
	MadDictator();
	MadDictator(const MadDictator &copy);
	virtual ~MadDictator();
	MadDictator &operator=(const MadDictator &copy);
};

#endif
