#pragma once
#include"Point.h"
#include<iostream>

class Circle
{
private:
    Point position;
    float radius;   //What will we need to do if we make it a pointer?
public:
    Circle();
    Circle(Point, float);
    Circle(const Circle&);
    ~Circle();
    float Area();
    float Area(float);
};
