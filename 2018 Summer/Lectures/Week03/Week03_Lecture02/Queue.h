#pragma once

struct Node
{
    int data;
    Node* next;
};

class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();
    void Enqueue(int);
    int RemoveAt(int);
    int Dequeue();
    void Print();
};
