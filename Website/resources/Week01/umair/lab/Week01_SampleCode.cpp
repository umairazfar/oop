#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>

using namespace std;

const double PI = 3.14159265;

void GraphMaker()
{
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
    LineMaker();
    return 0;
}

/**
See the code as given Week01_SampleCode.cpp.
Once you run the code, you can see that a file linegraph.txt is generated.
You should now try to understand the code on your own and test it to see
what happens when you make changes to it. Once understood, you are to produce a file,
namely graph.txt which will contain a sine graph. For reference, kindly see graph.txt
as given in the exercise folder.
*/
