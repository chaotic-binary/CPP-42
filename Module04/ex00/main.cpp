
#include "Sorcerer.hpp"
#include "Peon.hpp"
#include "Rustic.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);

	Rustic bill("Bill");
	std::cout << bill;
	robert.polymorph(bill);
	return 0;
}
