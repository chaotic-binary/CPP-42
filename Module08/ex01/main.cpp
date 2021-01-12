#include "span.hpp"
#include <iostream>

static void print_span(Span sp)
{
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << std::endl << std::endl;
}

int		main(void)
{
	Span sp = Span(5);
	int arr[5] = {5, 3, 17, 9, 11};
	sp.addNumber(arr, 5);
	Span sp_c = Span(sp);
	print_span(sp_c);

	std:: cout << "No room exception test:\n";
	try {
		sp.addNumber(17);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Span n = Span(1);
		n.addNumber(arr, 2);
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
	std::cout << std::endl;
	sp1.addNumber(-10);
	print_span(sp1);
	Span sp1_c = Span(0);
	sp1_c = sp1;
	sp1_c.addNumber(-25);
	print_span(sp1_c);

	Span sp2 = Span(4);
	int ins[4] = {-51, -50, -30, 30};
	sp2.addNumber(ins, 4);
	print_span(sp2);
	return (0);
}
