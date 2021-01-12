#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"
#include "MadDictator.hpp"
#include "BlowingPigeon.hpp"

int		main(void)
{
	Character* me = new Character("me");
	me->recoverAP(); //test recover full AP
	std::cout << *me;
	Enemy* b = new RadScorpion();
	me->attack(b); // test attak without weapon
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	me->equip(pr);
	std::cout << *me;
	me->equip(pf);
	me->attack(b);
	std::cout << *me;
	me->equip(pr);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;
	me->attack(b);
	std::cout << *me;

	std::cout << std::endl;
	me->attack(b); //test attack deleted enemy
	me->equip(pf);
	std::cout << *me;
	std::cout << std::endl;

	Enemy* sm = new SuperMutant();
	std::cout << sm->getType() << " has " << sm->getHP() << " HP\n";
	me->attack(sm);
	std::cout << sm->getType() << " has " << sm->getHP() << " HP\n";
	std::cout << std::endl;

	Enemy* e = new RadScorpion();
	std::cout << e->getType() << " has " << e->getHP() <<  " HP\n";
	me->attack(e);
	std::cout << e->getType() << " has " << e->getHP() <<  " HP\n";
	std::cout << *me;
	std::cout << std::endl;

	Enemy* d = new MadDictator();
	AWeapon* bp = new BlowingPigeon();
	me->equip(bp);
	me->recoverAP();
	std::cout << d->getType() << " has " << d->getHP() <<  " HP\n";
	me->attack(d);
	std::cout << d->getType() << " has " << d->getHP() <<  " HP\n";
	std::cout << *me;
	std::cout << std::endl;

	me->equip(pr);
	while (sm->getHP() > 0)
	{
		me->attack(sm);
		std::cout << *me;
		me->recoverAP();
	}

	std::cout << std::endl;

	delete me;
	delete pr;
	delete pf;
	delete bp;
	delete d;
	delete e;
	return 0;
}
