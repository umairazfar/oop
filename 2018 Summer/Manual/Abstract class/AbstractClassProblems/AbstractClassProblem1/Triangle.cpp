#include "Triangle.h"

Triangle::Triangle() : Shape()
{
    base = 0;
    height = 0;
}

Triangle::Triangle(int x, int y, int base, int height):Shape(x, y)
{
    this -> base = base;
    this -> height = height;
}

float Triangle::Area()
{
    float area = (0.5) * base * height;
    return area;
}

