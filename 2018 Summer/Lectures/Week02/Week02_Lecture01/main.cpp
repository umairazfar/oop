#include<iostream>

using namespace std;
//Refinement Level 0
/*
struct Light
{
    bool activated;
    int brightness;

};


int main()
{
    Light l;

    l.activated = true;
    l.brightness = 5;

    if(l.activated == true)
        cout<<"Light is active"<<endl;
    else
        cout<<"Light is not active"<<endl;

    if(l.activated)
        cout<<"The brightness level is "<<l.brightness<<endl;
    return 0;
}
*/

//Refinement Level 1
/*
struct Light
{
    bool activated;
    int brightness;

    Light()
    {
        activated = false;
        brightness = 0;
    }
};


int main()
{
    Light l;

    if(l.activated == true)
        cout<<"Light is active"<<endl;
    else
        cout<<"Light is not active"<<endl;

    if(l.activated)
        cout<<"The brightness level is "<<l.brightness<<endl;
    return 0;
}
*/

//Refinement Level 2
/*
struct Light
{
    bool activated;
    int brightness;

    Light()
    {
        activated = false;
        brightness = 0;
    }

    Light(bool active, int bright)
    {
        activated = active;
        brightness = bright;
    }
};


int main()
{
    Light l(true, 8); //Brightness level????

    if(l.activated == true)
        cout<<"Light is active"<<endl;
    else
        cout<<"Light is not active"<<endl;

    if(l.activated)
        cout<<"The brightness level is "<<l.brightness<<endl;
    return 0;
}
*/

//Refinement Level 3
/*
struct Light
{
    bool activated;
    int brightness;

    Light()
    {
        activated = false;
        brightness = 0;
    }

    Light(bool active, int bright)
    {
        activated = active;
        if(active == true)
            if(bright>0 && bright<=10)
                brightness = bright;
            else
                brightness = 1;
    }
};


int main()
{
    Light l(true, 15);

    if(l.activated == true)
        cout<<"Light is active"<<endl;
    else
        cout<<"Light is not active"<<endl;

    if(l.activated)
        cout<<"The brightness level is "<<l.brightness<<endl;
    return 0;
}
*/

//Refinement Level 4
/*
struct Light
{
    bool activated;
    int brightness;

    Light()
    {
        activated = false;
        brightness = 0;
    }

    Light(bool active, int bright)
    {
        activated = active;
        if(active == true)
            if(bright>0 && bright<=10)
                brightness = bright;
            else
                brightness = 1;
    }

    void Brighten()
    {
        brightness++;
    }

    void Dim()
    {
        brightness--;
    }
};


int main()
{
    Light l(true, 15);
    l.Brighten();   //how can we make this better????

    if(l.activated == true)
        cout<<"Light is active"<<endl;
    else
        cout<<"Light is not active"<<endl;

    if(l.activated)
        cout<<"The brightness level is "<<l.brightness<<endl;
    return 0;
}
*/

//Refinement Level 5
/*
struct Light
{
    bool activated;
    int brightness;

    Light()
    {
        activated = false;
        brightness = 0;
    }

    Light(bool active, int bright)
    {
        activated = active;
        if(active == true)
            if(bright>0 && bright<=10)
                brightness = bright;
            else
                brightness = 1;
    }

    void Brighten()
    {
        if(activated)
            if(brightness<10)
                brightness++;
    }

    void Dim()
    {
        if(activated)
            if(brightness>1)
                brightness--;
    }

    void ShowStatus()
    {
        if(activated == true)
        {
            cout<<"Light is active"<<endl;
            cout<<"The brightness level is "<<brightness<<endl;
        }
        else
            cout<<"Light is not active"<<endl;
    }
};


int main()
{
    Light l(true, 7);
    l.Brighten();
    l.Brighten();
    l.Dim();
    l.ShowStatus();
    return 0;
}
*/

//Refinement Level 6
/*
struct Light
{
    bool activated;
    int brightness;

    Light();
    Light(bool active, int bright);
    void Brighten();
    void Dim();
    void ShowStatus();
};


int main()
{
    Light l(true, 7);
    l.Brighten();
    l.Brighten();
    l.Dim();
    l.ShowStatus();
    return 0;
}

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
        cout<<"Light is active"<<endl;
        cout<<"The brightness level is "<<brightness<<endl;
    }
    else
        cout<<"Light is not active"<<endl;
}
*/

//Refinement Level 7

#include"Light.h"

int main()
{
    Light l(true, 7);
    l.Brighten();
    l.Brighten();
    l.Dim();
    //l.brightness = 90;
    l.ShowStatus();
    return 0;
}

