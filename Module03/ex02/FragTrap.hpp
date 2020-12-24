#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);
		FragTrap & operator=(FragTrap const & rhs);

		virtual void	rangedAttack(std::string const &target) const;
		virtual void	meleeAttack(std::string const &target) const;

		void	vaulthunter_dot_exe(std::string const & target);
};

#endif