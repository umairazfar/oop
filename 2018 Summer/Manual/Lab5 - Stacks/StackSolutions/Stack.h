#pragma once
#include"Node.h"

class Stack
{
private:
    Node* head;
public:
    Stack();
    ~Stack();
    void Push(int);
    int Pop();
    void Show();
    bool isEmpty();
    int Top();
    int Bottom();
};
