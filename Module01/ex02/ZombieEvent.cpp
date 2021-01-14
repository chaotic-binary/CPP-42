#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
	_type = "Undefined";
}

ZombieEvent::~ZombieEvent() {
	std::cout << "\nOops, it's sunlight, zombies are gone!\n";
}

void ZombieEvent::setZombieType(const std::string & type) {
	_type = type;
}

Zombie* ZombieEvent::newZombie(const std::string & name) {
	return (new Zombie(name, _type));
}

static unsigned int	random_i(int min, int max) {
	return (min + (std::rand() % max));
}

std::string ZombieEvent::_makeRandomName() {
	std::string res;
	const char vowels[] = "aeiou";
	const char consonants[] = "bcdfghjklmnpqrstvwxyz";
	const int len = random_i(5, 15);

	for (int i = 0; i < len; i++) {
		if (i % (random_i(2, 2)) == 0)
			res += consonants[random_i(0, 21)];
		else
			res += vowels[random_i(0, 5)];
	}
	res[0] = toupper(res[0]);
	return res;
}

void ZombieEvent::randomChump(void)
{
	Zombie chump = Zombie(_makeRandomName(), "Random");
	chump.announce();
}
