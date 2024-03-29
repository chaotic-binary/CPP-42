#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void) {
	std::cout << "\nTime to say goodbye to ";
	_printLog();
	std::cout << std::endl;
}

ScavTrap::ScavTrap(void) : ClapTrap(SC) {
	std::cout << "Default ScavTrap came to this World!\n";
}

ScavTrap::ScavTrap(const std::string & name) : \
	 ClapTrap(name, SC, 100, 100, 50, 50, 1, 20, 15, 3) {
	_printLog();
	std::cout << " is our new player!\n";
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
	std::cout << "This is a clone of ScavTrap!\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
	ClapTrap::operator=(rhs);
	return (*this);
}

void	ScavTrap::rangedAttack(std::string const &target) const{
	ClapTrap::rangedAttack(target);
	std::cout << "D'oh! D'ah! Oof! Ow! D'oh!\n\n";
}

void	ScavTrap::meleeAttack(std::string const &target) const {
	ClapTrap::meleeAttack(target);
	std::cout << "AHHHHHHHHHHHHHHHHHHHHHH!\n\n";
}

void	ScavTrap::challengeNewcomer(std::string const & target) const
{
	const std::string challenges[] = {	"Let's see are you worthy, Newcomer! Can you exit Vim?",
										 "I want free samples of your inner demons. Now!",
										 "I need to eat an entire snowman! Hurry up!",
										 "Find me a box within a box filled with cute tiny boxes.",
										 "Tell me a joke, Newcomer! If you make me smile, I let you pass." };

	std::cout << std::endl;
	_printLog();
	std::cout << " challenged " << target << " with this task:\n";
	std::cout << challenges[std::rand() % 5] << std::endl;
}