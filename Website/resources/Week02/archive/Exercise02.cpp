#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void Calculator();
float add(float num1, float num2);
float sub(float num1, float num2);
float mul(float num1, float num2);
float div(float num1, float num2);


int main()
{
    Calculator();
    return 0;
}

void Calculator()
{
    float num1 = 0;
    float num2 = 0;
    float ans = 0;
    char choice = 'y';
    char operation = '\0';


    while(choice != 'n')
    {
        cout<<"\nEnter the first number: ";
        cin>>num1;

        cout<<"\nEnter the second number: ";
        cin>>num2;

        cout<<"\nChoose the operation you want to perform:\n +\n -\n *\n /\noperation:";
        cin>>operation;

        switch(operation)
        {
            case '+':
                ans = add(num1, num2);
                break;
            case '-':
                ans = sub(num1, num2);
                break;
            case '*':
                ans = mul(num1, num2);
                break;
            case '/':
                ans = div(num1, num2);
                break;
            default:
                cout<<"\nEnter correct operation!\n";
        }
        cout<<"\nAnswer is: "<<ans<<endl;
        cout<<"\nDo you want to perform another operation?\n";
        cin>>choice;
    }
}

float add(float n1, float n2)
{
    return (n1 + n2);
}

float sub(float n1, float n2)
{
    return (n1 - n2);
}

float mul(float n1, float n2)
{
    return (n1 * n2);
}

float div(float n1, float n2)
{
    return (n1 / n2);
}
