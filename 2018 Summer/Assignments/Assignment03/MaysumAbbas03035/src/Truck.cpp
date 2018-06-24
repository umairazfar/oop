#include "Truck.h"
#include<stdlib.h>//For random numbers
#include <iostream>
using namespace std;
const int FullTankInLiters=50;

Truck::Truck()
{
    petrol=0.0f;
    money=0;
    fullMileage=0;
    emptyMileage=0;
    PetrolNeedToFull=0;
    CostToFull=0.0f;
    TotalLitersForJourney=0.0f;
    NumOfBoxes=0;
    DynTruckbox = NULL;
}

Truck::~Truck()
{
    //In Unload Function, Memory was deallocated
}

void Truck::Load()
{
    NumOfBoxes = rand() % 9 + 12;       //NumOfBoxes in the range 12-20
    DynTruckbox=new Box[NumOfBoxes];    //Creating Dynamic array of Boxes
    petrol=FullTankInLiters;            // Tank filled up to 50 liters
    cout<<"Truck driver : "<<driver;
    cout<<"Num of Boxes loaded = "<<NumOfBoxes<<endl;
    cout<<"Loaded Truck Travels 60 km"<<endl;
}
void Truck::Unload()
{
    if (DynTruckbox!=NULL)
    {
        delete [] DynTruckbox; // memory deallocation
        cout<<"Boxes Unloaded"<<endl;
    }
}

void Truck::Cost()
{
    petrol=FullTankInLiters-TotalLitersForJourney; //Petrol Consumed
    cout<<"Empty Truck Returns with "<<petrol<<" liters left in the tank"<<endl;
    float TripCost=TotalLitersForJourney*(2.73); //Calculating the total trip cost
    cout<<"Cost For the Trip = "<<TripCost<<"$"<<endl<<endl;
}
