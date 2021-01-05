#include "Enemy.hpp"

Enemy::Enemy()
{
}

Enemy::Enemy(int hp, std::string const &type) \
	: _hp(hp), _type(type)
{
}

Enemy::~Enemy()
{
	this->_type.erase();
}

Enemy::Enemy(const Enemy &copy) \
	: _hp(copy._hp), _type(copy._type)
{
}

Enemy	&Enemy::operator=(const Enemy &copy)
{
	if (this != &copy)
	{
		this->_hp = copy._hp;
		this->_type = copy._type;
	}
	return (*this);
}

int	Enemy::getHP() const
{
	return (this->_hp);
}

std::string const & Enemy::getType() const
{
	return (this->_type);
}

void	Enemy::takeDamage(int amount)
{
	if (amount <= 0)
		return ;
	_hp -= amount;
}