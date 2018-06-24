#include<iostream>              //Including libraries
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>
#include<stdio.h>

using namespace std;

const double PI = 3.14159265;

void GraphMaker()
{
    ofstream myfile;
    myfile.open("stars.txt");   //Opening a .txt file where the sine curve is written with asterisk (*).
    float result;               //Declaring a variable to store sine values in radians for each degree from 0 to 360.
    int distance = 45;          //Declaring some reasonably large number as compared to 'result' in order to get the clear sine curve.
    float spacing;              //Declaring a variable to store a float value.
    int count = 0;              //Initializing the counter

    while(count<360)            //Counter from 0 to 360
    {
        result = sin((PI * count) / 180);        //Obtaining sine value in radians for each degree.
        cout<<"Sine value in radians is:"<<result<<endl;
        spacing = result * distance;             //Multiplying the distance with the obtained sine value for appropriate distancing in each iteration so that a clearly visible sine graph can be obtained.

        int range = distance + spacing;          //Distance is fixed, i.e. 45, but spacing is changing with the change in sine value, therefore adding them up to use it as a range to get the sine curve.
        //When the spacing is positive value, the positive curve will be sketched, and when the spacing is negative value, the negative part of the sine curve will be drawn.
        for (int i = 0; i < range; i++)
        {
            myfile<<" ";        //Providing as many spaces as required at the given iteration starting initially from 'distance = 45'.
        }
        myfile<<"*"<<endl;      //Writing one '*' in each line after obtaining the desired spaces in each iteration.
        count = count + 1;      //Incrementing the 'while' loop counter till one complete cycle, i.e. 360 degrees.
    }
}

void LineMaker()
{
    ofstream myfile;
    myfile.open ("linegraph.txt");

    int count = 0;

    while (count<10)
    {
        int random = rand() % 10;
        cout<<"random:"<<random<<" "<<endl;
        for (int i = 0; i < random; i++)
            //
            myfile<<" ";
            myfile<<"*";
        myfile<<"\n";
        count = count + 1;
    }
}

int main()
{
    srand(time(NULL));
    //LineMaker();
    GraphMaker();
    return 0;
}

