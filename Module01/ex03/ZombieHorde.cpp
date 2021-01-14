#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) {
	this->_n = n;
	if (n < 0) {
		std::cerr << "Invalid number!\n";
		this->_n = 0;
		return ;
	}
	try {
		this->_horde = new Zombie[n];
	} catch (std::exception &e) {
		std::cerr << "Too many zombies!\n";
		return ;
	}
	for (int i = 0; i < n; i++) {
		this->_horde[i] = Zombie(_makeRandomName(), "Random");
	}
}

ZombieHorde::~ZombieHorde() {
	delete[] _horde;
	std::cout << "\nOops, it's sunlight, zombies are gone!\n";
}

static unsigned int	random_i(int min, int max) {
	return (min + (std::rand() % max));
}

std::string ZombieHorde::_makeRandomName() {
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

void ZombieHorde::announce(void) const {
	for (int i = 0; i < this->_n; i++) {
		this->_horde[i].announce();
	}
}
