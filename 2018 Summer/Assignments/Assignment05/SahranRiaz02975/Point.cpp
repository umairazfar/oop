#include "Point.h"

Point::Point()  //Default constructor, when a point object is created, its x and y coordinates are initialized to 0
{
    this -> x = 0;
    this -> y = 0;
}

Point::Point(int x, int y)  //Parameterized constructor, when a point object is created and its x and y coordinate values are passed simultaneously, those values get assigned to the respective attributes
{
    this -> x = x;
    this -> y = y;
}
