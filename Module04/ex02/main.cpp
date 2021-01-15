#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int		main(void)
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;
	std::cout << std::endl;

	ISpaceMarine* bill = new TacticalMarine;
	ISpaceMarine* tim = new AssaultTerminator;
	Squad* a = new Squad();
	Squad* b = new Squad();
	Squad* t = new Squad();
	a->push(bill);
	a->push(tim);
	t->push(tim);
	b->push(bill);
	a->push(tim);
	std::cout << a->getCount() << " soldier(s) in the unit " << std::endl;
	t = new Squad(*a); //test copy constructor
	std::cout << t->getCount() << " soldier(s) in the unit " << std::endl;
	*b = *a; //test assignment
	std::cout << b->getCount() << " soldier(s) in the unit " << std::endl;
	std::cout << std::endl;

	ISpaceMarine* cur = t->getUnit(0);
	cur->battleCry();
	cur->rangedAttack();
	cur->meleeAttack();
	std::cout << std::endl;

	delete t;
	delete a;
	delete b;
	return 0;
}
