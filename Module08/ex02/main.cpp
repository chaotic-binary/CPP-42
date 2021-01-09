#include "mutantstack.hpp"
#include <iostream>

template <typename I>
static void print_stack(I it, I e)
{
	std::cout << "\nStack: \n";
	while (it != e)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << std::endl;
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	print_stack(it, ite);
	std::stack<int> s(mstack);

	*it = 1;
	MutantStack<int> copy(mstack);
	MutantStack<int>::const_iterator cit = copy.begin();
	MutantStack<int>::const_iterator cite = copy.end();
	print_stack(cit, cite);
	//*cit = 20; //will not compile becuse it's const

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	print_stack(rit, rite);
	*rit = 10;
	print_stack(cit, cite);

	copy = mstack;
	MutantStack<int>::const_reverse_iterator crit = copy.rbegin();
	MutantStack<int>::const_reverse_iterator crite = copy.rend();
	print_stack(crit, crite);
	//*crit = 20; //will not compile becuse it's const

	return 0;
}
