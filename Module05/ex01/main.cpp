#include "Bureaucrat.hpp"

int		main(void)
{
	std::cout << "Test too high and too low form grades\n";
	Form* tooHigh;
	Form* tooLow;
	try
	{
		tooHigh = new Form("Too High", 0, 20);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		tooHigh = new Form("Too High", 20, 0);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		tooLow = new Form("Too Low", 20, 151);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		tooLow = new Form("Too Low", 151, 20);
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nTest of signing the form\n";
	Form* someForm = new Form("Paper", 11, 20);
	std::cout << *someForm;
	Form* someList = new Form("List of some stuff", 1, 1);
	std::cout << *someList;

	Bureaucrat* bill = new Bureaucrat("Bill", 5);
	std::cout << *bill;
	Bureaucrat* tom = new Bureaucrat("Tom", 12);
	std::cout << *tom;

	tom->signForm(*someForm);
	bill->signForm(*someForm);
	std::cout << *someForm;
	bill->signForm(*someForm);

	tom->signForm(*someList);
	tom->signForm(*someForm);
	delete someForm;
	delete bill;
	delete someList;
	delete tom;
}