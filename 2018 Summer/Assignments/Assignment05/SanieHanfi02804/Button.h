#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include "Words.h"
using namespace std;
class Button
{
private:
    Point position;
    int width;
    int height;
    SDL_Rect spriteClips[3];   //character array defined before.
    LTexture* spriteSheetTexture;
    Words* wordpointer;
public:
    Button();
    Button(LTexture* image, float x, float y, string button);
    ~Button();
    void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, string button);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();
};

