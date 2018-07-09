#include <iostream>
#include <stdlib.h>
#include "list.h"
#include "Shape.h"
#include "SDL.h"
using namespace std;

#include <iostream>

void Stack::Push(Rect* value)  //push function takes a pointer of type Rect as an arguement, basically so that it can save the shape created in the main file.
{
    //push function basically does that the shape that is created it stores it in a stack.
    if(head == NULL)
    {
        head = new node;       //new node is created, the head points towards the new node.
        head->data = value;    //the value of the data is replaced with the address of the shape.
        head->next = NULL;
    }
    else
    {
        node* temp = head;  //a pointer is created which points towards the same node as head does.
        head = new node;
        head->data = value;    //the value of the data is replaced with the address of the shape.
        head->next = temp;    //the next now points towards the address stored in temp.
    }
    cout<<"Pushing "<< value << endl;
}

Rect* Stack::Pop()// return type is Rect*, because we have to return addresses of the rectangles.
{

    if( head != NULL)  //this condition is applied so that when there is no rectangle drawn and the undo button is pressed, the program doesnt crashes.
    {
        node* temp = head;  //creates a pointer and it points towards, where head is pointing.
        head = head->next; //head stores the address that is stored in next.
        temp->next = NULL;
        Rect* New = temp->data; //a new pointer is created which stores the address that is stored in temp data.
        cout << "popping" << New << endl; //temp is deleted, so that extra memory is not consumed.
        delete temp;
        return New; //returns the address.


    }


}
void Stack::print(SDL_Renderer* gRenderer)//The function prints all the rectangle stored in the node.
{
    node* temp = head;
    while(temp != NULL ) //loop continues until temp doesnt point to NULL.
    {
        temp->data->Draw(gRenderer);//draws the rectangle that is stored in data.
        temp = temp->next; //address of the next is passed to temp.
    }


}

void Stack::removeAll()//empties the list, when a new rectangle is drawn.
{
    node* temp = head;
    while(temp != NULL ) //loop continues until temp doesnt point to NULL.
    {
        node* prev = temp;
        temp = temp->next; //address of the next is passed to temp.
        delete prev; //deletes the addresses of the previous shapes.
    }
    delete temp; //temp is deleted so that it doesnt point to any address.
    head = NULL;



}
