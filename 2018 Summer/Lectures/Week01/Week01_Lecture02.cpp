/**
* OOP lecture 02. Programming Basics in C++
* Understanding Arrays and Strings
**/

#include<iostream> //Similar to import command in Python
#include<stdio.h>
#include<stdlib.h>//For random numbers
#include<time.h>//For generating a new random seed
#include <iomanip>
using std::setw;

using namespace std;    //required for using cin and cout commands


int main()
{
    /**********************
    * Add your code here
    ***********************/

    //Initializing
    /*
    int numbers[3];

    cout<<numbers[0]<<endl;
    cout<<numbers[1]<<endl;
    cout<<numbers[2]<<endl;

    int numbers1[2] = {1,2};  //remove the number of elements then see

    cout<<numbers1[0]<<endl;
    cout<<numbers1[1]<<endl;
    cout<<numbers1[2]<<endl;

    int numbers2[3];

    numbers2[0] = 10;
    numbers2[1] = 20;
    numbers2[2] = 30;

    cout<<numbers2[0]<<endl;
    cout<<numbers2[1]<<endl;
    cout<<numbers2[2]<<endl;
*/
    int num[20];

    for (int i=0; i<20;)
    {
        num[i] = ++i;
        cout<<num[i]<<" ";
    }
    cout<<endl;

    char name[] = "karim1";
    cout<<name;

    cout<<endl;
    int a = 0;
    char b = 'k';

    char alpha[] = {'a', 'b', 'c'};
    cout<<alpha<<endl;

    cout<<sizeof(alpha)<<endl;
    cout<<sizeof(a)<<endl;
    cout<<sizeof(b)<<endl;
    cout<<sizeof(name)<<endl;
    cout<<sizeof(num)<<endl;

    int matrix[3][3] = { {1,0,0},
                         {0,1,0},
                         {0,0,1}};


    for (int i = 0; i< 3; i++)
    {
        for (int j = 0; j< 3; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int binary[10][10];

    for (int i = 0; i< 10; i++)
    {
        for (int j = 0; j< 10; j++)
        {
            binary[i][j] = j % 2;
        }
    }

    for (int i = 0; i< 10; i++)
    {
        for (int j = 0; j< 10; j++)
        {
            cout<<binary[i][j];
        }
        cout<<endl;
    }

    return 0;
}

//Exercise 1
//Change the code above so that it shows numbers from 0 to 99

//Exercise 2
//Write a code that generates an array that contains random numbers
//Then write code to sort it in ascending and descending order

//Exercise 3
//Write code that asks the user to input five names.
//Then write the names in a text file.
//You should only use character arrays
