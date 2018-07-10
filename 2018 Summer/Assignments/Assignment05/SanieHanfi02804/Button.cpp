#include <iostream>
#include "Button.h"

using namespace std;

Button::Button()
{
    width = 44;
    height = 48;
}
Button::Button(LTexture* image, float x, float y, string button)
{
    spriteSheetTexture = image;
    spriteClips[0].x = 0;           //this obtains the button image of the left side.
    spriteClips[0].y = 447;
    spriteClips[0].w = 66;
    spriteClips[0].h = 64;

    spriteClips[1].x = 64;             //this obtains the button image of the middle.
    spriteClips[1].y = 448;
    spriteClips[1].w = 64;
    spriteClips[1].h = 64;

    spriteClips[2].x = 124;                //this obtains the button image for the right side.
    spriteClips[2].y = 447;
    spriteClips[2].w = 42;
    spriteClips[2].h = 64;

    wordpointer = new Words(image, x,y, button);  //a pointer was created of type word, so that a string could be passed in the render function.

    position.x = x;
    position.y = y;

    this->width = spriteClips[0].w;
    this->height = spriteClips[0].h;






}
Button::~Button()
{

}
void Button::Render(long int& frame, SDL_Renderer* gRenderer, bool debug, string button)
{
    int i = 0;                  //the below part was adjusted so that the word could fit in the button. This was done for all three sprite clips.
    spriteSheetTexture->Render( position.x-((button.length()/2) * 94)+(i * 94), position.y - height/2, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x-((button.length()/2)* 34)+(i * 34), position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

    int Size = 0;    //a loop was run so that three clips of button can be pasted in the middle.
    Size = button.size();
    for(int i = 0; i < Size; i++)
    {
        spriteSheetTexture->Render( position.x-((button.length()/2) * 63)+(i * 63), position.y - height/2, &spriteClips[1], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if(debug == true)
        {
            SDL_Rect rect = { position.x-((button.length()/2)* 4)+(i * 24), position.y - height/2, width, height };
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
            SDL_RenderDrawRect( gRenderer, &rect );
        }

    }

    spriteSheetTexture->Render(position.x-((button.length()/2) * (-80))+(i * 0), position.y - height/2, &spriteClips[2], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    if(debug == true)
    {
        SDL_Rect rect = { position.x-((button.length()/2) * 4)+(i * 4), position.y - height/2, width, height };
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect( gRenderer, &rect );
    }

}

void Button::SetPosition(Point&)
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
