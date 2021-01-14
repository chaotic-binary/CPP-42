#include "Zombie.hpp"

Zombie::Zombie(const std::string & name, const std::string & type) \
	: _name(name), _type(type) {}

Zombie::~Zombie() {
	std::cout << _name << ": I'll be back!" << std::endl;
}

void Zombie::announce(void) const{
	std::cout << "<" << _name << " (" << _type << ")> " << "Braiiiiiiinnnssss...\n";
}
