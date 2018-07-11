#include "Point.h"

Point::Point()  //This is a default constructor which is used to initialize the x and y coordinate pair of an object, i.e. rectangle
{
    this -> x = 0;  //(this) is used to refer to the property of the instance member function
    this -> y = 0;
}

Point::Point(int x, int y)  //Parameterized constructor, used to assign the passed values to the x and y coordinate pair
{
    this -> x = x;
    this -> y = y;
}

Point::Point(const Point& point)  //Copy constructor, used to copy the x and y coordinate pair of one object into another
{
    x = point.x;
    y = point.y;
}
