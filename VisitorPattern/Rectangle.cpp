#include "Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x3, int y3) :Shape(4)
{
    setPoint(0, x1, y1);
    setPoint(1, x1, y3);
    setPoint(2, x3, y3);
    setPoint(3, x3, y1);
}

double Rectangle::getArea() const
{
    const Point& p0 = getPointAtIndex(0);
    const Point& p1 = getPointAtIndex(1);
    const Point& p3 = getPointAtIndex(3);

    return p0.getDistance(p1) * p0.getDistance(p3);
}

bool Rectangle::isPointIn(size_t index, int x, int y) const
{
    Point p(x, y);
    return p.x >= getPointAtIndex(0).x && p.x <= getPointAtIndex(2).x &&
        p.y <= getPointAtIndex(0).y && p.y >= getPointAtIndex(2).y;
}

bool Rectangle::intersectWith(const Shape* other) const
{
    return other->intersectWithRectangle(this);
}

bool Rectangle::intersectWithTriangle(const Triangle* other) const
{
    std::cout << "Formula for rect with triangle" << std::endl;
    return true;
}

bool Rectangle::intersectWithCircle(const Circle* other) const
{
    std::cout << "Formula for rect with rect" << std::endl;
    return true;
}

bool Rectangle::intersectWithRectangle(const Rectangle* other) const
{
    std::cout << "Formula for rect with circle" << std::endl;
    return true;
}

Shape* Rectangle::clone() const
{
    return new Rectangle(*this);
}
