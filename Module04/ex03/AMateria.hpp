#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &);
	virtual ~AMateria();
	AMateria &operator=(const AMateria &copy);

	std::string const &	getType() const;
	unsigned int		getXP() const;

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

private:
	const std::string		_type;
	unsigned int			_xp;
};

#endif
