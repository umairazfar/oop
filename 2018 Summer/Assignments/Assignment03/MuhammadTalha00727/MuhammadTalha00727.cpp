#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Box
{
    int length;
    int width;
    int height;
    int volume;

    Box()       //Declaring constructor
    {
        srand(time(NULL));
        length = 0;
        width = 0;
        height = 0;
    }

    int Volume()        //Declaring this function to calculate the volume of the boxes
    {
        length = rand()  % 26 + 5;  //generating random dimensions between 5 and 30;
        width = rand() % 26 + 5;
        height = rand() % 26 + 5;
        volume = length * width * height;
        return volume;
    }
};

struct Truck
{
private:
    int numBox;
    string driver_name;       //driver name;
    bool canGo;
    int petrol;             //current petrol in the driver's truck
    float money;           //money that the driver possesses
    int fullMileage;
    int emptyMileage;
    int* box_array;
    Box box;

public:
    void setdriver(string name) //Declaring a function to store driver name
    {
        driver_name = name;
    }

    string getdriver()  //Declaring a function to return driver name
    {
        return driver_name;
    }

    void setpetrol(float quantity)  //Declaring a function to store the petrol the driver has.
    {
        petrol = quantity;
    }

    void setmoney(float amount) //Declaring a function to store the money the driver has.
    {
        money = amount;
    }

    void setfullMileage(float full) //Declaring a function to store full mileage
    {
        fullMileage = full;
    }

    void setemptyMileage(float nil) //Declaring a function to return empty mileage
    {
        emptyMileage = nil;
    }

    float getpetrol()   //Declaring a function to return the petrol the driver has.
    {
        return petrol;
    }

    float getmoney()    //Declaring a function to return the money the driver has.
    {
        return money;
    }

    float getfullMileage()  //Declaring a function to return full mileage
    {
        return fullMileage;
    }

    float getemptyMileage() //Declaring a function to return empty mileage
    {
        return emptyMileage;
    }


    int Load_Unload()
    {
        int numBox  = rand() % 9 + 12;  //generating random numbers (for the boxes that a truck can carry)
        box_array = new int[numBox];        //making a dynamic array to store boxes of random dimensions;
        cout<<numBox<<" Boxes are loaded"<<endl;
        cout<<"The truck driver has sufficient petrol and money, hence the journey has started"<<endl;
        cout<<"Destination reached, boxes are being unloaded"<<endl;
        for (int i = 1; i <= numBox; i++)
        {
            box_array[i] = box.Volume();
            cout<<"Box "<<i<<" of volume "<<box_array[i]<<" is being un-loaded from the truck"<<endl;
        }
        cout<<endl;
        delete[] box_array;         //Deallocating the array of all the boxes
        return 0;
    }

    bool Cost_AndJourneyCheck()
    {
        float petrol_required_cost;

        float petrol_loaded = (60/fullMileage);          //petrol required when the truck is loaded
        float petrol_empty = (60/emptyMileage);         //petrol required when the truck is loaded
        float total_petrol = petrol_loaded + petrol_empty;   //total petrol required
        float money_required = total_petrol * 2.73;         //total cost of the petrol required for going and returning back

        if (petrol < 50)                                  //Truck needs to be full first before making the journey, i.e. petrol must be 50
        {
            float petrol_required = 50 - petrol;                      //petrol required to get the tank full
            petrol_required_cost = petrol_required * 2.73;           //cost required to get the tank full
            if (petrol_required_cost < money)
            {
                cout<<"Yes this truck can make a journey and the total cost of re-filling the tank would be: "<<petrol_required_cost<<"$"<<endl;
                cout<<"However the cost of petrol for the truck to go and return back would be: "<<money_required<<"$"<<endl;
                canGo = true;   //This condition is being used to check if the box can be loaded
            }
            else
            {
                cout<<"This truck cannot make a journey since the required money for re-fueling is: "<<petrol_required_cost<<"$, which is higher than the available money"<<endl;
                cout<<"Boxes are not loaded"<<endl;
                canGo = false;
            }
        }
        return canGo;       //returning the boolen value to check the possibility of journey
    }
};

int LineCounter(char* fileName)
{
    FILE* filePointer;                           //Declaring a file pointer
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
    fclose(filePointer);                                 //close file when done
    return counter;                                     //return line count
}

int main()
{
    srand(time(NULL));
    Truck ural;
    int line_count = LineCounter("Drivers.txt");
    Truck* truck_array = new Truck[line_count/5];      //Dynamic array of truck.

    FILE* filePointer;                               //Declaring a file pointer
    char buff[32];                                  //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");        //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    for (int i = 0; i < line_count/5; i++)
    {

        fgets(buff, 32, (FILE*)filePointer);        //Reading the name of the driver directly
        ural.setdriver(buff);

        fgets(buff, 32, (FILE*)filePointer);         //Reading the next line as string
        ural.setpetrol(atoi(buff));                 //Converting the string to integer

        fgets(buff, 32, (FILE*)filePointer);
        ural.setmoney(atoi(buff));

        fgets(buff, 32, (FILE*)filePointer);
        ural.setfullMileage(atoi(buff));

        fgets(buff, 32, (FILE*)filePointer);
        ural.setemptyMileage(atoi(buff));

        truck_array[i] = ural;

    }

    fclose(filePointer);                         //Closing file

    for (int i = 0; i < line_count/5; i++)
    {
        cout<<endl;
        cout << "Truck driver is: " << truck_array[i].getdriver()<<endl;    //Calling function to get the current driver name
        cout << "Truck full mileage is: " << truck_array[i].getfullMileage()<<endl; //Getting the mileage at loaded truck
        cout << "Truck empty mileage is: " << truck_array[i].getemptyMileage()<<endl;   //Getting the mileage at empty truck
        bool check = truck_array[i].Cost_AndJourneyCheck(); //Getting the cost and possibility of journey of each truck
        if (check == 1)
        {
            truck_array[i].Load_Unload();      //Loading and unloading the boxes if the journey is possible
        }
    }
    delete[] truck_array;       //deallocating the array of all the trucks
    return 0;
}
