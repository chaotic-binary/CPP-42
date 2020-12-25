#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void) {
	std::cout << "\nTime to say goodbye to SC4V-TP " << _name << std::endl;
}

ScavTrap::ScavTrap(void) {
	std::cout << "Default ScavTrap came to this World!\n";
}

ScavTrap::ScavTrap(const std::string &name) : \
											_name(name),
											_hitPoints(100),
											_maxHitPoints(100),
											_energyPoints(50),
											_maxEnergyPoints(50),
											_level(1),
											_meleeAttackDamage(20),
											_rangedAttackDamage(15),
											_armor(3) {
	_printLog();
	std::cout << " is our new player!\n";
}

ScavTrap::ScavTrap(ScavTrap const & src) : 	\
											_name(src._name), \
											_hitPoints (src._hitPoints), _maxHitPoints (src._maxHitPoints), \
											_energyPoints (src._energyPoints), _maxEnergyPoints (src._maxEnergyPoints), \
											_level(src._level), \
											_meleeAttackDamage(src._meleeAttackDamage), \
											_rangedAttackDamage (src._rangedAttackDamage), \
											_armor(src._armor) {
	std::cout << "New clone of ScavTrap!\n";
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
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

void	ScavTrap::rangedAttack(std::string const & target) const {
	_printLog();
	std::cout << " attacks " << target << " at range, causing " \
			<< _rangedAttackDamage << " points of damage using special SC4V-TP powers!\n";
	std::cout << "D'oh! D'ah! Oof! Ow! D'oh!\n";
}

void	ScavTrap::meleeAttack(std::string const & target) const {
	_printLog();
	std::cout << " attacks " << target << " causing " << _meleeAttackDamage << \
				" points of melee damage using special fight SC4V-TP technique\n";
	std::cout << "AHHHHHHHHHHHHHHHHHHHHHH!\n";
}

void	ScavTrap::_printLog() const {
	std::cout << "\nSC4V-TP " << _name;
}

void	ScavTrap::_resourceMessage(char mode) const {
	std::cout << _name;
	if (mode == 'H')
		std::cout << " now has " << _hitPoints << "/" << _maxHitPoints << " HP left\n";
	if (mode == 'E')
		std::cout << "'s energy level is " << _energyPoints << "/" << _maxEnergyPoints << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (amount <= _armor) {
		_printLog();
		std::cout << "'s armor worked well! No damage caused!\n";
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

void	ScavTrap::beRepaired(unsigned int amount) {
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
			repare_value(_hitPoints, _maxHitPoints, amount);
		else if (value == 2)
			repare_value(_energyPoints, _maxEnergyPoints, amount);
		else
			std::cerr << "Incorrect number\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	_resourceMessage('H');
	_resourceMessage('E');
}

void	ScavTrap::challengeNewcomer(std::string const & target) const
{
	const std::string challenges[] = {	"Let's see are you worthy, Newcomer! Can you exit Vim?",
										 "I want free samples of your inner demons. Now!",
										 "I need to eat an entire snowman! Hurry up!",
										 "Find me a box within a box filled with cute tiny boxes.",
										 "Tell me a joke, Newcomer! If you make me smile, I let you pass." };

	_printLog();
	std::cout << " challenged " << target << " with this task:\n";
	std::cout << challenges[std::rand() % 5] << std::endl;
}