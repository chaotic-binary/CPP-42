#include "span.hpp"

static void print_span(Span sp)
{
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << std::endl << std::endl;
}

int		main(void)
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	print_span(sp);

	std:: cout << "No room exception test:\n";
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
	print_span(sp1);
	sp1.addNumber(-25);
	print_span(sp1);

	Span sp2 = Span(4);
	sp2.addNumber(-30);
	sp2.addNumber(-50);
	sp2.addNumber(-51);
	sp2.addNumber(30);
	print_span(sp2);
	return (0);
}
