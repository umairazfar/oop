#include"Shape.h"

class Circle : public Shape
{
private:
    int radius;
public:
    Circle()
    {
        cout<<"First Circle Constructor Called\n";
        radius = 5;
    }

    Circle(int x, int y):Shape(x,y)
    {
        cout<<"Overloaded Circle Constructor Called\n";
        radius = 10;
        //cout<<position.x;
    }
    Circle(const Point& point):Shape(point)
    {

    }

    void Area()
    {
        cout<<3.1415 * radius * radius<<endl;
    }
};
