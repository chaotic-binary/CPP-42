#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string & name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & rhs);

		virtual void	rangedAttack(std::string const &target) const;
		virtual void	meleeAttack(std::string const &target) const;

		void	challengeNewcomer(std::string const & target) const;
};

#endif