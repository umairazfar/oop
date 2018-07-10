#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include <iostream>
#include "LTexture.h"
#include "Point.h"
#include "Character.h"

using namespace std;
class Word
{
public:
    Word();
    virtual ~Word();
    Word(LTexture* image, float x, float y, string characters);
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    int GetStringLength();      // function to access private attribute
    int GetFrameWidth();
    int GetFrameHeight();

private:
    Character* charArray;   // pointer used for creating dynamic array of characters
    int stringLength;       // variable to store the length of the string
    string characters;      // characters passed in input as a string
    int width;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;



};

