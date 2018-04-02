#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "node.h"

class mylist{
public:

    mylist(){start=NULL; size=0;}
    void append(int);
    void insert(int, int);
    void print();
    int  length();
    void remove_at(int);
    int get_value_index(int);
    int get_value_at(int);

private:
    node* start;
    int     size;
};
#endif // LIST_H_INCLUDED
