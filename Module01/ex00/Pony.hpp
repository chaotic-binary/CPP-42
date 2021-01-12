#ifndef PONY_H
# define PONY_H

# include <string>
# include <iostream>

class	Pony
{
	public:
		Pony(std::string name, std::string color);
		~Pony(void);

		const std::string&	getName() const;
		const std::string&	getColor() const;

		bool	getSleepingState() const;
		bool	getLaughingState() const;

		void	setSleepingState(bool state);
		void	setLaughingState(bool state);
		void	check_on_pony() const;

	private:
		const std::string	_name;
		const std::string	_color;
		bool				_is_sleeping;
		bool				_is_laughing;
};

#endif