#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"

class	NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(const std::string & name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap(void);
	NinjaTrap & operator=(NinjaTrap const & rhs);

	void ninjaShoebox(ClapTrap const & target) const;
};

#endif