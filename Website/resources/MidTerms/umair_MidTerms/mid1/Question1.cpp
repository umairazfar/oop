#include <iostream>

using namespace std;

class Point
{
private:

    float x;
    float y;
public:

    Point();
    Point(float x, float y);   //Q1 Constructors defined Properly. 2 points each
    void Add(float x, float y);//Q2 Add function defined Properly. 2 points each
    void Add(const Point&);
    void Add(Point*);
    void Show();                        //Q3 Show defined properly
};

int main()
{
    Point p1(3,4);
    Point p2 = p1;
    //p2.Add(p1);
    p2.Add(&p1);
    p2.Show();
    return 0;
}

Point::Point()
{
    x =y = 0;
}
Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
}

void Point::Add(float x, float y)
{
    this->x += x;
    this->y += y;
}
void Point::Add(const Point& p)
{
    this->x += p.x;
    this->y += p.y;
}
void Point::Add(Point* p)
{
    this->x += p->x;
    this->y += p->y;
}
void Point::Show()
{
    cout<<"point is ("<<x<<" "<<y<<")";
}
