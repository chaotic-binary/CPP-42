#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <cstdlib>

class ZombieEvent
{
	public:
		ZombieEvent(void);
		~ZombieEvent();

		void	setZombieType(const std::string & type);
		Zombie*	newZombie(const std::string & name);
		void	randomChump(void);

	private:
		std::string _type;
		std::string _makeRandomName(void);
};

#endif
