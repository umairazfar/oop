//include header files from Standard Library
#include <iostream>
#include <stdio.h>
#include<stdlib.h>  //For random numbers
#include<time.h>    //For generating a new random seed
#include <conio.h>  //It contains functions for console input/output

#include"Box.h"
#include"Truck.h"

using namespace std;//required for using cin and cout commands directly

int LineCounter(char*);
void ShowDriversMakingJourney(int,Truck*&);

int main()
{
    cout<<"Welcome to Package Delivery System."<<endl;
    cout<<"To Check which driver(s) can make journey Press ANY KEY"<<endl;
    getch();
    system("cls"); //Clears the Screen
    srand (time(NULL));
    int NumOfLines=LineCounter("Drivers.txt");
    int NumOfEntry=NumOfLines/5;
    cout<<"Number of Entries in the File are = "<<NumOfEntry<<endl; //5 Lines per Entry
    cout << "!!!----------------------Calculation Details :----------------------!!!" << endl;
    Truck *DynTruckArray;                       //Creating Dynamic Array of Trucks
    DynTruckArray=new Truck[NumOfEntry];        //new operator returns the base address

    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    for(int i=0;i<NumOfEntry;i=i+1)             //For Inputing Data from File into Dynamic Array
    {
        fgets(DynTruckArray[i].driver, 32, (FILE*)filePointer);

        fgets(buff, 32, (FILE*)filePointer);
        DynTruckArray[i].petrol = atoi(buff);   //atoi(): This function accepts a string and converts it into an integer

        fgets(buff, 32, (FILE*)filePointer);
        DynTruckArray[i].money = atoi(buff);

        fgets(buff, 32, (FILE*)filePointer);
        DynTruckArray[i].emptyMileage = atoi(buff);

        fgets(buff, 32, (FILE*)filePointer);
        DynTruckArray[i].fullMileage = atoi(buff);
    }

    fclose(filePointer);                        //Closing file

    cout<<endl;

    for (int cont=0;cont<NumOfEntry;cont=cont+1)
    {
        if (DynTruckArray[cont].petrol < 50)   //Calculating how much petrol needed to fill the tank
        {
            DynTruckArray[cont].PetrolNeedToFull=50-DynTruckArray[cont].petrol;
        }
        else
        {
            DynTruckArray[cont].PetrolNeedToFull=0;
        }
        cout<<cont+1<<"# Truck driver : "<<DynTruckArray[cont].driver;
        cout<<"Petrol Needed To fill the tank = "<<DynTruckArray[cont].PetrolNeedToFull<<" liters"<<endl;
        DynTruckArray[cont].CostToFull=2.73*DynTruckArray[cont].PetrolNeedToFull; //Cost needed to fill the tank
        cout<<"For which he should pay = "<<DynTruckArray[cont].CostToFull<<"$"<<endl;
        cout<<"Amount of Money he has "<<DynTruckArray[cont].money<<"$"<<endl;
        if (DynTruckArray[cont].CostToFull>DynTruckArray[cont].money)
        {
            cout<<"Do not have money to Fill the Tank"<<endl; //Driver can not make Journey
        }
        else
        {
            DynTruckArray[cont].TotalLitersForJourney=(60./DynTruckArray[cont].fullMileage)+(60./DynTruckArray[cont].emptyMileage);
            if (DynTruckArray[cont].TotalLitersForJourney<=50)//50 Liters Max Petrol can be in the tank
            {
                cout<<"Can make Journey"<<endl;
                cout<<"Total Liters Required for Complete Journey according to millage = "<<DynTruckArray[cont].TotalLitersForJourney<<" liters"<<endl;
            }
        }
        cout<<endl;
    }
    ShowDriversMakingJourney(NumOfEntry, DynTruckArray);//Shows Drivers that can make Journey
    cout<<"To Check the Number of Boxes Delivered, Trip Cost & other details"<<endl;
    cout<<"Press ANY KEY"<<endl;
    getch();
    system("cls"); //Clears the Screen
    cout<<"!!!---------Number of Boxes Delivered, Trip Cost & other details:---------!!!"<<endl<<endl;
    /**
    Journey Starts
    **/
    //Loads and Loaded Truck travels 60 km with Full Millage
    //Unloads and Show Volume of All Boxes in a single truck
    //Empty Truck travels 60 km with Empty Millage
    for (int cont=0;cont<NumOfEntry;cont=cont+1)
    {
        if(DynTruckArray[cont].TotalLitersForJourney !=0) //Loop for those who can make Journey
        {
            DynTruckArray[cont].Load();//Shows the number of Boxes loaded and travels 60 km
            int BoxesVolume=0;
            for (int BoxesLoop=0;BoxesLoop<DynTruckArray[cont].NumOfBoxes;BoxesLoop=BoxesLoop+1) // For Calculating Complete Volume
            {
                int vol=DynTruckArray[cont].DynTruckbox[BoxesLoop].Volume(); //Volume of a Box
                BoxesVolume =vol+BoxesVolume;
            }
            cout<<"Volume of all Boxes = "<<BoxesVolume<<" cubic inch"<<endl; //Shows Volume of all Boxes
            DynTruckArray[cont].Unload(); //Memory for Array of Boxes Deallocated
            DynTruckArray[cont].Cost(); //Prints the Total Cost for the Trip
        }

    }
    if (DynTruckArray!=NULL)
        {
            delete [] DynTruckArray; // memory deallocation
            cout<<"Memory for Array of all Trucks Deallocated"<<endl;
        }
    getch();
    return 0;
}

/**
Function Definitions
**/

void ShowDriversMakingJourney(int NumOfEntry,Truck *&DynTruckArray) //Passing as Pointer Reference
{
    cout << "\n!!!--------------Following Drivers can make Journey :--------------!!!" << endl;
    for (int cont=0;cont<NumOfEntry;cont=cont+1)
    {
        if(DynTruckArray[cont].TotalLitersForJourney !=0)
        {
            cout<<DynTruckArray[cont].driver;
        }
    }
    cout<<endl;
}

int LineCounter(char* fileName)
{
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen(fileName, "r");         //Opening file as read only

    if (filePointer == NULL)                    //If file is not found
    {
        perror ("Error opening file");          //Show Error
        return 0;
    }

    int counter = 0;                            //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}


