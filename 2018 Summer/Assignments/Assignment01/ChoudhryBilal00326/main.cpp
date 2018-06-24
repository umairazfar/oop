/*
Object Oriented Programming & Methodologies(CS224),
Summer Semester 2018, Habib University,

Instructor: Dr. Umair Azfar Khan,
TA: Ahmed Ali(aa02190),

assignment # 01
Choudhry Bilal Mazhar (cm00326)
*/

#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>

using namespace std;
const double PI = 3.14159265;

void GraphMaker() // Function GraphMaker() generates a sinusoidal waveform using asterisk signs(*) in a file named 'graph.txt'
{                // It is done using two nested for loops, here the period of the sinusoidal is hard coded as 360 degrees and can be varied.
    ofstream myfile;
    myfile.open("graph.txt");
    int sine=0;
    for (int sine=0; sine<=360; sine+=1)
    {
        int c=sin((PI/180)*sine)*35+100;
        for(int j=0; j<c;j++)
        {
            myfile<<" ";
        }
        myfile<<"*";
        myfile<<"\n";
    }
}

void LineMaker()
{
    ofstream myfile;
    myfile.open ("linegraph.txt");
    int count = 0;
    cout<<"\nRandom #'s generated for 'linegraph.txt' file: ";
    while (count<10)
    {
        int random = rand() % 10;
        cout<<random<<" ";
        for (int i = 0; i<random; i++)
            myfile<<"*";
        myfile<<"\n";
        count = count + 1;
    }
    cout<<"\n";
}

int main()
{
    srand(time(NULL));
    LineMaker();
    GraphMaker();
    return 0;
}
