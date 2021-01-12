#include "span.hpp"

Span::Span() {}

Span::Span(uint size) \
	: _maxN(size)
{}

Span::~Span()
{
	this->_numbers.clear();
}

Span::Span(const Span &copy) \
	:	_maxN(copy._maxN), \
		_numbers(copy._numbers)
{}

Span	&Span::operator=(const Span &copy)
{
	this->_maxN = copy._maxN;
	this->_numbers.clear();
	this->_numbers = copy._numbers;
	return (*this);
	return (*this);
}

void	Span::addNumber(int n)
{
	if (_numbers.size() == _maxN)
		throw NoRoomException();
	_numbers.insert(n);
}

void	Span::addNumber(int arr[], int size)
{
	if (_numbers.size() + size > _maxN)
		throw NoRoomException();
	for (int i = 0; i < size; i++)
		_numbers.insert(arr[i]);
}

uint	Span::shortestSpan(void) const
{
	_check_N();
	int shortestSpan = std::numeric_limits<int>::max();
	int tmp;
	std::multiset<int>::iterator it = ++begin(_numbers);
	while (it != end(_numbers))
	{
		tmp = *it - *(prev(it));
		if (tmp < shortestSpan)
			shortestSpan = tmp;
		++it;
	}
	return (shortestSpan);
}

uint	Span::longestSpan(void) const
{
	_check_N();
	return (*(_numbers.rbegin()) - *(_numbers.begin()));
}

void	Span::_check_N() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
}

const char* Span::NoRoomException::what() const throw()
{
	return ("No room for new numbers");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers");
}