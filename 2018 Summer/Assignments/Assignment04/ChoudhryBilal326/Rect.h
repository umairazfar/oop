#pragma once
#include"SDL.h"
#include"Point.h"

/** Rect class **/

class Rect
{
public:
    SDL_Rect* fillRect;
    Rect(SDL_Rect*);
    //Rect(const Point& topLeft, const Point& bottomRight, const Color&);
    void Draw(SDL_Renderer*, SDL_Rect*);
private:
    //Color color;
    Point topLeft;
    Point bottomRight;
};

