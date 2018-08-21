#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
    Circle c;
    cout<<c.Area(10)<<endl;

    Point p;
    p.x = 10;
    p.y = 20;

    Circle circle(p, 10);
    cout<<circle.Area()<<endl;

    Circle b = c;
    cout<<b.Area()<<endl;

    Circle* temp = new Circle;
    cout<<temp->Area()<<endl;
    delete temp;    //Comment this to see what happens

    Circle* all[10];
    for (int i = 0; i<10; i++)
    {
        all[i] = new Circle;
        cout<<all[i]->Area()<<endl;
    }

    return 0;
}

//Create a dynamic array of Circle Pointers
//Then create circles with variable radii and assign them to each pointer of the array
//print the sum of all the areas of all the circles
//Once done, create another array of Circle pointers which has an extra pointer.
//This pointer should point towards the circle with the largest area.
