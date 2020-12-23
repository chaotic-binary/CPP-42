#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::~ClapTrap() {
    std::cout << "Bye-Bye!\n";
}

ClapTrap::ClapTrap(const ClapTrap & src) :
                                        _name(src._name),
                                        _hitPoints (src._hitPoints),
                                        _maxHitPoints (src._maxHitPoints),
                                        _energyPoints (src._energyPoints),
                                        _maxEnergyPoints (src._maxEnergyPoints),
                                        _level(src._level),
                                        _meleeAttackDamage(src._meleeAttackDamage),
                                        _rangedAttackDamage (src._rangedAttackDamage),
                                        _armor(src._armor) {
    std::cout << "\nNew ClapTrap cloned!\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs) {
    ClapTrap lhs = ClapTrap(rhs);
	return (*this);
}

ClapTrap::ClapTrap(const std::string &name,
                    const std::string &model,
                    unsigned int hitPoints,
                    unsigned int maxHitPoints,
                    unsigned int energyPoints,
                    unsigned int maxEnergyPoints,
                    unsigned int level,
                    unsigned int meleeAttackDamage,
                    unsigned int rangedAttackDamage,
                    unsigned int armor) :
            _name(name),
            _hitPoints(hitPoints),
	        _maxHitPoints(maxHitPoints),
	        _energyPoints(energyPoints),
	        _maxEnergyPoints(maxEnergyPoints),
	        _level(level),
	        _meleeAttackDamage(meleeAttackDamage),
	        _rangedAttackDamage(rangedAttackDamage),
	        _armor(armor),
            _model(model){
    std::cout << "\nNew ClapTrap born!\n";
}

const std::string & ClapTrap::getName() const { return _name; }
unsigned int ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int ClapTrap::getMaxHitPoints() const { return _maxHitPoints; }
unsigned int ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int ClapTrap::getMaxEnergyPoints() const { return _maxEnergyPoints; }
unsigned int ClapTrap::getLevel() const { return _level; }
unsigned int ClapTrap::getMeleeAttackDamage() const { return _meleeAttackDamage; }
unsigned int ClapTrap::getRangedAttackDamage() const { return _rangedAttackDamage; }
unsigned int ClapTrap::getArmor() const {return _armor;}

void ClapTrap::setHitPoints(unsigned int value) {
    _hitPoints = value;
}

void ClapTrap::setMaxHitPoints(unsigned int value) {
    _maxHitPoints = value;
}

void ClapTrap::setEnergyPoints(unsigned int value) {
   _energyPoints = value;
}

void ClapTrap::setMaxEnergyPoints(unsigned int value) {
   _maxEnergyPoints = value;
}

void ClapTrap::setLevel(unsigned int value) {
   _level = value;
}

void ClapTrap::setMeleeAttackDamage(unsigned int value) {
   _meleeAttackDamage = value;
}

void ClapTrap::setRangedAttackDamage(unsigned int value) {
   _rangedAttackDamage = value;
}

void ClapTrap::setArmor(unsigned int value) {
   _armor = value;
}

void	ClapTrap::_printLog() const {
    std::cout << _model << " " << _name;
}

void	ClapTrap::_resourceMessage(char mode) const {
    std::cout << _name;
    if (mode == 'H')
        std::cout << " now has " << _hitPoints << "/" << _maxHitPoints << " HP left\n";
    if (mode == 'E')
        std::cout << "'s energy level is " << _energyPoints << "/" << _maxEnergyPoints << std::endl;
}

void   ClapTrap::_attackMessage(char mode, std::string const &target) const {
    _printLog();
    std::cout << " attacks " << target;
    if (mode == 'R')
        std::cout << " at range, causing " << _rangedAttackDamage << \
                " points of damage using special " << _model << " powers\n";
    if (mode == 'M')
        std::cout << " causing " << _meleeAttackDamage << \
                " points of melee damage using special " << _model << " fight technique\n";
}

void	ClapTrap::rangedAttack(std::string const &target) const {
    _attackMessage('R', target);
}

void	ClapTrap::meleeAttack(std::string const &target) const {
    _attackMessage('M', target);
}

void	ClapTrap::takeDamage(unsigned int amount) {
    if (amount <= _armor) {
        _printLog();
        std::cout << " was protected by his shiny armor!\n";
        return ;
    }
    else
        amount -= _armor;
    (amount < _hitPoints) ? _hitPoints -= amount : _hitPoints = 0;
    std::cout << std::endl;
    _printLog();
    std::cout << " took " << amount << " points of damage\n";
    _resourceMessage('H');
}

static void	repare_value(unsigned int &value, const unsigned int max, unsigned int amount) {
    amount = std::min(amount, max - value);
    value += amount;
    std::cout << "\nFairies got a magic potion that has force of " << amount << " ponies!\n";
}

void	ClapTrap::beRepaired(unsigned int amount) {
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
