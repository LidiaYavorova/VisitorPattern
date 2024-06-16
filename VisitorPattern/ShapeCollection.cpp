#include "ShapeCollection.h"

void ShapeCollection::resize(size_t newCapacity)
{
    Shape** newData = new Shape * [newCapacity];
    for (size_t i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

void ShapeCollection::free()
{
    for (size_t i = 0; i < size; i++)
    {
        delete data[i];
    }
    delete[] data;
}

void ShapeCollection::copyFrom(const ShapeCollection& other)
{
    data = new Shape * [other.capacity];
    for (size_t i = 0; i < other.size; i++)
    {
        data[i] = other.data[i]->clone();
    }
    size = other.size;
    capacity = other.capacity;
}

void ShapeCollection::moveFrom(ShapeCollection&& other)
{
    data = other.data;
    other.data = nullptr;
    size = other.size;
    other.size = 0;
    capacity = other.capacity;
    other.capacity = 0;
}

ShapeCollection::ShapeCollection()
{
    size = 0;
    capacity = 8;
    data = new Shape * [capacity] {nullptr};

}

ShapeCollection::ShapeCollection(const ShapeCollection& other)
{
    copyFrom(other);
}

ShapeCollection& ShapeCollection::operator=(const ShapeCollection& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

ShapeCollection::ShapeCollection(ShapeCollection&& other)
{
    moveFrom(std::move(other));
}

ShapeCollection& ShapeCollection::operator=(ShapeCollection&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

ShapeCollection::~ShapeCollection()
{
    free();
}

void ShapeCollection::addFigure(const Shape& shape)
{
    Shape* cloned = shape.clone();
    addFigure(cloned);
}

void ShapeCollection::addFigure(Shape* shape)
{
    if (size == capacity) {
        resize(size * 2);
    }
    data[size++] = shape;
    shape = nullptr;
}

double ShapeCollection::getAreaByIndex(size_t index) const
{
    return data[index]->getArea();
}

double ShapeCollection::detPerimeterByIndex(size_t index) const
{
    return data[index]->getPerimeter();
}

bool ShapeCollection::isPointInByIndex(size_t index, int x, int y) const
{
    return data[index]->isPointIn(index,x, y);
}

bool ShapeCollection::intersect(const Shape* sh1, const Shape* sh2)
{
    return sh1->intersectWith(sh2);
}

const Shape* ShapeCollection::operator[](size_t index) const
{
    if (index >= size) {
        throw std::exception("Invalid index");
    }
    return data[index];
}

unsigned ShapeCollection::getSize() const
{
    return size;
}
