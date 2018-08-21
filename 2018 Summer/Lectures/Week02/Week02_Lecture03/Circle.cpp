#include"Circle.h"


Circle::Circle()
{
    radius = 1;
    position.x = 0;
    position.y = 0;
    std::cout<<"\nConstructor Called"<<std::endl;
}

Circle::Circle(Point position, float radius)
{
    this->radius = radius;
    this->position = position;
    std::cout<<"x: "<<position.x<<", y: "<<position.y;
    std::cout<<"\nOverloaded Constructor Called"<<std::endl;
}


Circle::Circle(const Circle& circle)
{
    this->radius = circle.radius;
    position.x = circle.position.x;
    position.y = circle.position.y;
    std::cout<<"\nCopy Constructor Called"<<std::endl;
}

Circle::~Circle()
{
    std::cout<<"\nDestructor Called";
}

float Circle::Area()
{
    return 3.1415 * radius * radius;
}

float Circle::Area(float radius)
{
    this->radius = radius;

    return 3.1415 * radius * radius;
}
