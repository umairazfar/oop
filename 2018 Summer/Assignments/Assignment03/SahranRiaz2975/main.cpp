#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cstdlib>
#include <string>
#include <time.h>


//*important
//In my code the driver will fill the tank up to 50 liters not only before traveling for 60 km loaded
//but also before traveling for 60 km unloaded.

using namespace std;

//Structure for a box is made below
struct Box
{
    //Box has three attributes
    int length;
    int width;
    int height;

    Box() //Default constructor, whenever an object of the data type of box is created, all three of its dimensions are set to be random in the range of 5-30 inches
    {
        length = ((rand() % 26) + 5); //A random number in the range 5-30 is generated
        width  = ((rand() % 26) + 5); //A random number in the range 5-30 is generated
        height = ((rand() % 26) + 5); //A random number in the range 5-30 is generated
    }

    int Volume()
    {
        int volume = (length * width * height); //Whenever this function is invoked with an object, it returns the volume of the box
        return volume;
    }
};

//Structure for a truck is made below
struct Truck
{
    char driver[32]; //Stores the name of the driver from the text file
    float petrol;    //Stores the amount of petrol available in a truck, by default, from the text file
    float money;     //Stores the amount of money available with a truck driver, by default, from the text file
    float fullMileage; //Stores the mileage value of a truck when loaded, from the text file
    float emptyMileage; //Stores the mileage value of a truck when unloaded, from the text file
    Box* box; //A pointer of the data type of box that points to a dynamic array of boxes
    const float costPerLiter = 2.73; //A constant float value for the cost per liter of petrol, it remains unchanged
    const float fullTank = 50.0; //A truck can hold a maximum of 50 liters of petrol
    int numOfBoxes; //Stores the random number of boxes in the range 12-20 that are to be loaded into the truck
    bool loadPossible = false; //A boolean variable which is used to determine whether it is possible to travel for 60 km while loaded
    bool roundOne = true; //If true then the function that renders the cost of journey for 60 km while loaded runs
    bool roundTwo = false; //If true then the function that renders the cost of journey for 60 km while unloaded runs
    bool journeyPossible = false; //A boolean variable which is used to determine whether it is possible to travel for 60 km while unloaded
    float costOneWay = 0; //Stores the amount of money required to travel for 60 km while loaded
    float costWayBack = 0; //Stores the amount of money required to travel for 60 km while unloaded

