#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>

struct node {
    int val;
    node* next;
    node(){val=0;next=NULL;}
};


#endif // NODE_H_INCLUDED
