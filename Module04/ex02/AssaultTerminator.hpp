#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>
#include "ISpaceMarine.hpp"

class	AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(const AssaultTerminator &copy);
	virtual ~AssaultTerminator();
	AssaultTerminator &operator=(const AssaultTerminator &copy);

	virtual ISpaceMarine*	clone() const;
	virtual void	battleCry() const;
	virtual void	rangedAttack() const;
	virtual void	meleeAttack() const;
};

#endif
