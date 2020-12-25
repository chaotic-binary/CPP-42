#include "FragTrap.hpp"

FragTrap::~FragTrap(void) {
	std::cout << "\nGame over, ";
	_printLog();
	std::cout << std::endl;
}

FragTrap::FragTrap(void) : ClapTrap(FR) {
	std::cout << "Default FragTrap came to this World!\n";
}

FragTrap::FragTrap(const std::string & name) : \
	ClapTrap(name, FR, 100, 100, 100, 100, 1, 30, 20, 5) {
	_printLog();
	std::cout << " is joining the game!\n";
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src) {
	std::cout << "This is a clone of FragTrap!\n";
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
    ClapTrap::operator=(rhs);
	return (*this);
}

void	FragTrap::rangedAttack(std::string const &target) const{
	_attackMessage('R', target);
	std::cout << "Ha-HA!\n\n";
}

void	FragTrap::meleeAttack(std::string const &target) const {
	_attackMessage('M', target);
	std::cout << "BOOYAH!!\n\n";
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	const std::string attacks[] = {	"Soft kitty is sleeping on your knees, don't you dare to move!",
									"Watch out! Sharks with legs!",
									"You've accidentally bought Passive-aggressive Post-it notes. F.",
									"Catbite attack: Purr, human meat is so delicious!",
									"You locked up in the cinema with Russian movies on repeat :(" };

	if (_energyPoints < 25) {
		std::cout << std::endl;
		_printLog();
		std::cout << ": Not enough energy for vaulthunter.exe!\n";
		return;
	}
	_energyPoints -= 25;
	std::cout << std::endl;
	_printLog();
	std::cout << " used vaulthunter.exe on " << target << std::endl;
	unsigned int i = std::rand() % 5;
	std::cout << attacks[i] << std::endl << i * (std::rand() % 10) << " points of damage caused\n";
}