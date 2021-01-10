#include "id.hpp"

Base::~Base(void) {}

Base	*generate(void)
{
	int i = std::rand() % 3;

	switch(i)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		default:
			return new C();
			break;
	}
}

void	identify_from_pointer(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
}

void	identify_from_reference(Base &p)
{
	Base instance;
	
	try {
		instance = dynamic_cast<A &>(p);
		std::cout << "A";
	} catch(std::bad_cast &e) {}
	try {
		instance = dynamic_cast<B &>(p);
		std::cout << "B";
	} catch(std::bad_cast &e) {}
	try {
		instance = dynamic_cast<C &>(p);
		std::cout << "C";
	} catch(std::bad_cast &e) {}
}