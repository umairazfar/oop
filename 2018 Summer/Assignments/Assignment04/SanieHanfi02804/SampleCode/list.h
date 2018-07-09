#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include "Rect.h"
#include "node.h"
#include "SDL.h"
#include "Shape.h"
#include "Color.h"
class Stack
{
private:
    node* head;

public:
    Stack()   //constructor.
    {
        head = NULL;
    }

    ~Stack() //destructor
    {
        removeAll(); //removeAll deallocates all the memory.
    }
    void Push(Rect* value); //push function takes a pointer in an arguement.
    Rect* Pop(); //returns rectangle address.
    void print(SDL_Renderer* gRenderer);// the function prints the object on the screen.
    void removeAll(); //removes all the element from the stack.

};
#endif // LIST_H_INCLUDED


