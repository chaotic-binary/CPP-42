#ifndef ZOMBIEEVENT_HPP
#define ZOMBIEEVENT_HPP

# include "Zombie.hpp"
# include <cstdlib>

class ZombieEvent
{
	public:
		ZombieEvent(void);
		~ZombieEvent();

		void	setZombieType(std::string type);
		Zombie*	newZombie(std::string name);
		void	randomChump(void);

	private:
		std::string _type;
		std::string _makeRandomName(void);
};

#endif