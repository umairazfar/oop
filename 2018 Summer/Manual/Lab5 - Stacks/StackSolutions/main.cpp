#include <iostream>
#include"Stack.h"

using namespace std;

int main()
{
    Stack stk;
    stk.Push(6);
    stk.Push(7);
    cout<<stk.Pop()<<endl;
    cout<<stk.Pop()<<endl;
    cout<<stk.Pop()<<endl;

    //If we use a stack pointer, what are the problems we might encounter?
    return 0;
}
