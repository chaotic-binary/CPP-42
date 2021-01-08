# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "Intern.hpp"

int main()
{
	Intern intern;

	Form *form0 = intern.makeForm("presidential pardon", "Zafod Beeblebrox");
	std::cout << *form0;
	Form *form1 = intern.makeForm("robotomy request", "World");
	std::cout << *form1;
	Form *form2 = intern.makeForm("shrubbery creation", "_tree");
	std::cout << *form2;

	Bureaucrat bureaucrat = Bureaucrat("Some powerful bureaucrat", 1);
	bureaucrat.signForm(*form0);
	bureaucrat.executeForm(*form0);
	delete form0;
	delete form1;
	delete form2;

	std::cout << "\nDoesn't exist test\n";
	intern.makeForm("Unexistent type", "x");

	Form *f = new Form("form", 10, 10);
	Form *c = intern.makeForm("robotomy request", "Zafod Beeblebrox");
	*f = *c;
	std::cout << *f;
	bureaucrat.signForm(*f);
	bureaucrat.executeForm(*f);

	Form *a = new RobotomyRequestForm("people");
	Form *b = intern.makeForm("presidential pardon", "Nobody");
	*a = *b;
	bureaucrat.signForm(*a);
	bureaucrat.executeForm(*a);

	return (0);
}