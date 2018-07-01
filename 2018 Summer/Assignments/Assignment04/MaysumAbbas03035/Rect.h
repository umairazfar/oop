#pragma once
#include"SDL.h"
#include"Point.h"
#include <iostream>
/** Rect class **/

class Rect
{
private:
    Point topLeft;
    Point bottomRight;
public:
    SDL_Rect* fillRect;
    Rect(SDL_Rect*);
    void Draw(SDL_Renderer*, SDL_Rect*);
    ~Rect();
};

