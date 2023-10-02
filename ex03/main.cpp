#include <iostream>
#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(4), Fixed(0));
	Point c(Fixed(2), Fixed(4));

	Point point(Fixed(3), Fixed(3));

	bool isInside = bsp(a, b, c, point);

	if (isInside) {
		std::cout << "Point is inside the triangle." << std::endl;
	} else {
		std::cout << "Point is outside the triangle." << std::endl;
	}

	// Проверяем конструкторы копирования и оператор присваивания
	Point copyPoint = point;
	std::cout << copyPoint.getX() << "- x " << copyPoint.getY() << "- y" << std::endl;
	Point assignedPoint(Fixed(1), Fixed(1));
	std::cout << assignedPoint.getX() << "- x " << assignedPoint.getY() << "- y" << std::endl;
	assignedPoint = point;
	std::cout << assignedPoint.getX() << "- x " << assignedPoint.getY() << "- y" << std::endl;

	return 0;
}