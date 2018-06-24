#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>

using namespace std;

const double PI = 3.14159265;



void GraphMaker() // function to generate sine graph
{
    ofstream myfile;
    myfile.open ("graph.txt");
    double graph, range;
    double ranges = PI/180; // converting values to radians


    for (int range=0; range <= 360; range++ ) //loop for printing sine wave
    {
        graph = 50 + 50 * sin(range*ranges);

        for (int j=0; j<= graph; j++)
        {
            myfile << " ";
        }
        myfile << "*\n";
    }


    cout<< "check graph.txt"<<endl;

}

int main()
{
    GraphMaker(); //calling function for drawing a sine wave
    return 0;
}
