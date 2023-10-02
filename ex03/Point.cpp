#include "Point.hpp"
#include "Fixed.hpp"

//Constructors
Point::Point() : x(0), y(0){}

Point::Point(const Fixed xx, const Fixed yy): x(xx), y(yy) {}

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point::~Point() {}

//Operators overload
Point& Point::operator=(const Point &point) {
	(void)point;
	return *this;
}

Fixed Point::getX() const{
	return x;
}

Fixed Point::getY() const{
	return y;
}