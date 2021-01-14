#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>
# include <iostream>

class	Zombie
{
	public:
		Zombie(const std::string & name, const std::string & type);
		~Zombie();

		void announce(void) const;

	private:
		const std::string _name;
		const std::string _type;
};

#endif
