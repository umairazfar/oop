#include<iostream>
#include"Circle.h"

using namespace std;

int main()
{
    /*
    Circle circle1;
    Circle circle2(7,8);
    Point point;
    point.x = 90;
    point.y = 80;
    Circle circle3(point);
    circle2.Area();
    circle3.Callout();
    */

    Circle* shape = new Circle;
    shape->Callout();
    delete shape;

    return 0;
}
