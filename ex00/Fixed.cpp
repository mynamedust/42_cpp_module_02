#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = f._value;
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&f != this) {
		_value = f._value;
	}
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}