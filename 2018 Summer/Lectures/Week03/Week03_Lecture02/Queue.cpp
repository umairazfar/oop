#include"Queue.h"
#include<iostream>

using namespace std;

Queue::Queue()
{
    head = tail = NULL;
}
Queue::~Queue()
{
    while( head != NULL )
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout<<"\nNode deleted";
    }
}
void Queue::Enqueue(int data)
{
    if(head == NULL)
    {
        head = new Node;
        head->data = data;
        head->next = NULL;
        tail = head;
    }
    else
    {
        Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
    }
}
int Queue::Dequeue()
{
    int ret = 0;
    if(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        ret = temp->data;
        delete temp;
    }
    return ret;
}
void Queue::Print()
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int Queue::RemoveAt(int index)
{
    int val = 0;



    return val;
}
