/**
* OOP lecture 01. Programming Basics in C++
* Understanding Data Types and Functions
**/

#include<iostream> //Similar to import command in Python
#include<stdio.h>
#include<stdlib.h>//For random numbers
#include<time.h>//For generating a new random seed

using namespace std;    //required for using cin and cout commands

int DataTypes()
{

    int integer = 0;
    short s_integer = 0;
    long l_integer = 0;
    unsigned int u_integer = 0;

    /**Multiple ways of saying the same thing**/
    printf("The value of integer is: %i\n", integer);
    printf("The value of integer is: %d\n", integer);
    cout<<"The value of integer is: "<<integer<<"\n";
    cout<<"The value of integer is: "<<integer<<endl<<endl;

    integer = 64000;
    s_integer = 64000;
    l_integer = 64000;
    u_integer = 64000;

    printf("The value of integer is: %i\nThe value of short is: %i\nThe value of long is: %l\nThe value of unsigned integer is: %i\n", integer, s_integer, l_integer, u_integer);
    cout<<"The value of integer is: "<<integer<<endl<<"The value of short is: "<<s_integer<<endl<<"The value of long is: "<<l_integer<<endl<<"The value of unsigned integer is: "<<u_integer<<endl<<endl;

    integer = -64000;
    s_integer = -64000;
    l_integer = -64000;
    u_integer = -64000;

    printf("The value of integer is: %i\nThe value of short is: %i\nThe value of long is: %l\nThe value of unsigned integer is: %i\n", integer, s_integer, l_integer, u_integer);
    cout<<"The value of integer is: "<<integer<<endl<<"The value of short is: "<<s_integer<<endl<<"The value of long is: "<<l_integer<<endl<<"The value of unsigned integer is: "<<u_integer<<endl<<endl;

    float f_value = 64000.897f;
    double d_value = 64000.897;
    long double ld_value = 64000000.897;

    printf("The value of float is: %f\nThe value of double is: %e\n\n", f_value, d_value);

    return 0;

}


float Temperature(float fahrenheit) //Change return type to int and see what happens
{
    float celsius = (fahrenheit-32) * 5 / 9;
    return celsius;
}

int global = 5;

void VariableScope()
{
    global = global + 1;
    //int global = global + 1;
    cout<<"value of global is :"<<global;
}

void VariableScope(int global)
{
    global = global + 1;
    //int global = global + 1 //See the error and think how it can be fixed
    cout<<"\nvalue of global is :"<<global;
}
/*
//Uncomment it to learn about errors
void VariableScope(int global = 0)
{
    global = global + 1;
    //int global = global + 1;
    cout<<"\nvalue of global is :"<<global;
}
*/

void Conditionals()
{
    /* initialize random seed: */
    //srand (time(NULL));//see what effects it has after uncommenting it
    int random = rand() % 10;
    cout<<"\nGenerated random number is: "<<random<<endl;

    if (random <5)
    {
        cout<<"\nValue is less than 5"<<endl;
    }
    else
    {
        cout<<"\nValue is greater than or equal to 5"<<endl;
    }
}

void WhileLoop()
{
    char choice = 'y';
    int runs = 0;
    int totalRuns = 0;
    srand (time(NULL));

    while(choice != 'n' )
    {
        runs = rand() % 7;
        if (runs == 5)
        {
            runs = 0;
            cout<<"Out!"<<endl;
            cout<<"Total Runs Scored = "<<totalRuns<<endl;
            totalRuns = 0;
            cout<<"Do you want to try again?\nEnter 'y' for yes and 'n' for no\n";
            cin>>choice;
            if(choice == 'y')   //What happens if we put brackets or not. If not, only one statement is executed
                continue;       //Recommendation: Always put brackets
            else
            {
                break;
            }
        }
        else
        {
            cout<<"Runs scored = "<<runs<<endl;
            totalRuns = totalRuns + runs;
        }
    }
}

void DoWhileLoop()
{
    char choice = 'y';
    int runs = 0;
    int totalRuns = 0;
    srand (time(NULL));

    do
    {
        runs = rand() % 7;
        if (runs == 5)
        {
            runs = 0;
            cout<<"Out!"<<endl;
            cout<<"Total Runs Scored = "<<totalRuns<<endl;
            totalRuns = 0;
            cout<<"Do you want to try again?\nEnter 'y' for yes and 'n' for no\n";
            cin>>choice;
            if(choice == 'y')   //What happens if we put brackets or not. If not, only one statement is executed
                continue;       //Recommendation: Always put brackets
        }
        else
        {
            cout<<"Runs scored = "<<runs<<endl;
            totalRuns = totalRuns + runs;
        }
    }while(choice != 'n' );
}

void ForLoop()
{
    int i = 0;

    cout<<"Continuous series"<<endl;
    for (i = 0; i<20; i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Value of i is: "<<i<<endl;
    cout<<"Continuous evens"<<endl;
    for (i = 0; i<10; i+=2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Value of i is: "<<i<<endl;
    cout<<"Continuous odds"<<endl;
    for (int i = 1; i<10; i+=2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Value of i is: "<<i<<endl;
    cout<<"Continuous reverse series"<<endl;
    for (i = 10; i>0; i-=1)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Value of i is: "<<i<<endl;
    cout<<"Continuously Multiply by 2"<<endl;
    for (int i = 1; i<10; i*=2)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Value of i is: "<<i<<endl;
    cout<<"Another For usage"<<endl;
    i = 0;
    for (int i = 1; i<10; )
    {
        cout<<i<<" ";
        i = i+1;
    }
    cout<<endl;
    cout<<"Value of i is: "<<i<<endl;
    cout<<"Still Another usage"<<endl;
    for (;i<10; i+=3)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Value of i is: "<<i<<endl;
}

int main()
{
    /**********************
    * Add your code here
    ***********************/

    //Comment and Uncomment function calls to see how it works

    DataTypes();
    cout<<"The temperature in celsius is: "<<Temperature(102)<<endl<<endl;
    VariableScope();
    //VariableScope(10);
    //Conditionals();
    //WhileLoop();
    //DoWhileLoop();
    //ForLoop();
    /**********************
    * End of code
    ***********************/
    return 0;
}
