#pragma once

#include "Word.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"
#include "Point.h"
#include <string>

using namespace std;

class Button
{
private:
    Point location;  //Object of the class point
    Word* sentence;  //Pointer of type word, points to a word
    SDL_Rect spritePics;  //Object of class SDL_Rect
    LTexture* spritePaperTexture;  //This pointer points to an LTexture object
    int width;  //Used for rectangle clipping
    int height; //Used for rectangle clipping
    int lengthOfString;  //Stores the length of the word passed into the constructor
public:
    Button();  //Default constructor
    Button(string, LTexture* image, float, float);  //Overloaded constructor, half of screen width and height are passed into it along with address of an LTexture object and a word string
    ~Button();  //Destructor
    void DisplayButton(long int& frame, SDL_Renderer* gRenderer, bool debug);  //To display the button, at the center of the screen, with the word at the center of the button

};

