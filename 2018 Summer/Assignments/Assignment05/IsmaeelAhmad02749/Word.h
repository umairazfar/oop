#ifndef WORD_H
#define WORD_H

#include<iostream>
#include "Character.h"
#include<string.h>
using namespace std;

class Word
{
    public:
        Word();
        ~Word();
        Word(LTexture* image, float x, float y, string);
        void Render(long int& frame, SDL_Renderer* gRenderer, bool debug);
    private:
        int word_size;
        Character* char_ptr;
};

#endif // WORD_H
