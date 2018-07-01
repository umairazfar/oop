#include"Truck.h"

Truck::Truck()
{
    information.Name = "Test Driver";
    information.Cash = 15.8;
    petrolPresent = 34;
    emptyMileage = 10;
    loadedMileage = 9;
    std::cout<<"Constructor Called"<<std::endl;
}

Truck::Truck(Driver information, int emptyMileage, int loadedMileage, int petrolPresent)
{
    this->emptyMileage = emptyMileage;
    this->loadedMileage = loadedMileage;
    this->petrolPresent = petrolPresent;
    this->information = information;
    std::cout<<"Overloaded Constructor Called"<<std::endl;
}

Truck::~Truck()
{
    std::cout<<"Destructor Called"<<std::endl;
}

void Truck::TruckInfo()
{
    cout<<"Driver : "<<information.Name<<endl;
    cout<<"Petrol : "<<petrolPresent<<endl;
    cout<<"Cash : "<<information.Cash<<endl;
    cout<<"emptyMileage : "<<emptyMileage<<endl;
    cout<<"loadedMileage : "<<loadedMileage<<endl;
}

double Truck::TankRefill()
{
    double petrolCharges = (50 - petrolPresent) * 2.73;

    if(petrolCharges > information.Cash)
    {
        cout<<"foo"<<endl;
        double tempPetrol;
        tempPetrol = information.Cash/2.73;
        information.Cash = information.Cash - tempPetrol*2.73;
        this->petrolPresent += tempPetrol;
    }
    else
    {
        information.Cash = information.Cash - petrolCharges;
        petrolPresent = 50;
    }
    return petrolCharges;

}

bool Truck::JourneyPossibility()
{
    if (TankRefill() <= information.Cash)
    {
        return true;
    }
    else
    {
        return false;
    }

}

