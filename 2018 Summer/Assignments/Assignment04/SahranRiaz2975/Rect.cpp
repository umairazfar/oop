#include "Rect.h"


Rect::Rect(SDL_Rect rect)  //Assigns an argument of type SDL_Rect - a Rectangle to fillRect
{
    this -> fillRect = rect;
}

/** Draws the rectangle **/
void Rect::Draw(SDL_Renderer* gRenderer, SDL_Rect* fillRect)
{
    SDL_RenderFillRect(gRenderer, &(this->fillRect));
}


