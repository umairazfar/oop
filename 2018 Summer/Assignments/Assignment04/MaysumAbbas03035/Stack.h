#pragma once
#include "Node.h"
#include"Rect.h"

// Creating a class STACK
class Stack
{
private:

public:
    Node* head;
    Stack();                    //Constructor
    ~Stack();                   //Destructor
    void Push(Rect*);           // to insert an element
    Rect* Pop();                // to delete an element
    void Show(SDL_Renderer*);   // to show the stack
    void deleteStk();           // to empty and delete stack
};
