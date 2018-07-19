#include"Stack.h"
#include <iostream>

Stack::Stack()
{
    head = NULL;
}

Stack::~Stack()
{
    head = NULL;
}

void Stack::Push(int val)
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

int Stack::Pop()
{
    int val = -1;
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

void Stack::Show()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        std::cout<<temp->data<<std::endl;
        temp = temp->next;
    }
}

bool Stack::isEmpty()
{
    bool checkIsEmpty = (head == NULL);
    return checkIsEmpty;
}

int Stack::Top()
{
    int topElement = head->data;
    return topElement;
}
int Stack::Bottom()
{
    int BottomElement;
    //Iterating till the last element
    Node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp->next;
    }

    BottomElement = temp -> data;
    return BottomElement;
}
