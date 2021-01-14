#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie
{
	public:
		Zombie(void);
		Zombie(const std::string & name, const std::string & type);
		~Zombie();

		void announce(void) const;

	private:
		std::string _name;
		std::string _type;
};

#endif
