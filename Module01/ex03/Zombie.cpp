#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {}

Zombie::~Zombie() {}

void Zombie::announce(void) const {
	std::cout << "<" << _name << " (" << _type << ")> " << "Braiiiiiiinnnssss...\n";
}
