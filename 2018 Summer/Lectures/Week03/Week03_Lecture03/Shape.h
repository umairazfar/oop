#ifndef SHAPE_H
#define SHAPE_H

#include"Point.h"
#include<iostream>

using namespace std;

class Shape
{
private:
    Point position;
public:
    inline Shape()
    {
        cout<<"Shape Constructor Called\n";
        position.x = 0;
        position.y = 0;
    }

    Shape(int x, int y)
    {
        cout<<"Overloaded Shape Constructor Called\n";
        position.x = x;
        position.y = y;
    }

    Shape(const Point& point)
    {
        cout<<"Constructor with Point input Called\n";
        position = point;
    }

    virtual void Callout();
};
#endif
