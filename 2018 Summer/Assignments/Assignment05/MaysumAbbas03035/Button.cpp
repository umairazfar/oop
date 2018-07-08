#include"Button.h"
#include<iostream>

Button::Button()
{
    width = 44;
    height = 64;
    character_value = 0;
}

Button::Button(LTexture* image, float x, float y, string strg)
{
    spriteSheetTexture = image;
    character_value = 0;

    spritClipsLeft.x=0;
    spritClipsLeft.y=445;
    spritClipsLeft.w=64;
    spritClipsLeft.h=64;

    spritClipsMiddle.x=48;
    spritClipsMiddle.y=445;
    spritClipsMiddle.w=44;
    spritClipsMiddle.h=64;

    spritClipsRight.x=130;
    spritClipsRight.y=445;
    spritClipsRight.w=52;
    spritClipsRight.h=64;

    wordPointer =new Word(image, x, y,strg);
    position.x = x;
    position.y = y;
    this->width = spritClipsLeft.w;
    this->height = spritClipsLeft.h;
}

Button::~Button()
{
    delete wordPointer; //deallocating Memory
    wordPointer=NULL;
}

void Button::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, string str1)
{
    int length = str1.length();
    int i = 0;
    spriteSheetTexture->Render( position.x-(length/2)*44 + i*44 - 18, position.y - height/2, &spritClipsLeft, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };

    }
    for(i=1; i < length; i++)
    {
        spriteSheetTexture->Render(position.x-(length/2)*44 + i*44, position.y - height/2, &spritClipsMiddle, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if(debug == true)
        {
            SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        }
    }
    spriteSheetTexture->Render( position.x-(length/2)*44 + i*44 -15, position.y - height/2, &spritClipsRight, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
    }
}

void Button::SetPosition(Point& position)
{
    this->position.x = position.x - width/2;
    this->position.y = position.y - height/2;
}

void Button::SetPosition(int x, int y)
{
    this->position.x = x - width/2;
    this->position.y = y - height/2;
}

int Button::GetFrameWidth()
{
    return width;
}
int Button::GetFrameHeight()
{
    return height;
}
