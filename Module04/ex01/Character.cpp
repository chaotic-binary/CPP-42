#include "Character.hpp"

Character::Character()
{}

Character::Character(std::string const &name) : _name(name), _ap(40), _weapon(0)
{}

Character::~Character()
{}

Character::Character(const Character &copy) \
	:_name(copy._name), _ap(copy._ap), _weapon(copy._weapon)
{}

Character	&Character::operator=(const Character &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_ap = copy._ap;
		this->_weapon = copy._weapon;
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

int	Character::getAP(void) const
{
	return (this->_ap);
}

AWeapon	*Character::getWeapon(void) const
{
	return (this->_weapon);
}

void	Character::recoverAP()
{
	if (this->_ap == 40)
		return ;
	this->_ap += std::min(10, 40 - this->_ap);
}

void	Character::equip(AWeapon *weapon)
{
	this->_weapon = weapon;
}

void	Character::attack(Enemy *enemy)
{
	if (!this->_weapon || this->_ap < this->_weapon->getAPCost())
		return ;
	if (!enemy || enemy->getHP() ==  std::numeric_limits<int>::min())
	{
		std::cout << "Enough, your enemy is already dead.\n";
		return ;
	}
	std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
	this->_weapon->attack();
	this->_ap -= this->_weapon->getAPCost();
	enemy->takeDamage(this->_weapon->getDamage());
	if (enemy->getHP() <= 0)
		delete enemy;
}

std::ostream	&operator<<(std::ostream &os, Character const &character)
{
	if (character.getWeapon())
		os << character.getName() << " has " << character.getAP() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
	else
		os << character.getName() << " has " << character.getAP() << " AP and is unarmed" << std::endl;
	return (os);
}