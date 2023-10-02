#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point& point);
	Point& operator=(const Point& point);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
};


#endif
