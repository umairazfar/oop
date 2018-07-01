#include"Rect.h"


Rect::Rect(SDL_Rect* rect)
{
    this->fillRect = new SDL_Rect(); //Creating a Rectangle
    this->fillRect->x = rect->x;
    this->fillRect->y = rect->y;
    this->fillRect->h = rect->h;
    this->fillRect->w = rect->w;
}

Rect::~Rect()
{
    delete fillRect; //Deallocating the Memory
    fillRect=NULL;   //Avoids possibility of dangling pointers
}

/** Draws the rectangle **/
void Rect::Draw(SDL_Renderer* gRenderer, SDL_Rect* fillRect)
{
    SDL_RenderFillRect( gRenderer, this->fillRect );
}

