#include "Shape.h"

void Shape::free()
{
    delete[] points;
    points = nullptr;
    size = 0;
}

void Shape::copyFrom(const Shape& other)
{
    size = other.size;
    points = new Point[size];
    for (size_t i = 0; i < size; i++)
    {
        points[i] = other.points[i];
    }
}

void Shape::moveFrom(Shape&& other)
{
    points = other.points;
    other.points = nullptr;
    size = other.size;
    other.size = 0;
}

const Point& Shape::getPointAtIndex(size_t index) const
{
    if (index >= size) {
        throw std::exception("Invalid index");
    }
    return points[index];
}

Shape::Shape(size_t pointsCount)
{
    size = pointsCount;
    points = new Point[size];
}

Shape::Shape(const Shape& other)
{
    copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Shape::Shape(Shape&& other) noexcept
{
    moveFrom(std::move(other));
}

Shape& Shape::operator=(Shape&& other) noexcept
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

void Shape::setPoint(size_t index, int x, int y)
{
    if (index >= size) {
        throw std::exception("Invalid index");
    }
    points[size++] = Point(x, y);
}

double Shape::getPerimeter() const
{
    double perimeter = 0;
    for (size_t i = 0; i < size-1; i++)
    {
        perimeter += points[i].getDistance(points[i + 1]);
    }
    perimeter += points[0].getDistance(points[size - 1]);
    return perimeter;

}

Shape::~Shape()
{
    free();
}
