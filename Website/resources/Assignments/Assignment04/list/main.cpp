#include <iostream>
#include "include/list.h"

using namespace std;

int main()
{

    mylist l;
     l.print();
    for(int i=0;i<10;i++)
        l.append(i);

    l.insert(3,55);
    l.print();

    l.remove_at(30);
    l.print();

    int index = l.get_value_index(5);
    if (index < 0) cout<<"the value was not found in the list"<<endl;
    else cout<<"the index of value is "<<index<<endl;

    cout <<"the value at index 13 is "<<l.get_value_at(-30)<<endl;


    return 0;
}
