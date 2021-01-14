#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(const std::string & name, const std::string & type) \
	: _name(name), _type(type) {}

Zombie::~Zombie() {}

void Zombie::announce(void) const {
	std::cout << "<" << _name << " (" << _type << ")> " << "Braiiiiiiinnnssss...\n";
}
