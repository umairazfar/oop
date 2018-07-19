#include "Circle.h"

Circle::Circle():Shape()
{
    radius = 0;
}

Circle::Circle(int x, int y, int radius):Shape(x, y)
{
    this -> radius = radius;
}

float Circle::Area()
{
    float area = (3.142) * (radius ^ 2);
    return area;
}
