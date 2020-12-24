#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

# define FRmodel "FR4G-TP"
# define SCmodel "SC4V-TP"
# define NNJmodel "NN7A-TP"
# define SPmodel "SP3R-TP"
# define CLmodel "CL4P-TP"

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap(const std::string &name,
			 const std::string &model,
			 unsigned int hitPoints,
			 unsigned int maxHitPoints,
			 unsigned int energyPoints,
			 unsigned int maxEnergyPoints,
			 unsigned int level,
			 unsigned int meleeAttackDamage,
			 unsigned int rangedAttackDamage,
			 unsigned int armor);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &copy);

	virtual void	rangedAttack(std::string const &target) const;
	virtual void	meleeAttack(std::string const &target) const;
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	const std::string &getName() const;
	const std::string &getModel() const;

protected:
	void	_printLog() const;
	void	_attackMessage(char mode, std::string const &target) const;
	void	_resourceMessage(char mode) const;

	ClapTrap(const std::string &model);

    unsigned int getHitPoints() const;
    unsigned int getMaxHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getMaxEnergyPoints() const;
    unsigned int getLevel() const;
    unsigned int getMeleeAttackDamage() const;
    unsigned int getRangedAttackDamage() const;
    unsigned int getArmor() const;

    void setName(const std::string &name);
    void setHitPoints(unsigned int value);
    void setMaxHitPoints(unsigned int value);
    void setEnergyPoints(unsigned int value);
    void setMaxEnergyPoints(unsigned int value);
    void setLevel(unsigned int value);
    void setMeleeAttackDamage(unsigned int value);
    void setRangedAttackDamage(unsigned int value);
    void setArmor(unsigned int value);

	const std::string	_name;
	unsigned int		_hitPoints;
	unsigned int		_maxHitPoints;
	unsigned int		_energyPoints;
	unsigned int		_maxEnergyPoints;
	unsigned int		_level;
	unsigned int		_meleeAttackDamage;
	unsigned int		_rangedAttackDamage;
	unsigned int		_armor;

	const std::string   _model;
};

#endif
