#include"Rect.h"

Rect::Rect(SDL_Rect rect)
{
    this->fillRect = rect; //the object rect is passed into fillRect.
}


/** Draws the rectangle **/
void Rect::Draw(SDL_Renderer* gRenderer)
{
    SDL_RenderFillRect( gRenderer, &(this->fillRect) ); //fillRect contains an object, gRenderer helps to paste the object on the screen.
}

