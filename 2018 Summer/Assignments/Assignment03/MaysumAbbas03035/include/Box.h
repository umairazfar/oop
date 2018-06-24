#ifndef BOX_H
#define BOX_H
#pragma once //Better to write this in h file
#include <iostream>

class Box
{
    public:
        int length;
        int width;
        int height;
        Box();//Constructor
        ~Box(); //Destructor
        int Volume();
};

#endif // BOX_H
