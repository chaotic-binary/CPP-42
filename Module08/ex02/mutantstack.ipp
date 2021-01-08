#include "mutantstack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &copy):
	std::stack<T>(copy)
{}

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &copy)
{
	 if (this != &copy)
		std::stack<T>::operator=(copy);
	return (*this);
}
