#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"

class Character
{
private:
    Point position;
    int character_value;
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
public:
    Character();
    Character(LTexture* image, float x, float y);
    ~Character();
    virtual void Render(int,int,int,long int& frame, SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(int, int);
    void Redefine(LTexture*,float,float);
    int GetFrameWidth();
    int GetFrameHeight();
};

