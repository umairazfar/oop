#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Point.h"

class Character
{
public:
    Character();
    ~Character();
    Character(LTexture* image, float x, float y, char alphabet);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();

private:
    Point position;
    char alphabet;  // used for inputting a particular character
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
};
