#pragma once
#include <iostream>

class Circle;
class Triangle;
class Rectangle;

struct Point {
	int x;
	int y;
	Point():x(0),y(0){}
	Point(int x,int y):x(x),y(y){}
	double getDistance(const Point& other) const{
		int dx = x - other.x;
		int dy = y - other.y;
		return sqrt(dx * dx + dy * dy);
	}

};
class Shape{
private:
	Point* points;
	size_t size;

	void free();
	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);
protected:
	const Point& getPointAtIndex(size_t index) const;
public:
	Shape(size_t pointsCount);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);

	Shape(Shape&& other) noexcept;
	Shape& operator=(Shape&& other) noexcept;

	void setPoint(size_t index, int x, int y);
	
	virtual double getArea() const = 0;
	virtual bool isPointIn(size_t index, int x, int y) const = 0;
	virtual double getPerimeter() const;

	virtual bool intersectWith(const Shape* other) const = 0;
	virtual bool intersectWithTriangle(const Triangle* other) const = 0;
	virtual bool intersectWithCircle(const Circle* other) const = 0;
	virtual bool intersectWithRectangle(const Rectangle* other) const = 0;

	virtual Shape* clone() const = 0;

	virtual ~Shape();
};

