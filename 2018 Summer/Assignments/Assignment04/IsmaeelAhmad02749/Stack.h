#ifndef STACK_H
#define STACK_H
#include"SDL.h"
#include "Rect.h"

/** stack class **/
struct Node
{
    Rect* rect_node;
    Node* next;
};

class Stack
{
    public:
        Stack();
        virtual ~Stack();

        void Push(Rect* );
        Rect* Pop();
        void Show(SDL_Renderer*);
        //void removethis(int position);
        //void showthis();

    private:
         Node* head;
         int count;
};

#endif // STACK_H

