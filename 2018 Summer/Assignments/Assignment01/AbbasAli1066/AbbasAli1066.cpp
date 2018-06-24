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
    myfile.open ("newgraph.txt");  //File named newgraph is created here

    for (int i = 0; i<360; i++)    //A for loop that generated 0 to 360 which can be taken as degrees

    {

        float sinewave = sin((PI/180)*i*10)*50+50;  //That sine wave is being made with the 0 to 360 degree converted to Radians
        for (int j = 0; j<sinewave; j++)

        {
          myfile<<" ";    //For every value of the sine wave a blank space is created
        }

        myfile<<"*";      //At every blank space a star is stored
        myfile<<"\n";
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
        cout<<random<<" ";
        for (int i = 0; i<random; i++)
            myfile<<"*";
        myfile<<"\n";
        count = count + 1;
    }
}

int main()
{
    srand(time(NULL));
    GraphMaker();
    return 0;
}

