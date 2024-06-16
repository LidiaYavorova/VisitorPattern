#pragma once
#include "Shape.h"
class Triangle : public Shape
{
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);
	double getArea() const override;
	bool isPointIn(size_t index, int x, int y) const override;
	bool intersectWith(const Shape* other) const override;
	bool intersectWithTriangle(const Triangle* other) const override;
	bool intersectWithCircle(const Circle* other) const override;
	bool intersectWithRectangle(const Rectangle* other) const override;
	Shape* clone() const override;
};

