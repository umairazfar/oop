#include<iostream> //Similar to import command in Python
#include<stdio.h>
#include<stdlib.h> //For random numbers
#include<time.h>   //For generating a new random seed



using namespace std; //required for using cin and cout commands

struct Box
{
    int length;  //declaring variables;
    int width;   //declaring variables;
    int height;  //declaring variables;
    int vol;     //declaring variables;

    Box()
    {

        length = (rand() % 26) +5;   //generating a random value for length
        width = (rand() % 26) +5;    //generating a random value for width
        height = (rand() % 26) +5;   //generating a random value for height
        vol= height * width * length; //calculating the volume of a box
    }


    int Volume()
    {
        return vol;  //returning the volume value calculated above
    }
};

struct Truck
{
    string driver;      //declaring variables
    float journeyCost;  //declaring variables
    double petrol;      //declaring variables
    float money;        //declaring variables
    int boxesNumber;    //declaring variables
    float fullMileage;  //declaring variables
    float emptyMileage; //declaring variables
    float totalCost;    //declaring variables
    bool canGo=false;   //declaring variables
    Box* boxes= NULL;   //declaring pointer of type Box
    float petrolPresent;//declaring variables
    float petrolRequired; //declaring variables
    float costForFullTank; //declaring variables
    float destinationFuel;//declaring variables
    float journeyFuel;   //declaring variables

    void Load()
    {

        boxesNumber = (rand() % 8) + 12;     //generating a random number for number of boxes
        boxes = new Box [boxesNumber];       //creating an array of size box number to store the dimension of boxes
        for (int i = 0; i<boxesNumber; i++)  //running a loop
        {
            Box box;
            boxes[i]= box;                    //storing the value in the array
        }

    }
    void Unload()
    {
        for (int i=0; i<boxesNumber;i++)        //running a loop
        {
            cout<<"Unloading box "<<i+1<<" volume = "<<boxes[i].Volume()<<endl; //printing the value of volume
        }
        delete [] boxes;   //deleting the array
        boxes = NULL;      //setting value to null
    }

    void Cost()
    {
        petrol= float(60 / fullMileage ) + float(60 / emptyMileage);  //the amount of petrol used for the journey
        journeyCost= petrol *2.73;  //calculating the cost for the journey
        petrolRequired = 50 - petrolPresent; //the amount of petrol needed to fill the tank full
        destinationFuel= 50 - (60/fullMileage); //petrol left after one way journey
        journeyFuel= destinationFuel - (60/emptyMileage); //petrol left after return from journey
        costForFullTank= petrolRequired * 2.73; //amount required for full tank
        if (money>=costForFullTank)   //condition to check if drivers can make the journey or not
        {
            canGo = true;
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

    while(fgets(buff, 32, (FILE*)filePointer) !=NULL)   //If line read is not NULL
    {
        counter++;                                      //increase line count
    }
    fclose(filePointer);                                //close file when done

    return counter;                                     //return line count
}

int main()
{
    srand(time(NULL)); //generating a random value
    char filename[] = "Drivers.txt"; //creating a character array to store string
    int numberOfTrucks= LineCounter(filename); //number of trucks available
    Truck* trucks=NULL;
    trucks= new Truck [numberOfTrucks/5]; //declaring an array size of number of trucks
    FILE* filePointer;                          //Declaring a file pointer
    char buff[32];                              //Declaring a character array to store a line

    filePointer = fopen("Drivers.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return 0;
    }
    int i=0;
    while (i < numberOfTrucks/5)
    {
        fgets(buff, 32, (FILE*)filePointer); //Reading the name of the driver directly
        for (int i = 0; i < 32 ; i++)
        {
            if (buff[i] == '\n')
            {
                buff[i] = '\0'; //declaring next line as null character
            }
        }
        trucks[i].driver=buff; //storing name of truck driver
        cout << "************************" <<endl;
        cout<<"Driver name "<<trucks[i].driver<<endl;

        fgets(buff, 32, (FILE*)filePointer);        //Reading the next line as string
        trucks[i].petrolPresent = atoi(buff);       //Converting the string to integer
        cout<<"Petrol already present in truck = "<< trucks[i].petrolPresent <<endl;

        fgets(buff, 32, (FILE*)filePointer);  //Reading the next line as string
        trucks[i].money = atoi(buff);         //Converting the string to integer
        cout<<"Money that driver have = "<< trucks[i].money <<endl;

        fgets(buff, 32, (FILE*)filePointer);  //Reading the next line as string
        trucks[i].fullMileage = atoi(buff);   //Converting the string to integer
        cout<<"Truck's full mileage = "<< trucks[i].fullMileage <<endl;

        fgets(buff, 32, (FILE*)filePointer);  //Reading the next line as string
        trucks[i].emptyMileage = atoi(buff);  //Converting the string to integer
        cout<<"Truck's full mileage = "<< trucks[i].emptyMileage <<endl;
        trucks[i].Load(); //calling the load function
        trucks[i].Cost(); //calling the cost function

        if (trucks[i].canGo==true)  //condition whether the truck is able to go for the journey
        {
            cout << (trucks[i].driver);
            cout << " can go." << endl;
        }
         else
        {
            cout << (trucks[i].driver);
            cout<< "'s truck cannot go." << endl;
        }
        i++;
    }
    for (int i=0; i<numberOfTrucks/5; i++)
    {
        if (trucks[i].canGo==true)
        {
            cout << "************************" <<endl;
            cout << (trucks[i].driver) << "'s truck is going." << endl;  //printing the name of driver
            trucks[i].petrolPresent=trucks[i].petrolPresent - float(60/trucks[i].fullMileage);
            cout << "Fuel left after reaching the destination: " << trucks[i].destinationFuel << endl; //fuel left after making one way journey
            trucks[i].Unload();  //calling the unload function
            trucks[i].petrolPresent=trucks[i].petrolPresent - float(60/trucks[i].emptyMileage);
            cout << (trucks[i].driver)<< "'s truck has returned." << endl; //printing when driver has completed the journey
            cout << "Fuel left after the journey: " << trucks[i].journeyFuel << endl; //fuel left after complete journey
            cout << "Cost of journey: $" << trucks[i].journeyCost << endl; //calculating cost of journey
            cout << "************************" <<endl;
        }
    }


    delete [] trucks; //deleting the array
    trucks = NULL;  //setting it to null
    fclose(filePointer);  //closing the file
    return 0;
}
