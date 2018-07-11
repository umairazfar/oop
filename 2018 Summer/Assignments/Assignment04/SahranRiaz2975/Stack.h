#pragma once
#include "Node.h"
#include "Rect.h"

//Stack class prototype
class Stack
{
private:
    node* head;  //Pointer of type node is created which is used mainly to point at the top of a stack
public:
    Stack();
    void Push(Rect);
    void Remove();
    Rect Pop();
    bool IsEmpty();
    void Show(SDL_Renderer*, SDL_Rect*);
};
