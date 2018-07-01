//CS224 - Object Oriented Programming - Assignment 03
//Syed Fazl ur Rehman - sr02910

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Box
{

private:

    int length;
    int width;
    int height;

public:

    Box()
    {
        length = rand() % 26 + 5;   //Dimensions of packages may range from 5 to 30 inches
        width = rand() % 26 + 5;
        height = rand() % 26 + 5;
    }
    int Volume()    // calculates and returns volume of box
    {
        int volume = length * width * height;
        return volume;
    }

};

class Truck
{

private:

    char driver[32];
    int petrol;
    int money;
    int fullMileage;
    int emptyMileage;
    Box* box;

public:

    void Load(int& numBox)
    {
        box = new Box [numBox]; //Defining a dynamic array of boxes

        for (int i = 0; i < numBox; i++)
        {
            box[i];
        }

        cout<< "\n" << numBox << " boxes are loaded into the truck." <<endl;
    }

    void Unload(int& numBox)    //Calculates volume and deallocates the array
    {

       cout << "\nTruck is being unloaded..." << endl;

       for (int i = 0; i < numBox; i++)
       {
            int v = box[i].Volume();

            cout << " Volume of package " << i+1 << " in the truck is: " << v << endl;
       }

       delete[] box;    //deallocating the array
    }

    /*****************************/

	//Set and Get functions to access the private variables of class

    void SetPetrol(int newPetrol)
    {
        petrol = newPetrol;
    }

    void SetMoney(int newMoney)
    {
        money = newMoney;
    }

    void SetFullMileage(int newFullMileage)
    {
        fullMileage = newFullMileage;
    }

    void SetEmptyMileage(int newEmptyMileage)
    {
        emptyMileage = newEmptyMileage;
    }

    void SetDriver(char newDriver[32])  //accessing character by character for setting the name of driver
    {
        for (int i = 0; i < 32; i++)
        {
            driver[i] = newDriver[i];
        }
    }

    char* GetDriver()
    {
        return driver;
    }

    int GetPetrol()
    {
        return petrol;
    }

    int GetMoney()
    {
        return money;
    }

    int GetFullMileage()
    {
        return fullMileage;
    }

    int GetEmptyMileage()
    {
        return emptyMileage;
    }

    /*****************************/


    float CostEstimate()    //Calculating the estimated cost before the journey
    {
        int Petrol = GetPetrol();
        int Money = GetMoney();

        float fullTank = 50 - Petrol;   //Amount of petrol to full the tank completely
        float moneyToFull = fullTank * 2.73;    //Money required to full the tank completely
        return moneyToFull;
    }


    float CostTrip()    //Total cost of the trip

    {
        int FullMileage = GetFullMileage();
        int EmptyMileage = GetEmptyMileage();
        int Money = GetMoney();

        float moneyFull = (60 / FullMileage) * 2.73;    //cost per liter of petrol is 2.73 $
        float moneyEmpty = (60 / EmptyMileage) * 2.73;     //total journey require to travel 60 km

        float totalCost = (moneyFull + moneyEmpty);

        return totalCost;

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

    while (fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done
    return counter;                                     //return line count
}


int main()
{

    srand(time(NULL));  //used for generating random number of boxes between 12 to 20
	int randBox = 0;

    int line = LineCounter("Drivers.txt");  //For counting total lines in the file

    FILE* filePointer;   //Declaring a file pointer
    char buff[32];		//Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    int totalTrucks = line / 5;   //Number of lines per entry is 5 and total entries/trucks in 'drivers.txt' are 7

    Truck* truck = new Truck[totalTrucks];  //Declaring dynamic array of trucks

        for (int j = 0 ; j < totalTrucks ; j++)
        {
            if (filePointer == NULL)
            {
                perror ("Error opening file");
                return 0;
            }

            fgets(buff, 32, (FILE*)filePointer); //Reading the name of the driver
            truck[j].SetDriver(buff);

            fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string

            truck[j].SetPetrol(atoi(buff));		//Converting the string to integer

            fgets(buff, 32, (FILE*)filePointer);
            int money = atoi(buff);              //storing in variable for later usage
            truck[j].SetMoney(money);

            fgets(buff, 32, (FILE*)filePointer);

            truck[j].SetFullMileage(atoi(buff));

            fgets(buff, 32, (FILE*)filePointer);

            truck[j].SetEmptyMileage(atoi(buff));

			//Showing the details of each truck and its journey

            cout << " \nTruck " << "-----*  " << j+1 << "  *-----\n " << endl;

            cout << "Truck driver is: " << truck[j].GetDriver() << endl;

            cout << "Truck petrol is: " << truck[j].GetPetrol() << " litres" << endl;
            cout << "Truck money is: $" << money << endl;
            cout << "Truck full mileage is: " << truck[j].GetFullMileage() << " km/litre" << endl;
            cout << "Truck empty mileage is: " << truck[j].GetEmptyMileage() << " km/litre" << endl;

            float petrolCost = truck[j].CostEstimate();     //calculates cost for the trip

            cout << "The cost for the journey is: $ " << petrolCost<< endl;

            float fundLeft = money - petrolCost;    //Calculates the money left with driver


            if(fundLeft > 0)    //If the driver has some money, journey proceeds
            {
				cout << "\nThe driver can do the journey." <<endl;

                randBox = (rand() % 9) + 12;    //generates random no. of packages for each truck

				truck[j].Load(randBox);

                cout << "\nThe cost for the trip was $"<< truck[j].CostTrip() << endl;

                truck[j].Unload(randBox);
            }

            else        //If there is no money left with the driver
            {
                cout << "The driver cannot do the journey!" << endl;
            }
        }


    delete [] truck;		//Deallocating the array
    fclose(filePointer);      //Closing file
}

