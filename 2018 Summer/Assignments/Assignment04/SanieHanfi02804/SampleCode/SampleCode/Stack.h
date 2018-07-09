#pragma once
#include"Node.h"
#include"Rect.h"
#include<iostream>
using namespace std;
class Stack
{
private:
    Node* head;
public:
    Stack();
    ~Stack();
    void Push(Rect*);
    Rect* Pop();
    void Show(SDL_Renderer*);
    void Show()
    {
        if (head == NULL)
        {
            cout<<"dsfsdf"<<endl;
        }
        Node* temp = head;
        while(temp!=NULL)
        {
            //temp->data->Draw(gRenderer, temp->data->GetFillRect());
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
};

