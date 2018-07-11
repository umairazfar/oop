#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include "Character.h"

using namespace std;
class Word
{
private:
    Point position;
    int Word_value;
    int width;
    Character ch;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
public:
    Word();
    Word(LTexture* image, float x, float y);
    ~Word();
    virtual void Render(string nameToDraw, long int& frame, SDL_Renderer* gRenderer, bool debug);
    getSize();
};

