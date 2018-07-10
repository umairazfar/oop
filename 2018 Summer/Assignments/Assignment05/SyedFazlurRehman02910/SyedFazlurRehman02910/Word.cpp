#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "Word.h"

using namespace std;

Word::Word()
{
    stringLength = 0;
}

Word::~Word()
{
    delete[] charArray;
}

Word::Word(LTexture* image, float x, float y, string characters)
{
    stringLength = characters.length();
    charArray = new Character[stringLength];
    for (int i = 0; i < stringLength; i++)
    {
        charArray[i] = Character(image, x - (stringLength / 2) * 44 + i * 44, y, characters[i]);
    }
}

void Word::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    for (int i = 0; i < stringLength; i++)
    {
        charArray[i].Render(frame, gRenderer, false);
    }
}

int Word::GetStringLength()
{
    return stringLength;
}

int Word::GetFrameWidth()
{
    return width;
}

int Word::GetFrameHeight()
{
    return height;
}
