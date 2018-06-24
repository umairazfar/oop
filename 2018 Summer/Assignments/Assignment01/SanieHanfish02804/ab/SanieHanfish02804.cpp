#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>

using namespace std;

const double PI = 3.14159265; // The value of PI is defined to a certain number of decimal places.

void GraphMaker() //The function gives a sin wave in a txt file.
{
    ofstream myfile; //Used for inputting in the file
    myfile.open ("graph.txt");              //Already saved file is opened for editing.

    int count = 0;

    while (count < 360)                     //The loop will continue until the count value reaches 360 which means 2PI, this is done to obtain a perfect sin wave with complete cycle.
    {
        float radian = (count * (PI / 180));       //Taking the count value and converting it into radians.
        float Trignometric = sin (radian);       //Radian value is substituted into the sin function.
        float shape = (Trignometric * 45) + 50;   //Using the sin value Amplitude and phase difference of each value is increased so that proper sin graph can be obtained.
        cout << shape << " ";                     //Each value is outputed.
        for (int i = 0; i<shape; i++)         //Another loop is inserted, to input into the txt file line by line.
            myfile << " ";                      //Places space in txt file as many times as the loop runs in a single line.

        myfile << "*\n";                        //After the loop finishes * is printed after the spaces, and moves to next line.
        count = count + 1;                    //Count value is incremented.
    }

}

/*
void LineMaker()
{
    ofstream myfile;
    myfile.open ("linegraph.txt");


    int count = 0;

    while (count<360)
    {
        float points= (count*(PI/180));
        float stf=sin(points);
        float shape=(stf*70) + 75;
        cout<<shape<<" ";
        for (int i = 0; i<shape; i++)
            myfile<<" ";
        myfile<<"*\n";
        count = count + 1;
    }
}
*/
int main()
{

    GraphMaker(); //GraphMaker function is called.
    return 0;
}

//Font size 1 in txt file shows a perfect sin wave.
