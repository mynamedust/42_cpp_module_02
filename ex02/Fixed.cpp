#include "Fixed.hpp"
#include <math.h>

const int Fixed::_bits = 8;

//Constructors
Fixed::Fixed() {
	_value = 0;
}

Fixed::Fixed(const int i) {
	_value = i << _bits;
}

Fixed::Fixed(const float f) {
	_value = roundf(f * (1 << _bits));
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed& f) {
	if (&f != this) {
		this->_value = f._value;
	}
}

//Operators overload
Fixed& Fixed::operator=(const Fixed& f) {
	if (&f != this) {
		_value = f._value;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return stream;
}

//Comparison operators
bool Fixed::operator>(const Fixed& f) {
	return this->_value > f._value;
}

bool Fixed::operator<(const Fixed& f) {
	return this->_value < f._value;
}

bool Fixed::operator>=(const Fixed& f) {
	return this->_value >= f._value;
}

bool Fixed::operator<=(const Fixed& f) {
	return this->_value <= f._value;
}

bool Fixed::operator==(const Fixed& f) {
	return this->_value == f._value;
}

bool Fixed::operator!=(const Fixed& f) {
	return this->_value != f._value;
}

//Arithmetics operators
Fixed Fixed::operator+(const Fixed& f) {
	return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed& f) {
	return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator/(const Fixed& f) {
	return Fixed(this->toFloat() / f.toFloat());
}

Fixed Fixed::operator*(const Fixed& f) {
	return Fixed(this->toFloat() * f.toFloat());
}

//Increment && decrement
Fixed& Fixed::operator++() {
	_value += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	_value -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed copy(*this);
	++(*this);
	return copy;
}

Fixed Fixed::operator--(int) {
	Fixed copy(*this);
	--(*this);
	return copy;
}

//Public member functions
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