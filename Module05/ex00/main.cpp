#include "Bureaucrat.hpp"

int		main(void)
{
	std::cout << "Too high and too low tests\n";
	Bureaucrat* tooHigh;
	Bureaucrat* tooLow;
	try
	{
		tooHigh = new Bureaucrat("Too High", 0);
		std::cerr << "CAUTION! Something went wrong with the exception" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr  << e.what() << std::endl;
	}

	try
	{
		tooLow = new Bureaucrat("Too Low", 151);
		std::cerr << "CAUTION! Something went wrong with the exception" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr  << e.what() << std::endl;
	}

	std::cout << "\nDecrement test\n";
	Bureaucrat* bob = new Bureaucrat("Bob", 2);
	try
	{
		std::cout << *bob;
		bob->incGrade();
		std::cout << *bob;
		bob->incGrade();
		std::cerr << "CAUTION! Something went wrong with the exception" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *bob;

	std::cout << "\nIncrement test\n";
	Bureaucrat* tom = new Bureaucrat("Tom", 149);
	try
	{
		std::cout << *tom;
		tom->decGrade();
		std::cout << *tom;
		tom->decGrade();
		std::cerr << "CAUTION! Something went wrong with the exception" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << *tom;

	delete bob;
	delete tom;
	return (0);
}
