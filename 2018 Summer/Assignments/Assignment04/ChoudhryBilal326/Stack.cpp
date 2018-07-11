#include"Stack.h"
#include "Rect.h"
#include <iostream>

Stack::Stack()//constructor
{
    head = NULL;
}

Stack::~Stack()//destructor
{
    head = NULL;
}

void Stack::Push(Rect* val)
{
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
}

Rect* Stack::Pop()//poping function
{
    Rect* val = NULL;
    if(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        val = temp->data;
        delete temp;
        temp = NULL;
    }
    return val;
}

void Stack::Show(SDL_Renderer* gRenderer)//display on the screen using SDL renderer
{
    Node* temp = head;
    while(temp!=NULL)
    {
        temp->data->Draw(gRenderer, temp->data->fillRect);
        temp = temp->next;
    }
}

bool Stack::ShowStack()//returns the stack after checking if its not empty
{
    return(this->head != NULL);
}

void Stack::DeleteStack()//delete the stack
{
    Node* temporary = head;
    while(temporary != NULL)
    {
        delete temporary;
        temporary = temporary->next;
    }
    head = NULL;
}

