#include <iostream>
#include "Box.h"
#include<stdlib.h>//For random numbers

using namespace std;

Box::Box()
{
    length = rand() % 26 + 5; // length in the range 5-30
    width = rand() % 26 + 5;  // width in the range 5-30
    height = rand() % 26 + 5; // height in the range 5-30
}

int Box::Volume()
{
    int volume=length*width*height;
    return volume;
}

Box::~Box()
{
    //Memory for Dynamic Array of Boxes was deallocated in Truck class
}
