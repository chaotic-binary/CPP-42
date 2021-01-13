#include "Array.hpp"

template <typename T>
Array<T>::Array() \
	: _arr(new T[0]()), _size(0)
{}

template <typename T>
Array<T>::Array(uint n)
	: _arr(new T[n]()), _size(n)
{}

template<typename T>
Array<T>::~Array()
{
	_delArr();
}

template<typename T>
Array<T>::Array(const Array &copy)
{
	_deepCopy(copy);
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &copy)
{
	if (this == &copy)
		return (*this);
	_delArr();
	_deepCopy(copy);
	return (*this);
}

template<typename T>
uint Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
T &Array<T>::operator[](uint i) const
{
	if (i >= this->_size)
		throw OutOfBoundsException();
	return (this->_arr[i]);
}

template<typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds");
}

template<typename T>
void	Array<T>::_deepCopy(const Array<T> &copy)
{
	this->_size = copy._size;
	this->_arr = new T[this->_size];
	for (uint i = 0; i < this->_size; ++i)
		this->_arr[i] = copy._arr[i];
}

template<typename T>
void	Array<T>::_delArr()
{
	delete[] this->_arr;
}