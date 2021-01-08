#include "Span.hpp"

int		main(void)
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std:: cout << "\nNo room exception test:\n";
	try {
		sp.addNumber(17);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std:: cout << "\nNot enough numbers exception test:\n";
	Span sp1 = Span(5);
	try {
		std::cout << sp1.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	sp1.addNumber(-10);
	try {
		std::cout << sp1.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cerr << std::endl;
	sp1.addNumber(-10);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	sp1.addNumber(25);
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	return (0);
}
