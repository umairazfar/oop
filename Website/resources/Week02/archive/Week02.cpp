#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;

void SayHello(int);
void UnderstandingPointers();
void UnderstandingReferences();
void PassingValues(int, int*);
int SimpleSums(int, int);
void FindingSums(int&, int*, int*);
void DynamicMemory();
void StaticVariable();
void Arrays();
void SettingArray(int[]);
int* GettingArray();

int main()
{
    /*******************
    * Add your code here
    *******************/

    //SayHello(0);
    //UnderstandingPointers();
    //UnderstandingReferences();

    /*
    int val1 = 200;
    int val2 = 300;

    PassingValues(val1, &val2);

    cout<<"After passing values, val1 is: "<<val1<<endl;
    cout<<"After passing values, val2 is: "<<val2<<endl;

    int sum = 0;

    sum = SimpleSums(val1, val2);
    cout<<"Sum is: "<<sum<<endl;

    FindingSums(sum, &val1, &val2);

    cout<<"Sum is: "<<sum<<endl;
    */

    //DynamicMemory();
    //Arrays();
    //StaticVariable();
    //StaticVariable();

    /*******************
    * Add your code here
    *******************/
    return 0;
}

/**
Learning about function prototypes
**/
void SayHello(int val = 0)
{
    if(val == 0) cout<<"Hello!\n";
    else cout<<"Salam!\n";
}

/**
Learning about how pointers work
**/
void UnderstandingPointers()
{
    int val = 10;
    int* ptr_val = NULL;    //Pointer has been set to NULL, so it points nowhere

    cout<<val<<endl;
    cout<<ptr_val<<endl;

    ptr_val = &val;         //Giving the address of val to the pointer, that is the LVALUE

    cout<<val<<endl;        //Outputting the stored value
    cout<<ptr_val<<endl;    //Outputting the LVALUE of variable 'val'
    cout<<*ptr_val<<endl;   //Outputting the RVALUE of variable 'val'

    *ptr_val = 20;

    cout<<val<<endl;        //Outputting the stored value, which has changed now
    cout<<ptr_val<<endl;    //Outputting the LVALUE of variable 'val'
    cout<<*ptr_val<<endl;   //Outputting the RVALUE of variable 'val'
}

/**
*Learning about references
**/
void UnderstandingReferences()
{
    int val = 50;
    int& ref_val = val;

    ref_val = 100;

    cout<<val<<endl;
}
/**
*Passing values and changing them
**/
void PassingValues(int n1, int* n2)
{
    cout<<"The passed value of val1 is: "<<n1<<endl;
    cout<<"The passed value of val1 is: "<<*n2<<endl;
    n1 = 0;
    *n2 = 0;
    cout<<"The first changed value is: "<<n1<<endl;
    cout<<"The second changed value is: "<<*n2<<endl;
}

int SimpleSums(int a, int b)
{
    int sum = a + b;
    return sum;
}

void FindingSums(int& ref_sum, int* ptr1, int* ptr2)
{
    ref_sum = *ptr1 + *ptr2;
}

void DynamicMemory()
{
    int* ptra = NULL;
    int* ptrb = NULL;

    ptra = new int;
    ptrb = new int;

    *ptra = 10;
    *ptrb = 20;

    cout<<"Address of ptra is: "<<&ptra<<endl;
    cout<<"Address of ptrb is: "<<&ptrb<<endl;
    cout<<"Address stored in ptra is: "<<ptra<<endl;
    cout<<"Address stored in ptrb is: "<<ptrb<<endl;
    cout<<"Value pointed at by ptra is: "<<*ptra<<endl;
    cout<<"Value pointed at by ptrb is: "<<*ptra<<endl;

    cout<<"Sum is: "<<*ptra + *ptrb;

    cout<<"Deleting the pointers, which means, freeing the memory"<<endl;

    delete ptra;
    delete ptrb;

    cout<<"Address of ptra is: "<<&ptra<<endl;
    cout<<"Address of ptrb is: "<<&ptrb<<endl;
    cout<<"Address stored in ptra is: "<<ptra<<endl;
    cout<<"Address stored in ptrb is: "<<ptrb<<endl;
    cout<<"Value pointed at by ptra is: "<<*ptra<<endl;
    cout<<"Value pointed at by ptrb is: "<<*ptrb<<endl;

    cout<<"Setting pointers to NULL"<<endl;

    ptra = NULL;
    ptrb = NULL;

    cout<<"Address of ptra is: "<<&ptra<<endl;
    cout<<"Address of ptrb is: "<<&ptrb<<endl;
    cout<<"Address stored in ptra is: "<<ptra<<endl;
    cout<<"Address stored in ptrb is: "<<ptrb<<endl;
    //cout<<"Value pointed at by ptra is: "<<*ptra<<endl;   //Uncommenting these lines will cause the program to crash
    //cout<<"Value pointed at by ptrb is: "<<*ptrb<<endl;
}

void StaticVariable()
{
    static int called = 0;
    //cout<<"It has been called "<<++called<<" times."<<endl;
    cout<<"It has been called "<<called++<<" times."<<endl;
}

void Arrays()
{
    int intarray[3] = { 1, 5, 3};
    /*
    int intarray[3];
    intarray[0] = 1;
    intarray[1] = 5;
    intarray[2] = 3;
    */

    for (int i = 0; i<3; i++)
    {
        cout<<intarray[i]<<endl;
    }

    SettingArray(intarray);

    for (int i = 0; i<3; i++)
    {
        cout<<intarray[i]<<endl;
    }

    int* p = GettingArray();

    for (int i = 0; i<3; i++)
    {
        cout<<p[i]<<endl;
    }

    int length = 8;

    int* dyArray = new int[8];

    for (int i = 0; i<8; i++)
    {
        dyArray[i] = i;
        cout<<dyArray[i]<<endl;
    }
    delete[] dyArray;

    cout<<"\nSize of intarray is "<<sizeof(intarray);
    cout<<"\nSize of single element of intarray is "<<sizeof(intarray[0]);

}

void SettingArray(int passed[])
{
    for (int i = 0; i<3; i++)
    {
        passed[i] = 0;
        cout<<passed[i]<<endl;
    }
}

int* GettingArray()
{
    static int internal[3] = { 9, 9, 9};

    return internal;
}
