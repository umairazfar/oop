#include <iostream>

using namespace std;

class Point
{
private:

    float x;
    float y;
public:

    Point();
    Point(float x, float y);
    Point(const Point&);
    void Add(float x, float y);
    void Add(const Point&);
    void Add(Point*);
    float GetX();           //Q1 Check if they have declared functions that return attribute values
    float GetY();
    void Show();
};

void AllAreas(Point[], Point[]);

int main()
{
    Point topLeft[3];
    Point bottomRight[3];

    topLeft[0] = Point(1.0f,0.0f);  //Q2 Check if they convert values to float
    topLeft[1] = Point(2.0f,2.0f);
    topLeft[2] = Point(1.0f,8.0f);

    bottomRight[0] = Point(12.0f,30.0f);
    bottomRight[1] = Point(12.0f,10.0f);
    bottomRight[2] = Point(5.0f,9.0f);

    AllAreas(topLeft, bottomRight);

    return 0;
}

void AllAreas(Point tl[], Point br[]) //Q3 Check if they implement the function properly
{
    int l;
    int w;

    for (int i =0; i<3; i++)
    {
        l = tl[i].GetX() - br[i].GetX();
        w = tl[i].GetY() - br[i].GetY();
        cout<<"Area is: "<<l * w<<endl;
    }
}

float Point::GetX()
{
    return x;
}

float Point::GetY()
{
    return y;
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
Point::Point(const Point& p)
{
    this->x = p.x;
    this->y = p.y;
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
