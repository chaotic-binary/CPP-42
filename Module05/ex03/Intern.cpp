#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &) {}

Intern	&Intern::operator=(const Intern &)
{
	return (*this);
}

static Form *makeShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}
static Form *makeRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}
static Form *makePardon(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(std::string type, std::string const &target)
{
	static struct FormCreator formCreators[3] = {
		{ "shrubbery creation", makeShrubbery },
		{ "robotomy request", makeRobotomy },
		{ "presidential pardon", makePardon }
	};

	transform(type.begin(), type.end(), type.begin(), ::tolower);
	for (int i = 0; i < 3; i++)
	{
		if (formCreators[i].type == type)
		{
			std::cout << "Intern creates " << type << std::endl;
			return (formCreators[i].func(target));
		}
	}
	std::cout << "Unknown form type: " << type << std::endl;
	return (nullptr);
}