# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

static void testForm(Bureaucrat* bureaucrat, Form* form)
{
	bureaucrat->signForm(*form);
	bureaucrat->executeForm(*form);
}

int		main(void)
{
	srand(time(0));
	
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("_tree0");
	ShrubberyCreationForm* shrub1 = new ShrubberyCreationForm("_tree1");
	RobotomyRequestForm* robotomy = new RobotomyRequestForm("World");
	PresidentialPardonForm* pardon = new PresidentialPardonForm("Everyone");

	Bureaucrat* bob = new Bureaucrat("Bob", 120);
	Bureaucrat* tom = new Bureaucrat("Tom", 33);
	Bureaucrat* superjack = new Bureaucrat("Jack", 1);

	testForm(bob, shrub);
	testForm(bob, robotomy);
	testForm(tom, robotomy);
	testForm(superjack, pardon);
	testForm(superjack, shrub1);
	testForm(bob, pardon);

	delete shrub;
	delete shrub1;
	delete robotomy;
	delete pardon;

	delete bob;
	delete tom;
	delete superjack;

	return (0);
}
