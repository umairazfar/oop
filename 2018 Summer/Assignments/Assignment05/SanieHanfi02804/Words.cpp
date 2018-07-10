#include"Words.h"
#include<iostream>
using namespace std;
Words::Words()
{
    width = 44;
    height = 48;
}

Words::~Words()
{
//
}

Words::Words(LTexture* image, float x, float y, string word)
{
    //int length = 0;
    spriteSheetTexture = image;
    length = word.size();   //string size calculated.
    Char = new Character[length]; //pointer assigned to the dynamic array of characters.
    int position = 0;
    position = length * 0.5;   //so that word could be printed in the middle of the screen.
    for (int i = 0; i < length; i++)   //loop was runned so that all the character obtained can be put into the array.
    {
        Char[i] = Character(image, x-(position * 40)+(i * 40),y, word[i]);

    }
}

void Words::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    for(int i =0; i < length; i++) //loop was runned so that each character could be rendered onto the screen.
    {
        Char[i].Render(frame,gRenderer,debug); //each character was rendered.
    }

}
