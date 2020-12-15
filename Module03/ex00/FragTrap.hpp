#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include <iostream>

class	FragTrap
{
	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap & operator=(FragTrap const & rhs);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	vaulthunter_dot_exe(std::string const & target);

	private:
		std::string			_name;
		unsigned int		_hitPoints;
		unsigned int		_maxHitPoints;
		unsigned int		_energyPoints;
		unsigned int		_maxEnergyPoints;
		unsigned int		_level;
		unsigned int		_meleeAttackDamage;
		unsigned int		_rangedAttackDamage;
		unsigned int		_armor;

		void				_resourceMessage(int mode) const;
};

#endif