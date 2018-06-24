#ifndef TRUCK_H
#define TRUCK_H
#include<stdlib.h>//For random numbers
#include<time.h>//For generating a new random seed
#pragma once
#include"Box.h"

class Truck
{
    public:
        char driver[32]; //Driver name of 32 Characters
        float petrol;
        int money;
        int fullMileage;
        int emptyMileage;

        int PetrolNeedToFull;
        float CostToFull;
        float TotalLitersForJourney;
        int NumOfBoxes;

        Box *DynTruckbox ;
        Truck(); //Constructor
        ~Truck(); //Destructor
        void Load();
        void Unload();
        void Cost();

};

#endif // TRUCK_H
