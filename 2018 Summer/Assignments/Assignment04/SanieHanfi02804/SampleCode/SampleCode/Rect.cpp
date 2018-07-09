#include"Rect.h"

Rect::Rect(SDL_Rect* rect)
{
    this->fillRect = new SDL_Rect;
    this->fillRect->x = rect->x;
    this->fillRect->y = rect->y;
    this->fillRect->w = rect->w;
    this->fillRect->h = rect->h;
//
//    this->fillRect = rect;
}


/** Draws the rectangle **/
void Rect::Draw(SDL_Renderer* gRenderer, SDL_Rect*)
{
    SDL_RenderFillRect( gRenderer, fillRect );
}

SDL_Rect* Rect::GetFillRect()
{
    return fillRect;
}

