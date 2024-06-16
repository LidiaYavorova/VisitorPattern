#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "ShapeCollection.h"
#include "ShapeFactory.h"

int main()
{
    ShapeCollection collection;
    collection.addFigure(shapeFactory());
    collection.addFigure(shapeFactory());
    for (size_t i = 0; i < collection.getSize()-1; i++)
    {
        collection.intersect(collection[i], collection[i + 1]);
    }

}

