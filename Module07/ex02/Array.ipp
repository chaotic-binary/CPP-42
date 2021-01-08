#include "Array.hpp"

template <typename T>
Array<T>::Array() \
	: _size(0), _arr(nullptr)
{}

template <typename T>
Array<T>::Array(size_t n)
	: _size(n), _arr(new T[n]())
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
size_t Array<T>::size() const
{
	return (this->_size);
}

template<typename T>
T &Array<T>::operator[](size_t i) const
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
	this->_arr = nullptr;
	if((this->_size = copy._size))
	{
		this->_arr = new T[this->_size];
		for (size_t i = 0; i < this->_size; ++i)
			this->_arr[i] = copy._arr[i];
	}
}

template<typename T>
void	Array<T>::_delArr()
{
	if (this->_size)
		delete[] this->_arr;
}