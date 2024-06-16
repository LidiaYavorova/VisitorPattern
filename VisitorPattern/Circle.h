#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	double radius = 0;
	static double PI;
public:
	Circle(int x, int y, double radius);
	double getArea() const override;
	bool isPointIn(size_t index,int x, int y) const override;
	double getPerimeter() const override;
	bool intersectWith(const Shape* other) const override;
	bool intersectWithTriangle(const Triangle* other) const override;
	bool intersectWithCircle(const Circle* other) const override;
	bool intersectWithRectangle(const Rectangle* other) const override;
	Shape* clone() const override;
};

