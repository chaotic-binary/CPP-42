#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"

class	NinjaTrap : public virtual ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(const std::string & name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap(void);
	NinjaTrap & operator=(NinjaTrap const & rhs);

	virtual void	meleeAttack(std::string const &target) const;
	void ninjaShoebox(ClapTrap const & target) const;
};

#endif