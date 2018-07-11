#include "Stack.h"
#include "Node.h"
#include <iostream>
#include "Rect.h"

using namespace std;

Stack::Stack()  //Default constructor, used to initialize the head pointer of type node to NULL
{
    head = NULL;
}

void Stack::Push(Rect pRect) //Push function, accepts an object, and pushes it into the stk stack, my main stack
{
    node* temp = new node;  //temp pointer of type node accepts the address of a new node, dynamic memory allocation
    temp -> Rectangle = pRect;  //Object of type rectangle is assigned with the object pRect which is also of a type rectangle
    temp -> next = head;  //next pointer of temp accepts the address of the head pointer and points at that address
    head = temp;  //head pointer stores the address of the temp pointer and points there
}

Rect Stack::Pop()  //When invoked, the node at the top of the stack gets removed and the stack is relinked, this function returns an object of type Rect
{
    Rect rec;  //An object of type Rect is created

    if (head != NULL)  //If the head pointer points to a node, then the following actions are taken
    {
        node* temp = head;  //Pointer of type node created to point at the head, the top of the stack
        head = head -> next;  //head is made to point at the address pointed to by its next pointer of type node
        rec =  temp -> Rectangle;  //The object pointed to by the temp pointer is assigned to rec, object of type Rect
        delete temp; //Deallocation of memory
    }

    else  //If head points to NULL, it means there are no nodes available in the stack
    {
        cout << "There are no rectangles in the stack" << endl;
        return rec;
    }

    return rec;
}

void Stack::Remove()  //This function clears the stack
{
    while(head != NULL)  //Runs until head points to NULL, it means that the stack is fully traversed
    {
        node* temp = head;  //Pointer of type node is being made to point where the head pointer of type node is pointing, at the top of the stack
        head = head -> next;  //head is made to point where its next pointer is pointing
        delete temp;  //temp that stores the address of head, initially is deleted to remove the top most node of the stack
        cout << "Rectangle has been removed from the backup stack" << endl;
    }
}

void Stack::Show(SDL_Renderer* gRenderer, SDL_Rect* fillRect)  //This function displays each rectangle in the stack, takes in the pointer of type SDL_Rect and SDL_Renderer as arguments
{
    node* temp = head;  //Pointer of type node is being made to point at the top of the stack
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF ); //Hexadecimal values can be manipulated to change the color of the displayed rectangle
    while (temp != NULL)  //Stack is traversed upon until temp points to NULL
    {
        temp -> Rectangle.Draw(gRenderer, fillRect);  //Since rectangle is an object of type Rect, . operator is used to call its draw function
        temp = temp -> next;  //At the end of each iteration, temp is used to point where the next pointer of temp is pointing at
    }
}

bool Stack::IsEmpty()  //This function returns either true or false depending on whether the stack has any nodes left or not.
{
    if (head == NULL)  //Returns true if head points to NULL
    {
        return true;
        cout << "Backup stack is empty" << endl;
    }

    else  //Returns false if head does not point to NULL, meaning there is at least one node present in the stack
    {
        return false;
        cout << "Backup stack is not empty" << endl;
    }
}
