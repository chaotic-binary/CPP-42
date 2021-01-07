# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Intern.hpp"

int main()
{
	Intern intern;

	std::cout << *(intern.makeForm("presidential pardon", "Michelon"));
	std::cout << *(intern.makeForm("robotomy request", "Bender"));
	std::cout << *(intern.makeForm("shrubbery creation", "Maison"));

	std::cout << "\nDoesn't exist test\n";
	intern.makeForm("Unexistent type", "x");

	return (0);
}