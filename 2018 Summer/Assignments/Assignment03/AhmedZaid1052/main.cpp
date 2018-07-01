#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include "Truck.h"
#include "Box.h"


using namespace std;

int LineCounter(char*);


int main()
{
    int lines = LineCounter("Drivers.txt");
    int entries = lines/5;

    FILE* filePointer;                              //Declaring a file pointer
    char buff[32];                                  //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");        //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }


    Truck* tempo[entries];              //pointer array for trucks
    for(int i = 0; i < entries; i++)
    {
        int emptyMileage;
        int loadedMileage;
        int petrolPresent;
        Driver New;                                     //Object of the class Driver

        /*
        Store the values of individual entry
        */
        for(int i = 0; i < 5; i++)
        {
            fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string

            if(i == 0)
            New.Name = buff;

            if(i == 1)
            petrolPresent = atoi(buff);

            if(i == 2)
            New.Cash = atoi(buff);

            if(i == 3)
            emptyMileage = atoi(buff);

            if(i == 4)
            loadedMileage = atoi(buff);

        }
        // creates onjects at pointer addresses
        tempo[i] = new Truck(New, emptyMileage, loadedMileage, petrolPresent);

    }

    fclose(filePointer);                            //Closing file

    //Checks if a truck can make the journey
    for(int i = 0; i < entries; i++)
    {
        tempo[i]->TruckInfo();
        tempo[i]->TankRefill();

        if(tempo[i]->JourneyPossibility()== true)
        {
            cout<<"Happy!"<<endl;
        }
        tempo[i]->TruckInfo();

    }

    //frees the memory
    for(int i = 0; i < 4; i++)
    {
        cout<<"Truck deallocated at: "<<tempo[i]<<endl;
        delete tempo[i];

    }

//Dynamic array of boxes!
    int boxes = 12+rand()%20;
    Box* temp[5];
    for(int i = 0; i < boxes; i++)
    {
        int length = rand();
        temp[i] = new Box(5+rand()%30 , 5+rand()%30, 5+rand()%30);
        temp[i]->BoxInfo();
    }

    for(int i = 0; i < 4; i++)
    {
        cout<<"Object deallocated at: "<<temp[i]<<endl;
        delete temp[i];

    }
    return 0;
}

/*
Code obtained from Week 2 Exercise 1.
*/
int LineCounter(char* fileName)
{
    FILE* filePointer;                                  //Declaring a file pointer
    char buff[32];                                      //Declaring a character array to store a line

    filePointer = fopen(fileName, "r");                 //Opening file as read only

    if (filePointer == NULL)                            //If file is not found
    {
        perror ("Error opening file");                  //Show Error
        return 0;
    }

    int counter = 0;                                    //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}

