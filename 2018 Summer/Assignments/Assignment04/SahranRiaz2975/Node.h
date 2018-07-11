#pragma once
#include "Rect.h"

//node structure prototype
struct node
{
    Rect Rectangle;  //An object of type rectangle is created
    node* next;  // A pointer of type node is created
    node();      //node default constructor
};


