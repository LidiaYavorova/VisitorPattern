#include "Circle.h"

double Circle::PI = 3.1415;
Circle::Circle(int x, int y, double radius) : Shape(1)
{
    this->radius = radius;
    setPoint(0, x, y);
}

double Circle::getArea() const
{
    return PI * radius *radius;
}

bool Circle::isPointIn(size_t index, int x, int y) const
{
    Point p(x, y);
    return p.getDistance(getPointAtIndex(0)) <= radius;
}

double Circle::getPerimeter() const
{
    return 2 * PI * radius;
}

bool Circle::intersectWith(const Shape* other) const
{
    return other->intersectWithCircle(this);
}

bool Circle::intersectWithTriangle(const Triangle* other) const
{
    std::cout << "Formula for circle with triangle" << std::endl;
    return true;
}

bool Circle::intersectWithCircle(const Circle* other) const
{

    std::cout << "Formula for circle with circle" << std::endl;
    return true;
}

bool Circle::intersectWithRectangle(const Rectangle* other) const
{
    std::cout << "Formula for circle with rectangle" << std::endl;
    return true;
}

Shape* Circle::clone() const
{
    return new Circle(*this);
}
