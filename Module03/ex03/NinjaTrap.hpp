#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	NinjaTrap : public ClapTrap
{
public:
	NinjaTrap(void);
	NinjaTrap(const std::string & name);
	NinjaTrap(NinjaTrap const & src);
	virtual ~NinjaTrap(void);
	NinjaTrap & operator=(NinjaTrap const & rhs);

	virtual void	rangedAttack(std::string const &target) const;
	virtual void	meleeAttack(std::string const &target) const;

	void ninjaShoebox(ClapTrap const & target) const;
	void ninjaShoebox(FragTrap const & target) const;
	void ninjaShoebox(ScavTrap const & target) const;
	void ninjaShoebox(NinjaTrap const & target) const;

private:
	void shoeboxAttackMessage(ClapTrap const & target) const;
};

#endif