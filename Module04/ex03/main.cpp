#include "Cure.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	Cure *cure = new Cure();
	Ice *ice = new Ice();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(ice);
	src->learnMateria(cure);
	//full stack

	ICharacter* me = new Character("me");
	AMateria* to_equip;
	to_equip = src->createMateria("cure");
	me->equip(to_equip);
	to_equip = src->createMateria("ice");
	me->equip(to_equip);
	me->equip(cure->clone());
	me->equip(ice->clone());
	//full stack, another 4 materias allocated

	Character* bob = new Character("bob");
	me->use(0, *bob);
	me->use(3, *bob);
	bob->equip(to_equip); // bob has 1 materia that me also has
	bob->use(0, *me);
	Character* newGuy = new Character(*bob); //newGuy has a deep copy of 1 bob's materia
	newGuy->use(0, *bob);
	bob->unequip(0); // bob has nothing
	newGuy->use(0, *me);
	newGuy->equip(cure); // newGuy has 2 materias, the last also stored in src
	*bob = *newGuy; //bob has a deep copy of 2 newGuy's materias
	bob->use(1, *newGuy);
	newGuy->unequip(1); // newGuy has 1 materia

	std::cout<<"\nErrors:\n";
	me->use(4, *bob);
	Character* empty = new Character("empty");
	empty->use(0, *bob);
	AMateria *extra = ice;
	me->equip(extra);
	src->learnMateria(extra);
	empty->unequip(1);
	me->unequip(20);
	to_equip = src->createMateria("nonexistent");

	delete bob; //deep copy of 2 materias deleted
	delete me; //4 matrias deleted
	delete src; //4 materias deleted
	delete newGuy; //deep copy of 1 materia deleted
	delete empty;
	return 0;
}