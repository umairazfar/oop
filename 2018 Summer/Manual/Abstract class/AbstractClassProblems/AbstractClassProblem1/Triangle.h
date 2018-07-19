#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"

class Triangle : public Shape
{
    private:
        int base;
        int height;
    public:
        Triangle();
        Triangle(int x, int y, int base, int height);
        float Area();

};

#endif // TRIANGLE_H
