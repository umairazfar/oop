#include"Rect.h"

Rect::Rect(SDL_Rect* rect)
{
    this->fillRect = new SDL_Rect;
    this->fillRect->x = rect->x;
    this->fillRect->h = rect->h;
    this->fillRect->y = rect->y;
    this->fillRect->w = rect->w;

}


/** Draws the rectangle **/
void Rect::Draw(SDL_Renderer* gRenderer, SDL_Rect* fillRect)
{
    SDL_RenderFillRect( gRenderer, fillRect );
}

