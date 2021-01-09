#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

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
	Enemy* sm = new SuperMutant();
	std::cout << sm->getType() << " has " << sm->getHP() << " HP\n";
	me->attack(sm);
	std::cout << sm->getType() << " has " << sm->getHP() << " HP\n";
	Enemy* e = new RadScorpion();
	std::cout << e->getType() << " has " << e->getHP() <<  " HP\n";
	me->attack(e);
	std::cout << e->getType() << " has " << e->getHP() <<  " HP\n";
	std::cout << *me;
	me->equip(pr);
	me->attack(sm);
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->attack(sm);
	me->recoverAP();
	std::cout << *me;
	me->attack(sm);
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	std::cout << *me;
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	me->attack(sm);
	return 0;
}