    //The load function, an instance member function of the truck structure is defined below
    void Load(int numBox) //A random number in the range 12-20 is passed into this function through the main function
    {
        if (loadPossible == true && journeyPossible == true) //Only if it is possible to travel while loaded and back while unloaded, do the following
        {
            numOfBoxes = numBox;
            if (numBox >= 12 && numBox <= 20) //Check to see whether boxes passed are in the range 12-20
            {
                cout << "Boxes loaded into this truck are " << numBox << endl;
                box = new Box[numBox]; //Accordingly box pointer is assigned the address of the first box in the dynamic array of boxes of size numBox
            }
            else
            {
                cout << "A truck can only contain 12 to 20 packages" << endl;
            }
        }
        else
        {
            cout << "Since this truck cannot make the journey, boxes cannot be loaded into it" << endl;
        }
    }
    //The load function, an instance member function of the truck structure is defined below
    void Unload()
    {
        if (loadPossible == true && journeyPossible == true) //Only if it is possible to travel while loaded and back while unloaded, do the following
        {
            cout << "The contents of this truck are being unloaded" << endl;
            for (int j = 0; j < numOfBoxes; j++) //Runs for the number of boxes stored in the truck
            {
                cout << "Box " << j + 1 << " has a volume of " << box[j].Volume() << " inches cubed" << endl; //Prints the volume of each box in the array of boxes
            }
            delete[]box; //The array of boxes is deleted, memory is freed after the volume of all the boxes stored in one truck is printed
            box = NULL; //box pointer is deallocated
        }
        else
        {
            cout << "Boxes were not loaded into this truck, so unloading is not possible" << endl;
        }
    }
    //An instance member function that determines whether it is possible for a truck to make a complete journey
    void JourneyPossible()
    {
        if ((journeyPossible == true) && (loadPossible == true))
        {
            cout << "This truck can make the 60 km journey while loaded as well as another 60 km journey while unloaded" << endl;
        }
        else
        {
            cout << "This truck cannot make the journey" << endl;
            costOneWay = 0;  //Cost to travel loaded set once again to 0
            costWayBack = 0; //Cost to travel unloaded set once again to 0
        }
     }
    //An instance member function that explores the possibility for a truck to travel while loaded
    float CostOneWay()
    {
        float litres_For60Loaded = (60 / fullMileage); //Determines the amount of petrol required for a truck to travel 60 km while loaded
        while(roundOne) //If true then run
        {
            cout << "Petrol required by this truck to travel for 60 km while loaded is " << litres_For60Loaded << " liters" << endl;
            if (litres_For60Loaded <= fullTank) //This condition will not run if the petrol required to make this journey exceeds 50 liters
            {
                if (petrol < fullTank) //This condition runs if the default petrol quantity is less than 50 liters, amount will be calculated to acquire a full tank of petrol
                {
                    float deficitPetrol = fullTank - petrol; //Stores the amount of petrol needed to complete 50 liters
                    cout << "This truck requires a further " << deficitPetrol << " liters of petrol to fill the tank" << endl;
                    float amountForDeficit = (deficitPetrol * costPerLiter); //Does the costing to acquire the deficit petrol amount
                    if (amountForDeficit > money) //This condition runs if that amount to achieve deficit is greater than the amount of money the truck driver possesses
                        {
                            cout << "This truck cannot make the 60 km journey, while loaded, due to insufficient balance required to meet the deficit petrol demand" << endl;
                            return costOneWay;
                        }
                    else if (amountForDeficit <= money) //This condition runs if that amount to achieve deficit is less than or equal to the amount of money the truck driver possesses
                        {
                            cout << "This truck can make the journey for 60 km while loaded  as it has sufficient balance to meet the deficit petrol demand" << endl;
                            loadPossible = true; //Now the truck loading only depends on whether the return journey is possible
                            petrol = petrol + deficitPetrol; //Petrol is made 50 liters if the journey is made, once for loaded truck and once for unloaded truck
                            cout << "This truck will have " << petrol << " liters of petrol after refill" << endl;
                            cout << amountForDeficit << " rupees will be spent on petrol" << endl;
                            petrol = petrol - litres_For60Loaded; //According to the mileage for loaded, the amount of petrol remaining if the journey is made while the truck is loaded is stored in this variable
                            costOneWay = amountForDeficit; //If the journey is made, the cost to travel while loaded is stored in this variable
                            money = money - amountForDeficit; //If the journey is made, then after the journey while loaded, the amount of money remaining with the driver is stored in this variable
                            cout << "This truck will have " << petrol << " liters of petrol remaining after traveling one way" << endl;
                            cout << "This truck driver will have " << money << " rupees remaining after traveling one way" << endl;
                            roundTwo = true; //Since it is possible to travel one way, lets explore the possibility to travel the way back to determine whether the truck can make the journey
                            return costOneWay;
                        }
                }
                else if (petrol > fullTank) //A check to make the program error free
                {
                    cout << "This truck cannot travel for 60 km while loaded as it contains excessive fuel of more than 50 liters" << endl;
                    return costOneWay;
                }
                else if (petrol == fullTank) //The difference this time is that costing will not be performed since enough petrol is available to make the journey while loaded
                {
                    cout << "This truck can make the journey for 60 km while loaded as it has sufficient amount of petrol" << endl;
                    loadPossible = true;
                    petrol = petrol - litres_For60Loaded;
                    cout << "This truck will have " << petrol << " liters of petrol remaining after traveling one way " << endl;
                    roundTwo = true;
                    return costOneWay;
                }
            }
            else if (litres_For60Loaded > 50) //Check to remove errors in the program
            {
                cout << "This truck has a capacity to hold 50 liters of fuel, therefore it cannot make the journey for 60 km while loaded" << endl;
                return costOneWay;
            }
            roundOne = false; //This loop will end after running once
        }
    }
    //An instance member function that explores the possibility for a truck to travel while unloaded, return journey
    //The procedure is the same as the one for the journey while loaded.
    float CostReturn()
    {
        while (roundTwo)
        {
            float litres_For60Unloaded = (60 / emptyMileage); //This time mileage value for an unloaded truck is used
            cout << "The amount of petrol required by this truck to travel for 60 km while unloaded is " << litres_For60Unloaded << " liters" << endl;
            if (litres_For60Unloaded <= fullTank)
            {
                if (petrol < fullTank)
                {
                    float petrolDeficit = fullTank - petrol;
                    cout << "This truck requires a further " << petrolDeficit << " liters of petrol to fill the tank to return to its destination" << endl;
                    float deficitAmount = (petrolDeficit * costPerLiter);
                    if (deficitAmount > money)
                    {
                        cout << "This truck cannot make the journey back, unloaded, due to insufficient balance required to meet the deficit petrol demand" << endl;
                        return costWayBack;
                    }
                    else if (deficitAmount <= money)
                    {
                        cout << "This truck can make the journey back, unloaded, due to sufficient balance to meet the deficit petrol demand" << endl;
                        petrol = petrol + petrolDeficit;
                        cout << "This truck will have " << petrol << " liters of petrol after refill" << endl;
                        cout << deficitAmount << " rupees will be spent on petrol" << endl;
                        costWayBack = deficitAmount;
                        petrol = petrol - litres_For60Unloaded;
                        money = money - deficitAmount;
                        cout << "This truck will have " << petrol << " liters of petrol remaining upon return to its destination" << endl;
                        cout << "This truck driver will have " << money << " rupees remaining upon his return" << endl;
                        journeyPossible = true; //This variable ensures that the boxes are loaded into the truck, since the journey both ways is now possible
                        return costWayBack;
                    }
                }
                else if (petrol > fullTank) //Check to remove errors in the program
                {
                    cout << "This truck cannot travel back, unloaded, as it contains excessive fuel of more than 50 liters" << endl;
                    return costWayBack;
                }
                else if (petrol == fullTank)
                {
                    cout << "This truck has sufficient amount of petrol to make the journey back, unloaded" << endl;
                    petrol = petrol - litres_For60Unloaded;
                    cout << "This truck will have " << petrol << " liters of petrol remaining upon return" << endl;
                    journeyPossible = true; //This variable ensures that the boxes are loaded into the truck, since the journey both ways is now possible
                    return costWayBack;
                }
            }
            else if (litres_For60Unloaded > 50) //Check to remove errors from the program
            {
                cout << "This truck has a capacity to hold 50 liters of fuel, therefore it cannot make the journey back, unloaded" << endl;
                return costWayBack;
            }
            roundTwo = false; //This loop ends now
        }
        return costWayBack;
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

    int counter = 0;                                    //Counts the lines in file

    while(fgets(buff, 32, (FILE*)filePointer) != NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}

int main()
{
    srand(time(NULL)); //Done so every time the program is run, different random values are generated
    int linesInFile = LineCounter("Drivers.txt"); //Stores the number of lines in the file
    cout << linesInFile<<endl;
    cout << endl;
    int numTrucks = (linesInFile / 5); //Since each truck will have five details, the number of lines are divided by five to determine the number of times the for loop is run and the size of the dynamic array of trucks
    Truck* TRUCKS = new Truck[numTrucks];

    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    if (filePointer == NULL)                    //Check for incorrect or faulty file
    {
        perror ("Error opening file");
        return 0;
    }

    else
    {
        //In this for loop the data from the text file is picked up and assigned to the relevant variables for each of the trucks in the array of trucks
        for (int i = 0; i < numTrucks; i++)
        {
            fgets(TRUCKS[i].driver, 32, (FILE*)filePointer);
            fgets(buff, 32, (FILE*)filePointer);                     //Reading the next line as string
            TRUCKS[i].petrol = abs(atoi(buff));                      //Converting the string to integer, abs ensures that negative data is made positive before being assigned since negative data does not make much sense in this program
            fgets(buff, 32, (FILE*)filePointer);
            TRUCKS[i].money = abs(atoi(buff));
            fgets(buff, 32, (FILE*)filePointer);
            TRUCKS[i].fullMileage = abs(atoi(buff));
            fgets(buff, 32, (FILE*)filePointer);
            TRUCKS[i].emptyMileage = abs(atoi(buff));
        }
        fclose(filePointer);                                         //Closing file

        for (int k = 0; k < numTrucks; k++)
        {
            //Relevant details for each truck are printed out one after the other
            cout <<"************************************************************************************************************************" << endl;
            cout << "Truck " << k + 1 << " driver is " << TRUCKS[k].driver << endl;
            cout << "Truck " << k + 1 << " petrol is " << TRUCKS[k].petrol << " litres" << endl;
            cout << "Truck " << k + 1 << " money is RS. " << TRUCKS[k].money << endl;
            cout << "Truck " << k + 1 << " full mileage is " << TRUCKS[k].fullMileage << " km/litre" << endl;
            cout << "Truck " << k + 1 << " empty mileage is " << TRUCKS[k].emptyMileage << " km/litre" << endl;
            int randomBoxes = ((rand() % 9) + 12);
            float cost = TRUCKS[k].CostOneWay();
            float cost2 = TRUCKS[k].CostReturn();
            float cost3 = cost + cost2; //Cost3 stores the total cost of the journey
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            TRUCKS[k].JourneyPossible();
            cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
            if (TRUCKS[k].journeyPossible == false)
            {
                cost3 = 0; //If return journey is not possible then the truck will not leave at all, and total cost of journey will become 0
            }
            TRUCKS[k].Load(randomBoxes);
            TRUCKS[k].Unload();
            cout << "The total cost of journey for Truck " << k + 1 << " is RS. " << cost3 << endl;
            if ((TRUCKS[k].loadPossible == true) && (TRUCKS[k].journeyPossible == true))
            {
                cout << "Truck " << k + 1 << " has returned" << endl;
                cout << endl;
            }
            else
            {
                cout << "Truck " << k + 1 << " did not leave" << endl;
                cout << endl;
            }
        }
        delete [] TRUCKS; //Dynamic array of trucks is deleted
        TRUCKS = NULL;    //TRUCKS pointer is being deallocated
    }
    return 0;
}
