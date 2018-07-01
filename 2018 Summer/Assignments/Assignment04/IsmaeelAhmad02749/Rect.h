#pragma once
#include"SDL.h"
#include"Point.h"

/** Rect class **/

class Rect
{
private:

    //Color color;
    Point topLeft;
    Point bottomRight;
public:
    Rect(SDL_Rect*);
    //Rect(const Point& topLeft, const Point& bottomRight, const Color&);
    void Draw(SDL_Renderer*, SDL_Rect*);
    SDL_Rect* fillRect;
};

