#include"Light.h"
#include<iostream>

Light::Light()
{
    activated = false;
    brightness = 0;
}

Light::Light(bool active, int bright)
{
    activated = active;
    if(active == true)
        if(bright>0 && bright<=10)
            brightness = bright;
        else
            brightness = 1;
}

void Light::Brighten()
{
    if(activated)
        if(brightness<10)
            brightness++;
}

void Light::Dim()
{
    if(activated)
        if(brightness>1)
            brightness--;
}

void Light::ShowStatus()
{
    if(activated == true)
    {
        std::cout<<"Light is active"<<std::endl;
        std::cout<<"The brightness level is "<<brightness<<std::endl;
    }
    else
        std::cout<<"Light is not active"<<std::endl;
}

