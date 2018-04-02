#ifndef LIST_T_H_INCLUDED
#define LIST_T_H_INCLUDED

#include <iostream>
#include "node_T.h"
using namespace std;

template <typename T>
class mylist{
public:

    mylist(){start=NULL;}

    ~mylist (){
        while(start){
        node<T>* tmp = start;
        start=start->next;
        delete tmp;
        }
    }
    void append(T a);
    int  length() const;// const{node<T>* s = start; int n=0; while(s){s=s->next;n++;}return n;}
    //void remove_at(int);

    friend ostream& operator<< (ostream&a, mylist<T> const & l){
        int len = l.length();
        node<T>* t = l.start;
        a<<"[";
        for (int i=0; i<len; i++){
            a<<t->val;
            if(i<len-1) a<<",";

            t=t->next;
        }
        a<<"]";

        return a;
    }

private:
    node <T>* start;
};


template<typename T>
void mylist<T>::append(T a){
    node<T> *t = new node<T>;
    t->val =a;
    t->next = start;
    start = t;
}

template<typename T>
int  mylist<T>::length() const{
    node<T>* s = start;
    int n=0;
    while(s){s=s->next;n++;}
    return n;
}

#endif // LIST_T_H_INCLUDED
