#pragma once

#include "Character.h"
#include <string>
#include <iostream>

using namespace std;

//Class prototype below

class Word
{
private:
    string statement;  //Stores the passed string
    int stringLength;  //Stores the string length
    Character* Char;   //Pointer of type character, points to a dynamic array
    Point position;    //Object of class position
public:
    Word();  //Default constructor
    Word(string, float, float, LTexture* image);  //Parameterized constructor, half of the dimensions of the screen passed into it, along with an address of texture and the word string
    ~Word();  //Destructor
    void DisplayString(long int&, SDL_Renderer*, bool);  //Used to render the word at the center of the screen
} ;
