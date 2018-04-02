#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctype.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

void TimeDelay(int delay);      //This function should delay the execution to 3 second default, 0 sec min and 10 sec max
string ToUpperCase(string&);    //Converts a string to UpperCase. Also returns the string if required.
void read (int*);               //Reads a file and gets a pointer to the variable in main that holds the count of letters read
int edit ();                    //Creates and writes a new file

int main ()
{
    int count = 0;
    string command;
    bool loopRunning = true;

    while (loopRunning)
    {

    }
    return 0;
}

void TimeDelay(int delay)
{

}

string ToUpperCase(string& text)
{

}

void read (int* count)
{
    int line = 1;
    int line_num = 24;

    char filename[50];

    ifstream readfile;
    cout << "Enter name of the file to read: "<<endl;
    cin.getline(filename, 50);
    readfile.open(filename);

    while (/*Add your condition*/)
    {

    }

    readfile.close();
}

int edit ()
{

    return 0;
}
