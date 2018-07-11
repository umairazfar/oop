#include "Word.h"
#include <string>

using namespace std;

Word::Word()  //Default constructor used for initialization of a string and an integer
{
    statement = " ";
    stringLength = 0;
}

Word::Word(string line, float xPosition, float yPosition, LTexture* image)  //Overloaded constructor, statement is provided with a word string through line that is to be rendered at the center of the screen
{
    position.x = xPosition;  //For centering
    position.y = yPosition;  //For centering
    statement = line;
    stringLength = statement.size();  //Gets the length of string
    Char = new Character [stringLength];   //Dynamic array created and the address of its first index is passed to a character pointer, since the size of the word is determined at run time, a dynamic array is created

    for (int a = 0; a < stringLength; a++)  //Runs for the length of the word
    {
        Char[a] = Character(image,((a * 44) + (position.x - (stringLength /2 ) * 44)), position.y, statement[a]);  //For each index in the array, a character at the same index of the string is created at the center of the screen, then shifted to the left if there are more characters,
                                                                                                                   //such that half of the word appears on one side of the screen, and the other half at another
    }
}

void Word::DisplayString(long int& frame, SDL_Renderer* gRenderer, bool debug)  //Displays the passed word at the center of the screen
{
    for (int j = 0; j < stringLength; j++)  //Runs for the length of the word passed
    {
        Char[j].Render(frame, gRenderer, debug);  //Character render function is called for each character in the array
    }
}

Word::~Word()
{
    delete [] Char;  //Frees the memory
    Char = NULL;     //Points nowhere, memory inaccessible
}
