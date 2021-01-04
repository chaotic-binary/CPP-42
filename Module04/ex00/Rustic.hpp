#ifndef RUSTIC_HPP
# define RUSTIC_HPP

# include <iostream>
# include "Victim.hpp"

class Rustic : public Victim
{
public:
	Rustic();
	Rustic(const std::string &name);
	Rustic(const Rustic &copy);
	~Rustic();
	Rustic &operator=(const Rustic &copy);

	virtual void	getPolymorphed(void) const;

};

std::ostream	&operator<<(std::ostream &ostream, Rustic const &rustic);

#endif
