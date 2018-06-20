#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>

using namespace std; //for cin and cout

const double PI = 3.14159265;

void GraphMaker()
{
    ofstream myfile;       //var name for txt file -> myfile
    myfile.open("graph.txt"); //creating txt file

//    int count = 0;
//    degrees = 2;
//    cout << result<<endl;

    double degrees,result;

    degrees = 0; //input values for sin function, in degrees

    while(degrees < 360) //creates the curve
    {
        result = (sin((degrees * PI)/180)*50+50); //needs addition to cancel neg values, multiplied by factor to increase amplitude
                                                  //result is output value
        for (int i=0;i<result;i++) //for each     //number of spaces = value of result
        {
            myfile<<" ";                          //spaces written in file
//            cout << " ";
        }

//        cout << result;
//        cout << "\n";
        myfile<<"*";    //for each line, a sterick at the end of all the spaces
        myfile<<"\n";   //next line
        degrees++;      //next degree, next line

        //myfile<<"*";
        //myfile<<"\n";
    }

    //Write correct code to complete this function
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
    //LineMaker();
    GraphMaker();
    return 0;
}

