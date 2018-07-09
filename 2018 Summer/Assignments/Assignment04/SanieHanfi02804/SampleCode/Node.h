#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
#include "Shape.h"

struct node
{
    Rect* data;  //pointer data defined of type Rect. It is a pointer in the node.
    node* next;  //a pointer of type node is defined, pointer is basically used so that it can point towards the next or previous node.
    ~node() //destructor;
    {
        delete data; //memory deallocated
        cout<<"node deallocated"<<endl;
    }
};


#endif // NODE_H_INCLUDED
