#include "Enemy.hpp"

Enemy::Enemy() {}

Enemy::Enemy(int hp, std::string const &type) \
	: _hp(hp), _type(type)
{
	if (hp <= 0)
	{
		std::cout << "HP <= 0 doesn't make sense. Let's make it 1\n";
		this->_hp = 1;
	}
}

Enemy::~Enemy()
{
	this->_hp = std::numeric_limits<int>::min();
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
	if (_hp < 0)
		_hp = 0;
}
