#ifndef BUTTON_H
#define BUTTON_H
#include"Word.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include"Point.h"
#include "Character.h"

class Button
{
private:

    Point position;
    int Button_value;
    int width;
    Character ch;
    Word wd;
    int height;
    SDL_Rect spriteClips;
    LTexture* spriteSheetTexture;
public:
    Button();
    Button(LTexture* image, float x, float y);
    ~Button();
    virtual void Render(string buttonToDraw, long int& frame, SDL_Renderer* gRenderer, bool debug);
};

#endif // BUTTON_H
