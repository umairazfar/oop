#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "math.h"
#include "LTexture.h"
#include "Point.h"
#include "Word.h"
#include "Button.h"

using namespace std;
Button::Button()
{
    width = 64;     // Button Dimensions for single portion
    height = 64;
}

Button::~Button()
{
    delete words;
}

Button::Button(LTexture* image, float x, float y, string characters)
{
    spriteSheetTexture = image;
    words = new Word(image, x, y, characters);

    spriteClipsLeft.x = 0 * 64;     //clipping the left portion of the button
    spriteClipsLeft.y = 9 * 48;
    spriteClipsLeft.w = 64;
    spriteClipsLeft.h = 64;

    spriteClipsMiddle.x = 39;      //clipping the middle portion of the button
    spriteClipsMiddle.y = 9 * 48;
    spriteClipsMiddle.w = 64;
    spriteClipsMiddle.h = 64;

    spriteClipsRight.x = 90;    //clipping the right portion of the button
    spriteClipsRight.y = 9 * 48;
    spriteClipsRight.w = 64;
    spriteClipsRight.h = 64;

    position.x = x;
    position.y = y;

    this->width = spriteClipsLeft.w;    //dimensions of button  i. e. 64 x 64 remains same
    this->height = spriteClipsLeft.h;
}

void Button::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    int i = 0;
    spriteSheetTexture->Render ( position.x - float ((words->GetStringLength() / 1.75) * 64) +  i * 64, position.y - height / 2, &spriteClipsLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - int ((words->GetStringLength() / 1.75) * 64) + i * 64, position.y - height / 2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
        i++;
    }

    for ( ; i < words->GetStringLength(); i++)
    {
        spriteSheetTexture->Render ( position.x - float ((words->GetStringLength() / 2) * 64) + i * 64, position.y - height / 2, &spriteClipsMiddle, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if(debug == true)
        {
            SDL_Rect rect = { position.x - int ((words->GetStringLength() / 2) * 64) + i * 64, position.y - height / 2, width, height };
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
            SDL_RenderDrawRect( gRenderer, &rect );
        }
    }

    spriteSheetTexture->Render( position.x - float(words->GetStringLength() / 2) * 64  + i * 64, position.y - height / 2, &spriteClipsRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - int ((words->GetStringLength() / 2) * 64)  + i * 64, position.y - height / 2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

    words->Render(frame, gRenderer, debug);      // rendering word on the button
}

void Button::SetPosition(Point& position)
{
    this->position.x = position.x - width / 2;
    this->position.y = position.y - height / 2;
}

void Button::SetPosition(int x, int y)
{
    this->position.x = x - width / 2;
    this->position.y = y - height / 2;
}

int Button::GetFrameWidth()
{
    return width;
}

int Button::GetFrameHeight()
{
    return height;
}

