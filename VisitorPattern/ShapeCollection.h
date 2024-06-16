#pragma once
#include "Shape.h"
class ShapeCollection
{
private:
	Shape** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t newCapacity);
	void free();
	void copyFrom(const ShapeCollection& other);
	void moveFrom(ShapeCollection&& other);

public:
	ShapeCollection();
	ShapeCollection(const ShapeCollection& other);
	ShapeCollection& operator=(const ShapeCollection& other);

	ShapeCollection(ShapeCollection&& other);
	ShapeCollection& operator=(ShapeCollection&& other);
	~ShapeCollection();

	void addFigure(const Shape& shape);
	void addFigure(Shape* shape);

	double getAreaByIndex(size_t index) const;
	double detPerimeterByIndex(size_t index) const;
	bool isPointInByIndex(size_t index, int x, int y) const;

	bool intersect(const Shape* sh1, const Shape* sh2);

	const Shape* operator[](size_t index) const;

	unsigned getSize() const;

};

