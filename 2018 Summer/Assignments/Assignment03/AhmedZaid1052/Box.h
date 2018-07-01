#pragma once
#include<iostream>

class Box
{
private:

    int Width;
    int Length;
    int Height;

public:

    Box();
    Box(int, int, int);
    ~Box();
    void BoxInfo();

};
