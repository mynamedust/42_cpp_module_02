#include "Point.hpp"

Fixed triangleArea(const Point& a, const Point& b, const Point& c) {
	Fixed area;
	area = ((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY()))
		+ (c.getX() * (a.getY() - b.getY()))) / 2;
	return area < 0 ? area * -1 : area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	return triangleArea(a, b, c) - triangleArea(a, b, point) - triangleArea(a, point, c) - triangleArea(point, b, c) == 0;
}