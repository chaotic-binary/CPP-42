#include "FragTrap.hpp"

FragTrap::~FragTrap(void) {
	std::cout << "\nGame over, FR4G-TP " << this->_name << std::endl;
}

FragTrap::FragTrap(void) {
	std::cout << "Default FragTrap came to this World!\n";
}

FragTrap::FragTrap(const std::string &name) : \
	_name(name), \
	_hitPoints(100), \
	_maxHitPoints(100), \
	_energyPoints(100), \
	_maxEnergyPoints(100), \
	_level(1), \
	_meleeAttackDamage(30), \
	_rangedAttackDamage(20), \
	_armor(5) {
	_printLog();
	std::cout << " is joining the game!\n";
}

FragTrap::FragTrap(FragTrap const & src) : \
	_name(src._name), \
	_hitPoints (src._hitPoints), _maxHitPoints (src._maxHitPoints), \
	_energyPoints (src._energyPoints), _maxEnergyPoints (src._maxEnergyPoints), \
	_level(src._level), \
	_meleeAttackDamage(src._meleeAttackDamage), \
	_rangedAttackDamage (src._rangedAttackDamage), \
	_armor(src._armor) {
	std::cout << "New clone of FragTrap!\n";
}

FragTrap & FragTrap::operator=(FragTrap const & rhs) {
	if (this == &rhs)
		return (*this);
	*(const_cast<std::string*>(&_name)) = rhs._name;
	_hitPoints = rhs._hitPoints;
	_maxHitPoints = rhs._maxHitPoints;
	_energyPoints = rhs._energyPoints;
	_maxEnergyPoints = rhs._maxEnergyPoints;
	_level = rhs._level;
	_meleeAttackDamage = rhs._meleeAttackDamage;
	_rangedAttackDamage = rhs._rangedAttackDamage;
	_armor = rhs._armor;
	return (*this);
}

void	FragTrap::rangedAttack(std::string const & target) const {
	_printLog();
	std::cout << " attacks " << target << " at range, causing " \
			<< _rangedAttackDamage << " points of damage using special FR4G-TP powers! \n";
	std::cout << "Ha-HA!\n";
}

void	FragTrap::meleeAttack(std::string const & target) const {
	_printLog();
	std::cout << " attacks " << target << " causing " << _meleeAttackDamage << \
				" points of melee damage using special FR4G-TP fight technique\n";
	std::cout << "BOOYAH!!\n";
}

void	FragTrap::_printLog() const {
	std::cout << "\nFR4G-TP " << _name;
}

void	FragTrap::_resourceMessage(char mode) const {
	std::cout << _name;
	if (mode == 'H')
		std::cout << " now has " << _hitPoints << "/" << _maxHitPoints << " HP left\n";
	if (mode == 'E')
		std::cout << "'s energy level is " << _energyPoints << "/" <<  _maxEnergyPoints << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (amount <= _armor) {
		_printLog();
		std::cout << " was protected by his shiny armor!\n";
		return ;
	}
	else
		amount -= _armor;
	(amount < _hitPoints) ? _hitPoints -= amount : _hitPoints = 0;
	_printLog();
	std::cout << " took " << amount << " points of damage\n";
	_resourceMessage('H');
}

static void	repare_value(unsigned int &value, const unsigned int max, unsigned int amount) {
	amount = std::min(amount, max - value);
	value += amount;
	std::cout << "\nFairies got a magic potion that has force of " << amount << " ponies!\n";
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == _maxHitPoints && _energyPoints == _maxEnergyPoints)
		std::cout << "\nNo need of healing, " << _name << " is already full of life\n";
	else if (_hitPoints == _maxHitPoints)
		repare_value(_energyPoints, _maxEnergyPoints, amount);
	else if (_energyPoints == _maxEnergyPoints)
		repare_value(_hitPoints, _maxHitPoints, amount);
	else
	{
		std::cout << std::endl;
		std::cout << "What shall be repaired?\n";
		_resourceMessage('H');
		_resourceMessage('E');
		std::cout << "Put 1 for HP, 2 for energy\n";
		int value = 0;
		if (std::cin.eof()) {
			std::cerr << "Input error!\n";
			exit(0);
		}
		if (!(std::cin >> value)) {
			std::cerr << "Something is wrong with your input\n";
			if (std::cin.bad())
				exit(0);
		}
		else if (value == 1)
			repare_value(this->_hitPoints, this->_maxHitPoints, amount);
		else if (value == 2)
			repare_value(this->_energyPoints, this->_maxEnergyPoints, amount);
		else
			std::cerr << "Incorrect number\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	_resourceMessage('H');
	_resourceMessage('E');
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target) {
	const std::string attacks[] = {	"Soft kitty is sleeping on your knees, don't you dare to move!",
									"Watch out! Sharks with legs!",
									"You've accidentally bought Passive-aggressive Post-it notes. F.",
									"Catbite attack: Purr, human meat is so delicious!",
									"You locked up in the cinema with Russian movies on repeat :(" };

	if (_energyPoints < 25) {
		_printLog();
		std::cout << ": Not enough energy for vaulthunter.exe!\n";
		return;
	}
	_energyPoints -= 25;
	_printLog();
	std::cout << " used vaulthunter.exe on " << target << std::endl;
	unsigned int i = std::rand() % 5;
	std::cout << attacks[i] << std::endl << i * (std::rand() % 10) << " points of damage caused\n";
}