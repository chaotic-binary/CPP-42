#ifndef ZOMBIEHORDE_HPP
#define ZOMBIEHORDE_HPP

# include "Zombie.hpp"
# include <cstdlib>

class ZombieHorde
{
	public:
		ZombieHorde(int n);
		~ZombieHorde();

		void announce(void) const;

	private:
		Zombie		*_horde;
		int			_n;
		std::string	_makeRandomName(void);
};

#endif