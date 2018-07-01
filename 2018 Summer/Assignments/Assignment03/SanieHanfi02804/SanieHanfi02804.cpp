#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Box
{
    int length;                    //defining a variable.
    int width;                     //defining a variable.
    int height;                    //defining a variable.

    Box()                                   //copy constructor, it generates random dimensions.
    {
        length = 5 + rand() % 26;           //random values of length, width and height is generated in the constructor.
        width = 5 + rand() %  26;
        height = 5 + rand() % 26;
    }


    int Volume()                               //volume function defined, calculates the volume of the boxes.
    {
        int dimensions = 0;                    //defining a variable.
        dimensions = length * width * height;      //Volume calculated here and stored in a variable.
        return dimensions;

    }
};

struct Truck
{
    char driver[32];        //a character array is defined here.
    float petrol;           //declaring a variable.
    float money;            //declaring a variable.
    float fullMileage;      //declaring a variable.
    float emptyMileage;     //declaring a variable.
    Box box;                //an object box is created of data type Box.
    Box* totalBoxes = NULL;    //a pointer of type Box is defined here, basically its a pointer array.

    void Load(int numBox)    //load function takes an argument, the argument is the number of packages. It than loads the packages in an array, and calculates volume of each box and adds all the volume.
    {
        totalBoxes = new Box[numBox]; //dynamic array is created, the pointer totalboxes points towards the dynamic array.
        int allVolumes = 0;

        for (int i = 0; i < numBox; i++)     //loop started.
        {
            Box box;                     //object a is created of data type Box, that means it will generate random length and volume and store it in a.
            totalBoxes[i] = box;          //Each value of a is loaded into the pointer at every index, pointer contains the address which stores it in the array.
            allVolumes = box.Volume() + allVolumes;
        }
        cout << "The boxes are loaded, and the total volume of the boxes are:" << allVolumes << endl;    //allVolume is outputed here.

    }
    void Unload()   //deallocating
    {
        delete[] totalBoxes;   //deallocating the array.
        totalBoxes = NULL;    //to ensure there is no memory leak.

    }

    float Cost()   //calculates the total cost of journey, the function also checks if the journey is possible or not.
    {
        float journey = 0;     //variable defined here.
        float returnJourney = 0;
        journey = 60 / fullMileage;  //the amount of fuel required for one way is calculated.
        returnJourney = 60 / emptyMileage;  //the amount of fuel required for the return journey is calculated.
        float totalLitre = 0;   //variable defined here.
        totalLitre = journey + returnJourney;   //total amount of fuel required.
        float totalCost = 0;    //variable defined here.
        totalCost = totalLitre * 2.73;   //total cost of journey.
        if (totalLitre <= petrol)                    //condition applied, that if total journey fuel is less than the total fuel, than it can travel as there is enough fuel.
        {
            cout << "There is enough fuel for the journey" << endl;
            int package = 0;
            package = (12 + rand() % 8); //random number of packages is being generated so that it can be passed in the load function.
            cout << "Packages being loaded, the number of packages are:" << package << endl;
            Load(package);   //random packages passed in the load function.
            cout << "The fuel consumed in traveling with loaded truck is:" << journey << endl;
            cout << "The boxes are being unloaded now:" << endl;
            Unload();  //unloading function called, so that array could be deallocated.
            cout << "The fuel consumed in the return journey is:" << returnJourney << endl;
            cout << "The total fuel consumed is:" << totalLitre << endl;
            cout << "The total cost of the journey is:" << totalCost << endl;

        }
        else if (totalLitre > petrol && totalCost <= money)    //if total journey fuel required is greater than the already stored fuel than he will check that does he has enough money to buy fuel.
        {
            cout << "There is not enough fuel for the journey" << endl;
            cout << "He is buying fuel" << endl;
            float extraFuel = 0;
            extraFuel = totalLitre - petrol;  //extra fuel that is needed is calculated.
            cout << "Extra petrol needed is:" << extraFuel << endl;
            float extraCost = 0;
            extraCost = extraFuel * 2.73;   //extra cost needed to buy fuel is calculated.
            cout << "The money needed to buy extra petrol is:"<< extraCost << endl;
            float fundsLeft = 0;
            fundsLeft = money - extraCost; //remaining funds is being calculated.
            int package = 0;
            package = (12 + rand() % 8);  //random number of packages are being generated.
            cout << "Packages being loaded, the number of packages are:" << package << endl;
            Load(package); //random packages is being passed in the load function.
            cout << "The fuel consumed in traveling with loaded truck is:" << journey << endl;
            cout << "The boxes are being unloaded now:" << endl;
            Unload(); //deallocating the array.
            cout << "The fuel consumed in the return journey is:" << returnJourney << endl;
            cout << "The total fuel consumed is:" << totalLitre << endl;
            cout << "The total cost of the journey is:" << totalCost << endl;
            cout << "The remaining funds are:" << fundsLeft << endl;
        }
        else if(totalLitre > petrol && totalCost > money)
        {
            cout << "cannot travel" << endl;
        }

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

    while(fgets(buff, 32, (FILE*)filePointer) != NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}

int main()
{
    srand(time(NULL));
    cout << LineCounter("Drivers.txt") << endl;

    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line
    int line = 0;
    line = LineCounter("Drivers.txt");            //the line count is stored in a variable.

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    else
    {

        int entries = 0;  //variable defined here.

        entries = line / 5;  //the number of entries is being calculated. As each entry takes 5 lines so dividing it by line count gives us the number of drivers.
        Truck truck;    //an object truck is created of data type Truck.
        Truck* allTrucks = NULL;  //pointer array is created.
        allTrucks = new Truck[entries];   //dynamic array is created, so that all the Truck object can be saved in the array. allTrucks is used as it is a pointer and an array is a pointer.

        for (int i = 0; i < entries; i++)  //loop is created, which will continue until all the entries are not taken into account.
        {
            Truck ural;   //an object ural is created of data type truck, this will be used to store particular data of the object which is truck.
            fgets(ural.driver, 32, (FILE*)filePointer); //Reading the name of the driver directly

            fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
            ural.petrol = atoi(buff);                   //Converting the string to integer

            fgets(buff, 32, (FILE*)filePointer);
            ural.money = atoi(buff);

            fgets(buff, 32, (FILE*)filePointer);
            ural.fullMileage = atoi(buff);

            fgets(buff, 32, (FILE*)filePointer);
            ural.emptyMileage = atoi(buff); // above it reads the entry of the first driver and stores all the information in the object ural, and than moves to the second driver.

            allTrucks[i] = ural;  //the information of the truck is stored in an array, each index has a different truck object.
            cout << "Truck driver is: " << ural.driver;
            cout << "Truck petrol is: " << ural.petrol << endl;
            cout << "Truck money is: " << ural.money << endl;
            cout << "Truck full mileage is: " << ural.fullMileage << endl;
            cout << "Truck empty mileage is: " << ural.emptyMileage << endl;
            cout << "The width of one box in truck is: " << ural.box.width << endl;
            allTrucks[i].Cost();  //the cost for each truck is calculated.

        }

    delete[] allTrucks; //after calculating the cost of each truck, the truck array is deallocated.
    allTrucks = NULL;  //to ensure that there is no memory leak.
    }

fclose(filePointer); //file closed.

return 0;
}






