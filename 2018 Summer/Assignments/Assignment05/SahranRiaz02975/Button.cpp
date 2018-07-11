#include "Button.h"
#include <iostream>
#include <string>

using namespace std;

Button::Button()  //Default constructor used to initialize the width and height of the button and the length of the passed word
{
    //Width and height of a button are fixed to 64 * 64
    width = 64;
    height = 64;
    lengthOfString = 0;
}

Button::Button(string sentenceToDisplay, LTexture* pic, float halfScreenWidth, float halfScreenHeight)
{
    spritePaperTexture = pic;  //Stores the address of an Ltexture object
    lengthOfString = sentenceToDisplay.size();  //Stores the size of the passed word
    sentence = new Word(sentenceToDisplay, halfScreenWidth, halfScreenHeight, spritePaperTexture); //Using the character class, a word is created at the center of the screen dynamically, and assigned to a pointer of type word
    //Used for positioning on to the screen
    location.x = halfScreenWidth;
    location.y = halfScreenHeight;
}

void Button::DisplayButton(long int& frame, SDL_Renderer* gRenderer, bool debug)  //Used to render the button at the center of the screen, button is displayed in three parts, the center part expands according to the length of the word that has to be rendered on it
{
    for (int z = 0; z < lengthOfString; z++)  //Loop is used to expand the center part of the button according to the length of the word
    {
        spritePics.x = 10;
        spritePics.y = 432;
        spritePics.w = 64;
        spritePics.h = 64;

        this -> width = spritePics.w;
        this -> height = spritePics.h;

        spritePaperTexture -> Render(((z * 64) + (location.x - (lengthOfString / 2) * 64)), location.y - height / 2, &spritePics, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

        if (debug == true)
        {
            SDL_Rect rect = {((z * 64) + (location.x - (lengthOfString / 2 ) * 64)), location.y - height / 2, width, height };
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
            SDL_RenderDrawRect(gRenderer, &rect);
        }
    }
    //Last part of the button is rendered after the last character of the word
    spritePics.x = 90;
    spritePics.y = 432;
    spritePics.w = 64;
    spritePics.h = 64;

    this -> width = spritePics.w;
    this -> height = spritePics.h;

    spritePaperTexture -> Render(location.x + ((lengthOfString - 1) * 64 / 2), location.y - height / 2, &spritePics, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

    if (debug == true)
    {
        SDL_Rect rect = {location.x + ((lengthOfString - 1) * 64 / 2), location.y - height / 2, width, height};
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderDrawRect(gRenderer, &rect);
    }
//First part of the button is rendered before the first character of the word
    spritePics.x = 0;
    spritePics.y = 432;
    spritePics.w = 64;
    spritePics.h = 64;

    this -> width = spritePics.w;
    this -> height = spritePics.h;

    spritePaperTexture -> Render(location.x - ((lengthOfString + 1) * 64 / 2), location.y - height / 2, &spritePics, 0.0, NULL, SDL_FLIP_NONE, gRenderer);

    if (debug == true)
    {
        SDL_Rect rect = {location.x - ((lengthOfString + 1) * 64 / 2), location.y - height / 2, width, height};
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );
        SDL_RenderDrawRect(gRenderer, &rect);
    }

    //Word is rendered on to the screen after the button has been rendered
    sentence -> DisplayString(frame, gRenderer, debug);
}

Button::~Button()  //Destructor
{
    delete sentence;  //Deallocates the memory
    sentence = NULL;  //Memory is no longer accessible
}
