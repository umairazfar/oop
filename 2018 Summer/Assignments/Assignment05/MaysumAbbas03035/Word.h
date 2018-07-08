#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include"Character.h"

using namespace std;

class Word
{
private:
    Point position;
    int character_value;
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
    Character* dynArray;
    int length;
public:
    Word();
    Word(LTexture* image, float x, float y, string);
    ~Word();
    void getCharacter(int a,int b,int c, int d);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug, string);
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();
};

