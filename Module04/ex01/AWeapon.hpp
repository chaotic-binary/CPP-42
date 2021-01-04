#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
public:
	AWeapon();
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(const AWeapon &copy);
	virtual ~AWeapon();
	AWeapon &operator=(const AWeapon &copy);

	std::string const		&getName() const;
	int						getDamage() const;
	int						getAPCost() const;

	virtual void			attack() const = 0;

private:
	std::string		_name;
	int				_dmg;
	int				_ap;
};

#endif
