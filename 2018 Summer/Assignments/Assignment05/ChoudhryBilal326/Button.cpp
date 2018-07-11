#include "Button.h"
#include<iostream>

using namespace std;

Button::Button()
{
    width = 64;
    height = 64;
}

Button::Button(LTexture* image, float x, float y)
{

    spriteSheetTexture = image;

    //Frame 0
    spriteClips.x = 0;
    spriteClips.y = 432;
    spriteClips.w = 64;
    spriteClips.h = 64;

    //Frame 1
    spriteClips.x = 64;
    spriteClips.y = 432;
    spriteClips.w = 64;
    spriteClips.h = 64;

    //Frame 2
    spriteClips.x = 128;
    spriteClips.y = 432;
    spriteClips.w = 64;
    spriteClips.h = 64;

    position.x = x;
    position.y = y;

    this->width = spriteClips.w;
    this->height = spriteClips.h;
}

void Button::Render(string buttonToDraw,long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    int seq = 0;
    for(string::iterator it=buttonToDraw.begin(); it!=buttonToDraw.end(); it++)
    {
        ch.Render(int(*it),seq,buttonToDraw.length(),frame, gRenderer, false);
        seq++;
    }
}
