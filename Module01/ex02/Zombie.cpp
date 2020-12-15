#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type) : _name(name), _type(type) {}

Zombie::~Zombie() {
	std::cout << _name << ": I'll be back!" << std::endl;
}

void Zombie::announce(void) const{
	std::cout << "<" << _name << " (" << _type << ")> " << "Braiiiiiiinnnssss...\n";
}
