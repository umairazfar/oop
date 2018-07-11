#pragma once
#include "SDL.h"
#include "Point.h"

/** Rect class **/
//Rect class prototype
class Rect
{
private:
    SDL_Rect fillRect;  //Object of type SDL_Rect is created, fillRect is a rectangle
    Point topLeft;  //Variable of type Point is created, has an x and y coordinate pair initially assigned with the value 0 respectively
    Point bottomRight;  //Variable of type Point is created, has an x and y coordinate pair initially assigned with the value 0 respectively
public:
    Rect()  //Default constructor with no coding
    {

    }
    Rect(SDL_Rect);
    void Draw(SDL_Renderer*, SDL_Rect*);
};


