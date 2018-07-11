#include"Word.h"
#include<iostream>

Word::Word()
{

}

Word::Word(LTexture* image, float x, float y)
{
    ch.Redefine(image, x, y);
}

Word::~Word()
{

}

void Word::Render(string nameToDraw,long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    int seq = 0;
    for(string::iterator it=nameToDraw.begin(); it!=nameToDraw.end(); it++)
    {

        ch.Render(int(*it),seq,nameToDraw.length(),frame, gRenderer, false);
        seq++;
    }
}

