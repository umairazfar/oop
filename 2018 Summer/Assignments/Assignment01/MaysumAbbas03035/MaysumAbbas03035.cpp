#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>

using namespace std;

const double PI = 3.14159265;

void GraphMaker()
{
    ofstream myfile;
    myfile.open ("graph.txt"); //It opens the file

    int count = 0;
    while (count<360) //count values are 360 degrees for one complete sine wave
    {
        float SineWave = 70 * ( sin (count * (PI / 180 )) ) + 70 ; //Generating y-axis values for Sine Wave, shifted values.
        cout<<SineWave<<" "; //It prints the values of SineWave and then a space
        for (int i = 0; i<SineWave; i++) //spaces are written in the file, according to the value of SineWave
            {
                myfile<<" ";
            }
        myfile<<"*\n"; //* is added in the end of each line of spaces, in the file
        count = count + 1;
    }
}

int main()
{
    GraphMaker();
    return 0;
}

