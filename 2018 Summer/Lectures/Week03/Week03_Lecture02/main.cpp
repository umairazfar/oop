#include <iostream>
#include"Queue.h"

using namespace std;

int main()
{
    Queue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(15);
    q.Enqueue(20);
    q.Enqueue(25);
    int val = q.Dequeue();
    cout<<"Returned value is = "<<val<<endl;
    val = q.Dequeue();
    cout<<"Returned value is = "<<val<<endl;
    val = q.Dequeue();
    cout<<"Returned value is = "<<val<<endl;
    q.Print();
    return 0;
}
