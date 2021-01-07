#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();
	Intern &operator=(const Intern &copy);

	Form *makeForm(std::string type, std::string const &target);

private:
	struct FormCreator
	{
		const std::string &type;
		Form *(*func)(std::string const &);
	};
};

#endif
