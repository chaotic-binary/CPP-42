#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon();
	Peon(const std::string &name);
	Peon(const Peon &copy);
	virtual ~Peon();
	Peon &operator=(const Peon &copy);

	virtual void	getPolymorphed(void) const;

};

std::ostream	&operator<<(std::ostream &ostream, Peon const &peon);

#endif
