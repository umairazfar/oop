#include"Rect.h"

Rect::Rect(SDL_Rect* rect)
{
    this->fillRect = new SDL_Rect;//using fillRect to draw the rectangles
    this->fillRect->x = rect->x;//x coordinate
    this->fillRect->y = rect->y;//y coordinate
    this->fillRect->w = rect->w;//with
    this->fillRect->h = rect->h;//height
}


/** Draws the rectangle **/
void Rect::Draw(SDL_Renderer* gRenderer, SDL_Rect* fillRect)
{
    SDL_RenderFillRect( gRenderer, fillRect );
}

