#include "Fixed.hpp"
#include <cmath>

const int Fixed::_bits = 8;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int i) {
	std::cout << "Int constructor called" << std::endl;
	_value = i << _bits;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(f * (1 << _bits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) {
	std::cout << "Copy constructor called" << std::endl;
	if (&f != this) {
		this->_value = f._value;
	}
}

Fixed& Fixed::operator=(const Fixed& f) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&f != this) {
		_value = f._value;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return stream;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float Fixed::toFloat(void) const {
	return float(_value) / (1 << _bits);
}

int Fixed::toInt(void) const {
	return _value >> _bits;
}