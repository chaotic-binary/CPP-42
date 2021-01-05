
#include "Fixed.class.hpp"

const int Fixed::_fractBits = 8;

Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) {
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fractBits;
}

Fixed::Fixed(float const value) {
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << _fractBits));
}

Fixed::Fixed(Fixed const &copy) : _value(copy.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_value = rhs.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int Fixed::toInt(void) const {
	return (this->_value >> Fixed::_fractBits);
}

float Fixed::toFloat(void) const {
	return (this->_value / (float)(1 << Fixed::_fractBits));
}

std::ostream &operator<<(std::ostream &os, Fixed const &in)
{
	os << in.toFloat();
	return (os);
}