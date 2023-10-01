#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int _value;
	static const int _bits;
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	~Fixed();
	Fixed(const Fixed &f);

	static Fixed& min(Fixed& f1, Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);

	Fixed& operator=(const Fixed& f);

	bool operator>(const Fixed& f) const;
	bool operator<(const Fixed& f) const;
	bool operator>=(const Fixed& f) const;
	bool operator<=(const Fixed& f) const;
	bool operator==(const Fixed& f) const;
	bool operator!=(const Fixed& f) const;

	Fixed operator+(const Fixed& f);
	Fixed operator-(const Fixed& f);
	Fixed operator/(const Fixed& f);
	Fixed operator*(const Fixed& f);

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed);

#endif