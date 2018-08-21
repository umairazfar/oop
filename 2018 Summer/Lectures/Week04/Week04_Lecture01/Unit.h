#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>


using namespace std;

enum DIRECTION{UP,DOWN,LEFT,RIGHT};

class Unit
{
    protected:
        SDL_Rect srcRect;
        SDL_Rect mover;
        SDL_Texture* image;
        float x;
        float y;
    public:
        Unit(SDL_Texture* bodyImg, SDL_Texture* turretImg, int x, int y);
        Unit(SDL_Texture* texture, int x, int y);
        Unit();
        virtual ~Unit();
        virtual void Move(int direction);
        virtual void Draw(SDL_Renderer*);
};



