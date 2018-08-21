#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"Unit.h"

class Turret:public Unit
{
public:
    ~Turret();
    Turret(SDL_Texture* image, int x, int y);
};
