#include<iostream>      //for I/O
#include<math.h>        //for sine function
#include<stdlib.h>      //c++ standard library
#include <fstream>      //for file I/O

using namespace std;

const double PI = 3.14159265; //sets constant for the value of pi

/* This function opens a file named "graph.txt" and write a sine shaped
array of aesteric character*/
void GraphMaker()
{
    ofstream myfile;            //creates an object of class ofstream
    myfile.open ("graph.txt");  //opens the file

    /*The nested for loop runs through 360 degrees to calculate the value of
    sine function and then place the character in the file accordingly.*/
    for (int i = 0; i<360; i++)
    {
        float random = sin(((PI/180)*i))*40+40; //angle is converted to degrees
        //This loop and following two statements, write in the file.
        for ( int j = 0; j<random; j++)
        {
            myfile<<" ";
        }
        myfile<<"*";
        myfile<<"\n";

    }
}

int main()
{
    GraphMaker();	//function call for sine wave
    return 0;
}

