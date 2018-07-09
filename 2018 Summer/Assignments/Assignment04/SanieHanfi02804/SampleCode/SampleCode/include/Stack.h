#pragma once
#include"Node.h"
#include"Rect.h"

class Stack
{
private:
    Node* head;
public:
    Stack();
    ~Stack();
    void Push(Rect*);
    int Pop();
    void Show();
};
