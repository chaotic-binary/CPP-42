#include "id.hpp"

int		main(void)
{
	std::cout << "Random\n";
	for (int i = 0; i < 5; i++)
	{
		Base *tmp = generate();

		std::cout << i + 1 << " from poineter:";
		identify_from_pointer(tmp);
		std::cout << ", from reference:";
		identify_from_reference(*tmp);
		std::cout << std::endl;

		delete tmp;
	}

	std::cout << "\nPredefined\n";
	A a;
	B b;
	C c;

	std::cout << "from pointer - ";
	std::cout << "A: ";
	identify_from_pointer(&a);
	std::cout << " , B: ";
	identify_from_pointer(&b);
	std::cout << " , C: ";
	identify_from_pointer(&c);

	std::cout << "\nfrom reference - ";
	std::cout << "A: ";
	identify_from_reference(a);
	std::cout << " , B: ";
	identify_from_reference(b);
	std::cout << " , C: ";
	identify_from_reference(c);
	std::cout << std::endl;
	return (0);
}
