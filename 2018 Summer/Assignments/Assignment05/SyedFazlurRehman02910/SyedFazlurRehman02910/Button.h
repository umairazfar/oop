#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include <iostream>
#include "LTexture.h"
#include "Point.h"
#include "Word.h"

using namespace std;

class Button
{
public:
    Button();
    virtual ~Button();
    Button(LTexture* image, float x, float y, string characters);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();

private:
    Point position;
    Word* words;
    int width;
    int height;
    SDL_Rect spriteClipsRight;      // spriteClips for different portions of the button
    SDL_Rect spriteClipsLeft;
    SDL_Rect spriteClipsMiddle;
    LTexture* spriteSheetTexture;
};


