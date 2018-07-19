#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape
{
    private:
        int radius;

    public:
        Circle();
        Circle(int x, int y, int radius);
        float Area();


};

#endif // CIRCLE_H
