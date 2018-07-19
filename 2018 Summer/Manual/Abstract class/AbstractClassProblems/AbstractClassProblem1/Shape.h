#ifndef SHAPE_H
#define SHAPE_H
#include "Position.h"

class Shape
{
    private:
        Position position;
    public:
        Shape();
        Shape(int x, int y);
        virtual float Area() = 0;
};

#endif // SHAPE_H
