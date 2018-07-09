#include"Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    head = NULL;
}

Stack::~Stack()
{
    head = NULL;
}

void Stack::Push(Rect* val)
{
//    if (head == NULL)
//    {
////        cout<<<al<endl;
//        head = new Node;
//        head->data = val;
//        head->next = NULL;
//    }
//    else
//    {
//        //cout<<"push: "<<val<<endl;
//        Node* temp = head;
//        head = new Node;
//        head->data = val;
//        head->next = temp;
//
//    }

if (head == NULL)
    {
        head = new Node;
        head->data = val;
        head->next = NULL;
    }
    else
    {
        Node* temp = head;
        head = new Node;
        head->data = val;
        head->next = temp;
    }
    cout<<"Pushing "<< val << endl;
}

Rect* Stack::Pop()
{
    Rect* val;
    if(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        val = temp->data;
        //delete temp;
        temp = NULL;
    }
    cout<<"Popping "<< val << endl;
    return val;

}

void Stack::Show(SDL_Renderer* gRenderer)
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->data->Draw(gRenderer, temp->data->GetFillRect());
        //std::cout<<temp->data;
        temp = temp->next;
    }
}




