#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include "string.h"
#include "Character.h"
using namespace std;
class Words
{
private:
    Character* Char;
    LTexture* spriteSheetTexture;
    int width;
    int height;
    int length;
public:
    Words();
    Words(LTexture* image, float x, float y, string word);
    ~Words();
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
};
