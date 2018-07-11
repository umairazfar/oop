#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Point.h"

//Character structure prototype

class Character
{
private:
    //Ascii values of the special characters is being loaded into the following four arrays row wise as present in the sprite sheet
    int asciiSymbolsArrFRow [4] = {46, 44, 59, 58};
    int asciiSymbolsArrSRow [11] = {63, 33, 45, 95, 126, 35, 34, 39, 38, 40, 41};
    int asciiSymbolsArrThRow [11] = {91, 93, 124, 96, 92, 47, 64, 248, 43, 61, 42};
    int asciiSymbolsArrFouRow [5] = {36, 156, 128, 60, 62};
    Point position;  //Point object position created to get the character rendered in the center of the screen
    int characterValue;  //Holds the ascii value of the passed character
    int width;  //Used for rectangle clipping
    int height; //Used for rectangle clipping
    SDL_Rect spriteClips;  //Object of class SDL_Rect used to clip parts of the sprite sheet
    LTexture* spriteSheetTexture;  //Points to an object of type LTexture
public:
    Character();  //Default constructor
    Character(LTexture* image, float x, float y, char);  //Overloaded constructor
    ~Character();  //Destructor
    virtual void Render(long int& frame, SDL_Renderer* gRenderer, bool debug); //Virtual used to avoid the confusion that for which object the render function needs to be called
    void SetPosition(Point&);
    void SetPosition(int, int);
    int GetFrameWidth();
    int GetFrameHeight();
};


