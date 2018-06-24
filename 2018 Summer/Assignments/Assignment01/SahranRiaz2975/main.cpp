#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include <fstream>
#include <string>

using namespace std;

// Task 1
void GraphMaker();
void Name_Sorter();
int main()
{
    GraphMaker();
    Name_Sorter();
    return 0;
}
const double PI = 3.14159265;     //The value of PI is set to be constant, since it is a large float value, the data type of double is used to allocate a space of 8 bytes to it

double sine;                      //A variable of the data type of double is declared to hold the large float values of sine, as it is passed in with angles from 0 to 360, in radians
const int sine_Multiplier = 50;   //A constant integer variable is declared that will forever hold the value of 50, it can be changed by the user manually, and not through any function in the program. It is multiplied by angles from 0 to 360 in radians to determine the amount of spacing needed.
const int additional_Shift = 50;  //This constant integer variable is declared to shift the entire sine wave by 50 spaces to give an idea about the negative values of sine
void GraphMaker()                 //Function by the name of GraphMaker is declared
{
    ofstream out_File;
                                  //An output file by the name of graph.txt is created and referenced by out_File, it is done using the output file stream class
    out_File.open("graph.txt");

    for (int i = 0; i < 361; i++) //A for loop is created that will run from 0 to 360, the angles required to generate one complete cycle of a sine wave
    {
        sine = sin(i*PI/180);     //The variable of sine holds the sin values of the angles from 0 to 360, converted to radians, with one degree difference
        double shift_Sine = ((sine_Multiplier*sine)+additional_Shift);  //A variable of the data type of double by the name shift_Sine holds the absolute value of the product of sine_Multiplier with sine to determine the number of spaces after which an asterik will appear,
                                                                           //abs is used to remove the possibility of a negative number in the upcoming for loop. The resultant value will have an addition of 50 spaces to make the asterik appear almost at the center of the file.
        for (int l = 0; l < int (shift_Sine); l++) //A for loop is created to run the number of times the value stored in shift_Sine
        {
            out_File << " ";              //Spaces are created in a line inside the file graph.txt, the number of times the loop runs
        }
        out_File << "*" << endl;             //As the for loop ends, an asterik is placed next to the last space in that line, then the cursor is moved to the next line
    }
    out_File.close();                        //Since the file is created, and was open, it is time to close it now
}

// Task 2

void Name_Sorter()                          //Function Name_Sorter is declared
{
    string line;                            //This string variable holds the name in each line of the names.txt file within the loop to keep track of the number of items in that file
    ifstream myfile;                        //Using an input stream class, file names.txt is being referred to with the name myfile in order to be read

    myfile.open("names.txt");
    int Count = 0;                          //Keeps track of the number of elements in the file names.txt
    if (myfile.is_open())                   //A check to see whether the desired file is open or not is passed into an if condition
    {
        while ( getline (myfile,line) )     //Count increments by one the number of times the string variable line receives a name from the text file
        {
            Count++;
        }
        myfile.close();                     //names.txt is being closed after use
    }
    else cout << "Unable to open file";     //Error statement is displayed if the file does not open due to some reason

    string Names[Count];                    //A string array, Names, of the size count is created to hold each name from the file names.txt
    string temp;                            //A string variable to temporarily hold data during the application of bubble sort on the array
    string extra;                           //Gets the name from the file names.txt and assigns it to the string array Names
    ifstream myFile;                        //names.txt is being read again, so the same reading protocol is applied
    myFile.open("names.txt");
    for (int z = 0; z < Count; z++)         //This for loop runs according to the value of Count to assign each name in the file to the array Names
    {
        myFile >> extra;
        Names[z] = extra;
    }
    myFile.close();                         //File being closed after use
    for (int k = 0; k < (Count-1); k++)     //Loop runs the number of times the value of Count-1 to ensure all names in the array are sorted
    {
        for (int j = 0; j < Count; j++)     //Loop runs the number of times the value of count
        {
            if ((j+1)>=Count)               //if j+1 is 5 and the list has 5 elements, index 0 to 4, then the program will crash, this check is to ensure that does not happen
            {
                break;
            }
            if ((int(Names[j+1][0])) < (int(Names[j][0]))) //Bubble sort algorithm is applied by comparing the ascii values of the first alphabet of each of the two successive elements in the array
            {
                temp = Names[j+1];
                Names[j+1] = Names[j];
                Names[j]=temp;
            }

            else if ((int(Names[j+1][0])) == (int(Names[j][0])))  //Following are the two checks to ensure sorting is appropriate
            {
                continue;
            }
            else
            {
                continue;
            }

        }
    }
    ofstream sortedFile;       //A file is being created by the name sortedNames,txt and referred to by the name sortedFile, this is done using the class output stream
    sortedFile.open("sortedNames.txt");
    for (int l = 0; l < Count; l++)     //Loop runs on the basis of the value in Count
    {
        sortedFile << Names[l] << endl; //File is being written with the sorted names from the array Names
    }
    sortedFile.close();                 //File closed after use
}

