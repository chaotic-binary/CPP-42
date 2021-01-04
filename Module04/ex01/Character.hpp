#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
	Character();
	Character(std::string const &name);
	Character(const Character &copy);
	~Character();
	Character &operator=(const Character &copy);

	void	recoverAP();
	void	equip(AWeapon*);
	void	attack(Enemy*);

	std::string const 	&getName() const;
	int					getAP(void) const;
	AWeapon				*getWeapon(void) const;

private:
	std::string _name;
	int			_ap;
	AWeapon		*_weapon;
};

std::ostream	&operator<<(std::ostream &os, Character const &character);

#endif
