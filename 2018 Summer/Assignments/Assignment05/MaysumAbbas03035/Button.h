#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include"Character.h"
#include"Word.h"

using namespace std;

class Button
{
private:
    Point position;
    int character_value;
    int width;
    int height;
    LTexture* spriteSheetTexture;
    Word* wordPointer;

    SDL_Rect spritClipsLeft;
    SDL_Rect spritClipsMiddle;
    SDL_Rect spritClipsRight;


public:
    Button();
    Button(LTexture* image, float x, float y, string);
    ~Button();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, string);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();
};


