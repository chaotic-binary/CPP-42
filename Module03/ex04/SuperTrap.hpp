#ifndef SUPERTRAP_H
# define SUPERTRAP_H

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class	SuperTrap : public virtual FragTrap, public virtual NinjaTrap
{
public:
	SuperTrap(void);
	SuperTrap(const std::string & name);
	SuperTrap(SuperTrap const & src);
	~SuperTrap(void);
	SuperTrap & operator=(SuperTrap const & rhs);

	virtual void	rangedAttack(std::string const &target) const;
	virtual void	meleeAttack(std::string const &target) const;
};

#endif