#ifndef BLOWINGPIGEON_HPP
# define BLOWINGPIGEON_HPP

# include <iostream>
# include "AWeapon.hpp"

class BlowingPigeon : public AWeapon
{
public:
	BlowingPigeon();
	BlowingPigeon(const BlowingPigeon &copy);
	virtual ~BlowingPigeon();
	BlowingPigeon &operator=(const BlowingPigeon &copy);

	virtual void			attack() const;

};

#endif
