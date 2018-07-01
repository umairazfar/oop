#pragma once
#include"Driver.h"
#include<iostream>

class Truck
{
private:

    Driver information;
    float loadedMileage;
    float emptyMileage;
    float petrolPresent;

public:

    Truck();
    Truck(Driver, int, int, int);
    ~Truck();
    void TruckInfo();
    double TankRefill();
    bool JourneyPossibility();

};
