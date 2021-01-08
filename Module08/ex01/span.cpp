#include "span.hpp"

Span::Span() {}

Span::Span(size_t size) \
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
	if (this->_numbers.size() == this->_maxN)
		throw NoRoomException();
	this->_numbers.insert(n);
}

size_t	Span::shortestSpan(void) const
{
	_check_N();
	int next = *(++(this->_numbers.begin()));
	return (std::abs(next - *(this->_numbers.begin())));
}

size_t	Span::longestSpan(void) const
{
	_check_N();
	int max = *(--(this->_numbers.end()));
	return (std::abs(max - *(this->_numbers.begin())));
}

void	Span::_check_N() const
{
	if (this->_numbers.size() < 2)
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