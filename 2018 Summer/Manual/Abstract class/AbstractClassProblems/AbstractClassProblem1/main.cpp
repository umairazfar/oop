#include <iostream>
#include "Circle.h"
#include "Triangle.h"


using namespace std;

int main()
{
    Shape* circle = new Circle(4, 3, 10);
    cout << circle -> Area() << endl;
    Shape* triangle = new Triangle(2, 5, 6, 10);
    cout << triangle -> Area() << endl;
    return 0;
}
