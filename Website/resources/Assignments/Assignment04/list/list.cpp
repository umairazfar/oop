#include <iostream>
#include <stdlib.h>
#include "include/list.h"
using namespace std;

void mylist::append(int val){

    if (start==NULL)
    {
        node* p = new node;
        if(p==NULL){cerr<<"Unable to allocate memory"<<endl; exit(0);}

        p->val = val;
        start = p;
        size++;
    }
    else{
        //go to list's end
        node* s = start;
        while (s->next) s=s->next;

        node* p = new node;
        if(p==NULL){cerr<<"Unable to allocate memory"<<endl; exit(0);}

        p->val = val;
        s->next = p;
        size++;
    }
}



void mylist::print()
{
    node* s = start;
    cout<<"[";
    while(s){
        cout<<s->val<<",";
        s=s->next;
    }
    cout<<"]";
}


/*
We defined the insert operation to be strictly different from append
which means that insert won't be able to add to the end of the array.
Including this behaviour requires trivial change in code.
*/


void mylist::insert(int ind, int val){
    if(ind<0 || ind>=size)
        cerr<<"Invalid index passed  to insert()"<<endl;


    node* p = new node;
    if(p==NULL){cerr<<"Unable to allocate memory"<<endl; exit(0);}
    p->val = val;


    //By definition if we reach here, start!=NULL

    if(start->next==NULL)
    {
        node* tmp = start;
        start = p;
        start->next = tmp;
    }
    else{
        //now go to the appropriate location
        node* behind = start;
        node* ahead  = start->next;
        for (int i=1; i<ind; i++){
            behind = ahead;
            ahead  = ahead->next;
        }
        behind->next = p;
        p->next = ahead;
    }
    size++;
}


int mylist::length(){
    return size;
}

void mylist::remove_at(int ind){
        if(ind<0 || ind>=size){
            cerr<<"Invalid index passed  to remove_at()"<<endl;
            exit(-1);
        }

    node *behind = start;
    if(ind==0)
    {
        start = start->next;
        delete behind;
    }
    else{
        //now go to the appropriate location
        node* ahead  = behind->next;
        for (int i=1; i<ind; i++){
            behind = ahead;
            ahead  = ahead->next;
        }
        behind->next = ahead->next;
        delete ahead;
    }
    size--;
}

int mylist::get_value_index(int val){

    int index = -1;
    node *tmp = start;
    while(tmp){
        index++;
        if(tmp->val==val)
            break;
        tmp = tmp->next;
    }

    if(tmp) return index;
    else    return -1;
}

int mylist::get_value_at(int index){

    if(index<0 || index>=size){
            cerr<<"Invalid index passed  to get_value_at()"<<endl;
            exit(-1);
    }

    node *s = start;
    for (int i=0; i<index; i++)
        s= s->next;

    return s->val;
}
