#include"Word.h"
#include<iostream>

Word::Word()
{
    width = 44;
    height = 48;
    character_value = 0;
}

Word::Word(LTexture* image, float x, float y, string strg)
{
    spriteSheetTexture = image;
    character_value = 0;
    position.x = x;
    position.y = y;
    this->width = spriteClips.w;
    this->height = spriteClips.h;
    length = strg.length();
    int halflength=length/2;

    dynArray = new Character[length];
    for ( int i = 0; i<length; i++)
    {
        int asCode=(int) strg[i];
        dynArray[i]= Character(image, x-(halflength*44) + i*44, y-20);
        dynArray[i].asciiToimage(asCode);
    }
}

Word::~Word()

{
    delete[] dynArray;//deallocating Memory
    dynArray=NULL;
}

void Word::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, string str1)
{
    int length = str1.length();
    for (int i=0;i< length;i++)
    {
        dynArray[i].Render(frame, gRenderer, false);
    }

    //spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &spriteClips, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x - width/2, position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }
}

void Word::SetPosition(Point& position)
{
    this->position.x = position.x - width/2;
    this->position.y = position.y - height/2;
}

void Word::SetPosition(int x, int y)
{
    this->position.x = x - width/2;
    this->position.y = y - height/2;
}

int Word::GetFrameWidth()
{
    return width;
}
int Word::GetFrameHeight()
{
    return height;
}

void Word::getCharacter(int a,int b,int c, int d)
{
    spriteClips.x = a;
    spriteClips.y = b;
    spriteClips.w = c;
    spriteClips.h = d;
}
