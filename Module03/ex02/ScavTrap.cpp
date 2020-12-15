#include "ScavTrap.hpp"

ScavTrap::~ScavTrap(void) {
	std::cout << "\nTime to say goodbye to SC4V-TP " << this->_name << std::endl;
}

ScavTrap::ScavTrap(void) {}

ScavTrap::ScavTrap(const std::string name) : _name(name) {
	this->_hitPoints = 100;
	this->_maxHitPoints = 100;
	this->_energyPoints = 50;
	this->_maxEnergyPoints = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangedAttackDamage = 15;
	this->_armor = 3;
	std::cout << "\nSC4V-TP: " << this->_name << " is our new player!\n";
}

ScavTrap::ScavTrap(ScavTrap const & src) : 	_name(src._name), \
											_hitPoints (src._hitPoints), _maxHitPoints (src._maxHitPoints), \
											_energyPoints (src._energyPoints), _maxEnergyPoints (src._maxEnergyPoints), \
											_level(src._level), \
											_meleeAttackDamage(src._meleeAttackDamage), \
											_rangedAttackDamage (src._rangedAttackDamage), \
											_armor(src._armor) {}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs) {
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_maxHitPoints = rhs._maxHitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_maxEnergyPoints = rhs._maxEnergyPoints;
	this->_level = rhs._level;
	this->_meleeAttackDamage = rhs._meleeAttackDamage;
	this->_rangedAttackDamage = rhs._rangedAttackDamage;
	this->_armor = rhs._armor;
	return (*this);
}

void	ScavTrap::rangedAttack(std::string const & target) {

	std::cout << "\nSC4V-TP " << this->_name << " attacks " << target << " at range, causing " \
			<< _rangedAttackDamage << " points of damage using his special ScavTrap powers! \n";
}

void	ScavTrap::meleeAttack(std::string const & target) {
	std::cout << "\nSC4V-TP " << this->_name << " attacks " << target << " causing " \
			<< _meleeAttackDamage << " points of melee damage using his special ScavTrap stuff! \n";
}

void	ScavTrap::_resourceMessage(int mode) const {
	if (mode == 1)
		std::cout << this->_name << " now has " << this->_hitPoints << "/" << this->_maxHitPoints << " HP left\n";
	if (mode == 2)
		std::cout << this->_name << "'s energy level is " << this->_energyPoints << "/" << this->_maxEnergyPoints << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (amount <= this->_armor) {
		std::cout << "\nSC4V-TP " << this->_name << "'s armor worked well! No damage caused!\n";
		return ;
	}
	else
		amount -= this->_armor;
	(amount < this->_hitPoints) ? this->_hitPoints -= amount : this->_hitPoints = 0;
	std::cout << "\nSC4V-TP " << this->_name << " took " << amount << " points of damage\n";
	_resourceMessage(1);
}

static void	repare_value(unsigned int &value, const unsigned int max, unsigned int amount) {
	amount = std::min(amount, max - value);
	value += amount;
	std::cout << "\nFairies got a magic potion that has force of " << amount << " ponies!\n";
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == this->_maxHitPoints && this->_energyPoints == this->_maxEnergyPoints)
		std::cout << "\nNo need of healing, " << this->_name << " is already full of life\n";
	else if (this->_hitPoints == this->_maxHitPoints)
		repare_value(this->_energyPoints, this->_maxEnergyPoints, amount);
	else if (this->_energyPoints == this->_maxEnergyPoints)
		repare_value(this->_hitPoints, this->_maxHitPoints, amount);
	else
	{
		std::cout << std::endl;
		std::cout << "What shall be repaired?\n";
		_resourceMessage(1);
		_resourceMessage(2);
		std::cout << "Put 1 for HP, 2 for energy\n";
		int value = 0;
		if (std::cin.eof()) {
			std::cout << "Input error!\n";
			exit(0);
		}
		if (!(std::cin >> value)) {
			std::cout << "Something is wrong with your input\n";
			if (std::cin.bad())
				exit(0);
		}
		else if (value == 1)
			repare_value(this->_hitPoints, this->_maxHitPoints, amount);
		else if (value == 2)
			repare_value(this->_energyPoints, this->_maxEnergyPoints, amount);
		else
			std::cout << "Incorrect number\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	_resourceMessage(1);
	_resourceMessage(2);
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	const std::string challenges[] = {	"Let's see are you worthy, Newcomer! Can you exit Vim?",
										"I want free samples of your inner demons. Now!",
										"I need to eat an entire snowman! Hurry up!",
										"Find me a box within a box filled with cute tiny boxes.",
										"Tell me a joke, Newcomer! If you make me smile, I let you pass." };

	std::cout << "\nSC4V-TP " << this->_name << " challenged " << target << " with this task:\n";
	std::cout << challenges[std::rand() % 5] << std::endl;
}