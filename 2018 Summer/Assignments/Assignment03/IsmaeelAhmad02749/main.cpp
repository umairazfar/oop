#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include<time.h>

using namespace std;

struct Box
{
    int length;
    int width;
    int height;

    int randomDimension = (rand() % 26) + 5;
    int* ptr_randomDimension = &randomDimension;


    Box()
    {
        length = width = height = *ptr_randomDimension ;//randomDimension;
    }


    int Volume()
    {
        return *ptr_randomDimension * *ptr_randomDimension * *ptr_randomDimension;
    }
};

struct Truck
{
    char driver[32];
    int petrol;
    float money;
    int fullMileage;
    int emptyMileage;
    Box box;

    int numBox = rand() % 9 + 12;
    Box* p = new Box[numBox]; //d.array to store boxes

    void Load(int boxes) //how many boxes will be stored in this truck
    {
        cout<<"the number of boxes to be loaded truck are "<<numBox<<endl;
        int i = 0; //index in array

        for (int q = 0; q < numBox; q++) //filling in the D.array wd bxes.
        {
            cout<<p[i].height<<" ,";
            p[i] = Box();
            i++;
        }
        cout<<endl;
        cout<<"no of boxes loaded into the truck: "<<i<<endl;
        cout<<endl;
    }

    void Unload()
    {
        delete[] p;
    }

    void PetrolPump()
    {

        //has to incorporate mney too
        while (money > 0 && petrol < 50)
        {
            //rate is $2.73/litre
            petrol++;
            money = money - 2.73;
        }

    }

    float petConsumption()
    {
        float goingFuel = 60.0/fullMileage; //this much litres needed for going journey
        float returnFuel = 60.0/emptyMileage; //fuel needed for return journey
        return goingFuel + returnFuel;
    }

    float Cost()
    {
        return petConsumption() * 2.73;
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
    srand(time(NULL));

    cout<<LineCounter("Drivers.txt")<<endl;

    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }

    Truck* trucksArr = new Truck[LineCounter("Drivers.txt")];


    for (int i =0; i <LineCounter("Drivers.txt")/5; i++) //iterate over the file depending on  number of lines.
    {
        trucksArr[i] = Truck();
        fgets(trucksArr[i].driver, 32, (FILE*)filePointer); //Reading the name of the driver directly

        fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
        trucksArr[i].petrol = atoi(buff);                   //Converting the string to integer

        fgets(buff, 32, (FILE*)filePointer);
        trucksArr[i].money = atoi(buff);

        fgets(buff, 32, (FILE*)filePointer);
        trucksArr[i].fullMileage = atoi(buff);

        fgets(buff, 32, (FILE*)filePointer);
        trucksArr[i].emptyMileage = atoi(buff);

        cout<<endl;

        int needMore; //petrol needed more
        int costofthis; //cost of addition petrol needed
        bool needPetrol = false;
        bool hasenufmoney = true;

        if (trucksArr[i].petConsumption() > trucksArr[i].petrol)
        {
            needPetrol = true;
            needMore = trucksArr[i].petConsumption() - trucksArr[i].petrol;
            costofthis = needMore * 2.73;
            //
            if (costofthis > trucksArr[i].money)
            {

            }

        }

        if (needPetrol == false)
        {
            trucksArr[i].Load(trucksArr[i].numBox);
            cout<<"cost of the trip is "<< trucksArr[i].Cost()<<endl;

            if (trucksArr[i].petConsumption() > trucksArr[i].petrol)
            {
                cout<<"need this much petrol "<<trucksArr[i].petConsumption()<<endl;
                cout<<"has this much "<<trucksArr[i].petrol<<endl;
                trucksArr[i].PetrolPump();
                cout<<"had to full the tank before departing."<<endl;

                cout << "Truck driver is: " << trucksArr[i].driver;
                cout << "Truck petrol is: " << trucksArr[i].petrol<<endl;
                cout << "Truck money is: " << trucksArr[i].money<<endl;
                cout << "Truck full mileage is: " << trucksArr[i].fullMileage<<endl;
                cout << "Truck empty mileage is: " << trucksArr[i].emptyMileage<<endl;
                cout << endl<<endl;

                trucksArr[i].Unload();
            }//if loop ends, checks if tank needs to be filled before journey.
            else
            {
                cout << "Truck driver is: " << trucksArr[i].driver;
                cout << "Truck petrol is: " << trucksArr[i].petrol<<endl;
                cout << "Truck money is: " << trucksArr[i].money<<endl;
                cout << "need petrol "<<needMore<<". It will cost "<<costofthis<<". But truck money is not enough."<<endl;
                cout<<"sorry this truck cannot load, doesnt have enough funds"<<endl;
            }
        }//if loop ends, check if a truck can load.
        cout<<endl;
    }//for loop ends here

    cout << endl;
    fclose(filePointer);                        //Closing file
    delete[] trucksArr;
    return 0;
}//main ends
