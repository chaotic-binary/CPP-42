#ifndef NINJATRAP_H
# define NINJATRAP_H

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	SuperTrap;
class	NinjaTrap : public virtual ClapTrap
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
	void ninjaShoebox(SuperTrap const & target) const;

private:
	void shoeboxAttackMessage(ClapTrap const & target) const;
	bool isSame(ClapTrap const *attacker, ClapTrap const *target) const;
};

# include "SuperTrap.hpp"

#endif