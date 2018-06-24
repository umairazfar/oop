#include<iostream> //Similar to import command in Python
#include<stdio.h>
#include<stdlib.h> //For random numbers
#include<time.h>   //For generating a new random seed
#include <fstream> //For input/output stream class to operate on files.
#include <math.h>  //For using mathematics operands

using namespace std; //required for using cin and cout commands

const double PI = 3.14159265;

void GraphMaker()
{
    /*int count = 0;
    int space = 0;
    while (space < 10)
    {
        for (int i = 0; i < space + 20; i++)
        {
            cout << " " ;
        }
        cout << "*" <<endl;
        space = space + 1;
    }*/
    //Write correct code to complete this function
    ofstream myfile;                                 //opening a file for writing purpose
    myfile.open ("graph.txt");                       //naming the file that is to opened
    for (int j=0; j<360; j++)                        //loop generated for a complete sine wave from 0 to 360
    {
        float radians= j * PI/180;                   //converting values from degrees to radians
        for(int i=0; i<(30*sin(radians))+50; i++)    //loop for obtaining the sine wave
        {

        myfile<<" ";
        }
        myfile<<"*"<<endl;
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
    LineMaker();
    GraphMaker();                             //calling the function
    return 0;
}


