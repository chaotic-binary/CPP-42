#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include <iostream>

class	ScavTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const std::string & name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap & operator=(ScavTrap const & rhs);

		void	rangedAttack(std::string const & target) const;
		void	meleeAttack(std::string const & target) const;
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	challengeNewcomer(std::string const & target) const;

	private:
		const std::string	_name;
		unsigned int		_hitPoints;
		unsigned int		_maxHitPoints;
		unsigned int		_energyPoints;
		unsigned int		_maxEnergyPoints;
		unsigned int		_level;
		unsigned int		_meleeAttackDamage;
		unsigned int		_rangedAttackDamage;
		unsigned int		_armor;

		void				_printLog() const;
		void				_resourceMessage(char mode) const;
};

#endif