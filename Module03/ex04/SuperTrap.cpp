#include "SuperTrap.hpp"

SuperTrap::~SuperTrap(void) {
	std::cout << "\nYou was special, we will miss you, ";
	_printLog();
	std::cout << std::endl;
}

SuperTrap::SuperTrap(void) : ClapTrap(SP) {
	std::cout << "Default SuperTrap came to this World!\n";
}

SuperTrap::SuperTrap(const std::string & name) : \
	ClapTrap(name, SP, 100, 100, 120, 120, 1, 60, 20, 5),
	FragTrap(name),
	NinjaTrap(name) {
	_printLog();
	std::cout << ": I am " << name << ", a perrrfect creature!, I am a SuperTrap\n";
}

SuperTrap::SuperTrap(SuperTrap const & src) : FragTrap(src), NinjaTrap(src) {
	std::cout << "This is a clone of SuperTrap!\n";
}

SuperTrap & SuperTrap::operator=(SuperTrap const & rhs) {
    ClapTrap::operator=(rhs);
	return (*this);
}

void SuperTrap::meleeAttack(std::string const & target) const {
	NinjaTrap::meleeAttack(target);
}

void SuperTrap::rangedAttack(std::string const & target) const {
	FragTrap::rangedAttack(target);
}