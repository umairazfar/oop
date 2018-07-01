#include"Box.h"

Box::Box()
{
    Width = 34;
    Height = 10;
    Length = 9;
    std::cout<<"Constructor Called"<<std::endl;
}

Box::Box(int Width, int Height, int Length)
{
    this->Width = Width;
    this->Length = Length;
    this->Height = Height;
    std::cout<<"Overloaded Constructor Called"<<std::endl;
}

Box::~Box()
{
    std::cout<<"Destructor Called"<<std::endl;
}

/*
Prints the dimensions of the box
*/

void Box::BoxInfo()
{
    std::cout<<Width<<std::endl;
    std::cout<<Height<<std::endl;
    std::cout<<Length<<std::endl;
}

