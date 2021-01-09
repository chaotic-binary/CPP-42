#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

enum {
	FR = 0,
	SC = 1,
	NN = 2,
	SP = 3,
	CL = 4
};

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap(const std::string &name,
			const unsigned char	model,
			unsigned int hitPoints,
			unsigned int maxHitPoints,
			unsigned int energyPoints,
			unsigned int maxEnergyPoints,
			unsigned int level,
			unsigned int meleeAttackDamage,
			unsigned int rangedAttackDamage,
			unsigned int armor);
	virtual ~ClapTrap();
	ClapTrap &operator=(const ClapTrap &copy);

	virtual void	rangedAttack(std::string const &target) const;
	virtual void	meleeAttack(std::string const &target) const;
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	const std::string &getName() const;
	unsigned char getModel() const;

protected:
	ClapTrap(const unsigned char model);

	void	_printLog() const;

	const std::string	_name;
	unsigned int		_hitPoints;
	unsigned int		_maxHitPoints;
	unsigned int		_energyPoints;
	unsigned int		_maxEnergyPoints;
	unsigned int		_level;
	unsigned int		_meleeAttackDamage;
	unsigned int		_rangedAttackDamage;
	unsigned int		_armor;

	const unsigned char	_model;
	static const std::string modelId[];

private:
	void	_attackMessage(char mode, std::string const &target) const;
	void	_resourceMessage(char mode) const;
};

#endif
