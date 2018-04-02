#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Box
{
    int length;
    int width;
    int height;

    Box()
    {
        length = width = height = 5;
    }


    int Volume()
    {
        return 0;
    }
};

struct Truck
{
    char driver[32];
    int petrol;
    int money;
    int fullMileage;
    int emptyMileage;
    Box box;

    void Load(int numBox)
    {

    }
    void Unload()
    {

    }

    float Cost()
    {

    }
};

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

int main()
{
    Truck ural;

    cout<<LineCounter("Drivers.txt")<<endl;

    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    fgets(ural.driver, 32, (FILE*)filePointer); //Reading the name of the driver directly

    fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
    ural.petrol = atoi(buff);                   //Converting the string to integer

    fgets(buff, 32, (FILE*)filePointer);
    ural.money = atoi(buff);

    fgets(buff, 32, (FILE*)filePointer);
    ural.fullMileage = atoi(buff);

    fgets(buff, 32, (FILE*)filePointer);
    ural.emptyMileage = atoi(buff);

    fclose(filePointer);                        //Closing file


    cout << "Truck driver is: " << ural.driver;
    cout << "Truck petrol is: " << ural.petrol<<endl;
    cout << "Truck money is: " << ural.money<<endl;
    cout << "Truck full mileage is: " << ural.fullMileage<<endl;
    cout << "Truck empty mileage is: " << ural.emptyMileage<<endl;
    cout << "The width of the box in truck is: " << ural.box.width;
    return 0;
}
