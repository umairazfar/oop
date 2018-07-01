#include "Stack.h"
#include"Rect.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    head = NULL;
}

Stack::~Stack()
{
    deleteStk();
    cout << "Destructor Called" << endl;
}

// PUSH Operation
void Stack::Push(Rect *pointr)
{
    Node* temp; //1.Pointer of Type Node is Initialized
    temp = new Node; //2.New Object of structure Node is created at random position in memory, address returned
    temp->data = pointr; //3.Assessing the Object where pointer is pointing, and assigning values to its data members
    temp->next = head; //4.Same as above, next always points to the last Node
    head = temp; //5.Value(address) stored in temp gets into head, head always points to the top Node
}

// Pop Operation
Rect* Stack::Pop()
{
    Node* temp;//1.Pointer of Type Node is Initialized
    if(head!=NULL)
    {
        temp = head;//2.address of top node is stored in temp
        head = head->next;//3.address of second top node is stored in head, which becomes top node
        delete temp; //deallocates memory
    }
    return temp->data;// Pointer of type Rect is returned

}

// Show stack
void Stack::Show(SDL_Renderer* gRenderer)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        temp->data->Draw(gRenderer,temp->data->fillRect); //For Drawing onto sdl platform
        temp = temp->next; //Making sure complete stack is traversed
    }
}
//Empty and Deletes Stack
void Stack::deleteStk()
{
    Node *current = head;
    Node *temp;
    while(current != NULL)//traverses each node in the list and temporarily put it to a temporary pointer
    {
        temp = current;
        current = current->next;
        delete temp; //deallocates the the memory space
        temp = NULL; //Avoids the possibility of dangling pointer
    }
    head = NULL;
}
