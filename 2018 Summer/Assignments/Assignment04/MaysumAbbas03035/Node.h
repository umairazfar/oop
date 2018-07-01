#include"Rect.h"
#pragma once

//   Creating a NODE Structure
struct Node
{
public:
    Rect* data;//Pointer of type Rect
    Node* next;//Pointer of the type Node
    Node();
    ~Node();
};
