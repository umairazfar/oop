#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"

class Character
{
private:                       //attributes assigned below.
    Point position;
    int character_value;
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
public:
    Character();
    Character(LTexture* image, float x, float y, char character); //overloaded constructor takes character in the argument as well.
    ~Character();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();
};

