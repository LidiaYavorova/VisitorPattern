#include "ShapeFactory.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"

Shape* shapeFactory()
{
    int n;
    std::cin >> n;
    double radius = 0;
    int x1, y1, x3, y3;
    switch (n) {
    case 1:
        int x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        return new Triangle(x1, y1, x2, y2, x3, y3);
        break;
    case 2:
        std::cin >> x1>> y1>>x3>>y3;
        return new Rectangle(x1, y1, x3, y3);
        break;
    case 3:
        std::cin >> x1>>y1 >> radius;
        return new Circle(x1, y1, radius);
        break;
    default:
        return nullptr;
        break;
    }
}
