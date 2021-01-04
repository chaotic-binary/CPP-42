#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
public:
	Enemy();
	Enemy(int hp, std::string const & type);
	Enemy(const Enemy &copy);
	virtual ~Enemy();
	Enemy &operator=(const Enemy &copy);

	std::string const &getType() const;
	int getHP() const;

	virtual void takeDamage(int);

private:
	int			_hp;
	std::string	_type;
};

#endif
