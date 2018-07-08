#include "Word.h"
#include <iostream>
#include "Character.h"

#include <string>
using namespace std;


Word::Word()
{
    word_size = 0;
    //ctor
}

Word::Word(LTexture* image, float x, float y, string str)
{
    word_size = str.size();
    char_ptr = new Character[word_size];
    int my_position = word_size*0.5;

    for (int i=0;i<word_size;i++)
    {
        char_ptr[i] = Character(image, x-(my_position*44), y, str[i]);
        my_position--;
    }
}
Word::~Word()
{
    delete [] char_ptr;
    //dtor
}

void Word::Render(long int& frame, SDL_Renderer* gRenderer, bool debug)
{
    for (int i=0;i<word_size;i++)
    {
        char_ptr[i].Render(frame, gRenderer, false);
    }
}

