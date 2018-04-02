#include <iostream>

#include <typeinfo>
#include "include/list_T.h"


using namespace std;


template <typename mytype>
int find_occurrences(mytype a[], int size, mytype element)
{

    if(typeid(mytype)==typeid(int))
        cout<<"sepcial code for int"<<endl;

    int num=0;
    for(int i=0; i<size; i++)
        if(a[i]==element)
            num++;

    return num;
}

/*
* Task1: a. Understand the code in list_T.h and node_T.h
*        b. In main(), use generate different types of list and display them
*        c. Add a remove() function to the list, which when passed an argument,
            searches for it in the list and if found  removes it from the list.
*/

/*
* Task2: a. Implement the Course------Student association relationship from
            the last lab using linked list.
*/
int main()
{
	int a[6] = {2,3,3,1,5,6};
	cout<<find_occurrences(a,6,3)<<endl;
	double b[6] = {3.4,4.5,3.4,2.3,3.4,2.0};
    cout<<find_occurrences(b,6,3.4)<<endl;


    mylist<int> li;
    for(int i=0; i< 10; i++)
        li.append(i);

    cout<<li;


    return 0;
}
