#include "Stack.h"
#include<iostream>>
#include "Rect.h"

using namespace std;

Stack::Stack()
{
    head = NULL;
    count = 0;
    //ctor
}

Stack::~Stack()
{
    head = NULL;
    count = 0;
    //dtor
}

void Stack::Push(Rect* rect_ptr)
{
    if (head == NULL)
    {
        head = new Node;
        head->rect_node = rect_ptr;
        head->next = NULL;
    }
    else
    {
        Node* temp = head;
        head = new Node;
        head->rect_node = rect_ptr;
        head->next = temp;
    }
}

Rect* Stack::Pop()
{
    Rect* val = NULL;
    if(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        val = temp->rect_node;
        delete temp;
        temp = NULL;
    }
    return val;
}

void Stack::Show(SDL_Renderer* gRenderer)
{
    Node* temp = head;

    while (temp != NULL)
    {
        temp->rect_node->Draw(gRenderer, temp->rect_node->fillRect);
        temp = temp->next;
    }

}
