/*
Habib University, Summer Semester 2018,
Object Oriented Programming & Design Methodologies(CS224),
Assignment # 03; Package Delivery System.

Instructor: Dr. Umair Azfar Khan
TA: Ahmed Ali(aa02190)

Choudhry Bilal Mazhar (cm00326)
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

class Box
{
    int length;
    int width;
    int height;
    int volume;

public:    //public functions

    Box()  //Constructor
    {
        length = 5 + (rand() % 26);   //length between 5 and 30 inches
        width = 5 + (rand() % 26);    //width between 5 and 30 inches
        height = 5 + (rand() % 26);   //height between 5 and 30 inches
    }

    void Volume()    //calculates the volume of each box
    {
        volume = length * width * height;
    }

    int getVolume()  //returns the volume of the box
    {
        return volume;
    }

};

class Truck
{
    char driver[32];
    int petrol;
    int money;
    int loaded_mileage;
    int empty_mileage;
    float total_journey;
    float cost_per_litre;
    float max_petrol;
    Box *arrayBox;      //initializing boxes array

public:     //public functions

    Truck()     //Constructor
    {
        total_journey = 60;      //distance of the journey
        cost_per_litre = 2.73;   //cost for one liter of petrol
        max_petrol = 50;         //tank limit
    }

    void setDriver(char d[32])    //acceses the name of the driver from main and sets it here
    {
        strcpy(driver, d);   //character array d is copied to driver
    }

    string getDriver()           //returns the name of the driver
    {
        return driver;
    }

    void setPetrol(int p)        //acceses the value of petrol from main and sets it
    {
        petrol = p;
    }

    int getPetrol()
    {
        return petrol;
    }

    void setMoney(int m)
    {
        money = m;
    }

    int getMoney()
    {
        return money;
    }

    void setEmileage(int emileage)
    {
        empty_mileage = emileage;
    }

    int getEmileage()
    {
        return empty_mileage;
    }

    void setLmileage(int lmileage)
    {
        loaded_mileage = lmileage;
    }

    int getLmileage()
    {
        return loaded_mileage;
    }

    int checker()   //checks whether the truck has enough money to go and deliver packages
    {
        int up;
        float money_needed;
        if (petrol < 50)   //checks if the driver has less than 50 liters of petrol
        {
            up = max_petrol - petrol;   //amount of liters needed
            money_needed = up * cost_per_litre;  //the amount of money needed to fill the tank
            if(money_needed > money)  //if the amount of money needed is greater than the money the driver has then this truck can't go
            {
                cout << "The money needed to fill the tank is $" << money_needed << " and the driver initially has $ " << money << endl;
                return 0;
            }
            else    //if the driver has enough cash to fill the tank then he can go
            {
                petrol = petrol + up;  //fills the tank to 50 litres
                cout << "\nThe money needed to fill the tank is $ " << money_needed << " and the driver initially has $ " << money << endl;
                money = money - money_needed;    //the cash needed to fill the tank is subtracted from the initial money
                return 1;
            }
        }
        return 0;
    }

    void print()     //function prints out the updated details of the truck's driver
    {
        cout << "\n----->>> Driver is good to go!" << endl;
        cout << "-----> Updated Details: " <<endl;
        cout << "\n*******************************************" <<endl;
        cout << "Truck driver name: " << driver <<endl;
        cout << "Truck's petrol: " << petrol<<" liters"<<endl;
        cout << "Truck driver's money: $ " << money <<endl;
        cout << "Truck's mileage when loaded: " << loaded_mileage<<" km"<<endl;
        cout << "Truck's mileage when empty: " << empty_mileage<<" km\n"<<endl;


    }

    void Load(int numBox)      //loads boxes into the truck
    {
        arrayBox = new Box[numBox];
        for (int i = 0; i<numBox; i++)
        {
            Box b;
            b.Volume();   //stores the volume
            arrayBox[i] = b;
            cout << "Volume of box " << i+1 << ": " << arrayBox[i].getVolume() << " cubic inches" << endl;
        }
    }

    void Unload()           //unloads boxes from the truck
    {
        delete[] arrayBox;    //deallocates the array
    }

    float Cost()           //calculates the total cost for the complete journey
    {
        float lit, total, lit1;
        lit = (total_journey/loaded_mileage) * cost_per_litre;   //money needed for going
        lit1 = (total_journey/empty_mileage) * cost_per_litre;  //money needed for coming back
        total = lit + lit1;               //total cost for the journey
        cout << "\nThe total cost of the journey is $ " << total << endl;
        return total;
    }
};

int LineCounter(const char* fileName)   //tells the number of lines needed
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
    srand(time(0));
    FILE* filePointer;                          //Declaring a file pointer
    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only
    int count = LineCounter("Drivers.txt");
    int count1 = count/5;                       //since each driver has 5 lines of info

    Truck *arrayTruck;
    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }
    arrayTruck = new Truck[count1];

    cout <<"                              PACKAGE DELIVERY SYSTEM\n"<<endl;

    for (int i = 0; i<count1; i++)
    {
        cout <<"----------------------------------------("<<i+1<<")----------------------------------------"<<endl;
        Truck t;                //creating an object
        char buff[32];          //Declaring a character array to store a line

        fgets(buff, 32, (FILE*)filePointer); //Reading the name of the driver directly
        t.setDriver(buff);

        fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
        t.setPetrol(atoi(buff));                //Converting the string to integer

        fgets(buff, 32, (FILE*)filePointer);
        t.setMoney(atoi(buff));

        fgets(buff, 32, (FILE*)filePointer);
        t.setEmileage(atoi(buff));

        fgets(buff, 32, (FILE*)filePointer);
        t.setLmileage(atoi(buff));

        cout << "Truck driver name: " << t.getDriver() <<endl;
        cout << "Truck's petrol: " << t.getPetrol() <<" liters"<<endl;
        cout << "Truck driver's money: $ " << t.getMoney() <<endl;
        cout << "Truck's mileage when loaded: " << t.getLmileage() <<" km"<<endl;
        cout << "Truck's mileage when empty: " << t.getEmileage() <<" km"<<endl;

        int random_boxes =  12+(rand() % 9);  //random packages between 12 to 20
        if (t.checker() == 1)            //checks if the driver has enough money to go
        {
            t.print();
            cout << random_boxes << " Packages have been loaded on the truck:\n" << endl;
            t.Load(random_boxes);
            t.Unload();
            cout << "\nThe truck has been unloaded!" << endl;
            t.Cost();
            cout << endl;
        }
        else          //if the checker function returns 0 then that truck can't go
        {
            cout << "\n----->>> This truck can't go!\n" << endl;
        }
        arrayTruck[i] = t;
    }

    delete [] arrayTruck;                       // deallocating array of truck
    fclose(filePointer);                        //Closing file
    return 0;
}
