#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>

template< typename T >
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const &copy);
	virtual ~MutantStack();
	MutantStack<T> &operator=(const MutantStack<T> &copy);

private:
};

#include "mutantstack.ipp"

#endif
