#include "Pony.hpp"

static void	ponyOnTheHeap(void)
{
	std::cout << "New pony on the Heap ~" << std::endl;
	Pony *pony = new Pony("HeapPony", "white");
	pony->Pony::setLaughingState(1);
	pony->Pony::check_on_pony();
	delete(pony);

}

static void	ponyOnTheStack(void)
{
	std::cout << "New pony on the Stack ~" << std::endl;
	Pony pony = Pony("StackPony", "red");
	pony.Pony::setSleepingState(1);
	pony.Pony::check_on_pony();
}

int			main(void)
{
	ponyOnTheHeap();
	std::cout << std::endl;
	ponyOnTheStack();
	return (0);
}