#ifndef VICTIM_HPP
# define VICTIM_HPP
# include <iostream>

class Victim
{
public:
	Victim();
	Victim(const std::string &name);
	Victim(const Victim &copy);
	virtual ~Victim();
	Victim &operator=(const Victim &copy);

	virtual void	getPolymorphed(void) const;

	const std::string&		getName(void) const;

	protected:
	std::string		_name;

};

	std::ostream	&operator<<(std::ostream &os, Victim const &victim);

#endif
