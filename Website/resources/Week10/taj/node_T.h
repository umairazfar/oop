#ifndef NODE_T_H_INCLUDED
#define NODE_T_H_INCLUDED

#include<iostream>
using namespace std;

template <typename T>
struct node {
    T val;
    node* next;
    node(){val=0;next=nullptr;}
};

template<typename T>
ostream& operator<<(ostream &a, node<T> n)
{
    a<<n.val;
    return a;
}

#endif // NODE_T_H_INCLUDED
