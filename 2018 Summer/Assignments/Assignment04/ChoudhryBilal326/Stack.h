#pragma once
#include"Node.h"

class Stack
{
public:
    Stack();
    ~Stack();
    void Push(Rect*);
    Rect* Pop();
    void Show(SDL_Renderer*);//image processed and shown on screen
    bool ShowStack();
    void DeleteStack();
private:
    Node* head;
};
