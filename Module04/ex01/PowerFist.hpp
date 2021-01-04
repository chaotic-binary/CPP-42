#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>
# include "AWeapon.hpp"

class PowerFist  : public AWeapon

{
public:
	PowerFist();
	PowerFist(const PowerFist &copy);
	virtual ~PowerFist();
	PowerFist &operator=(const PowerFist &copy);

	virtual void			attack() const;
};

#endif
