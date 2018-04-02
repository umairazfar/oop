/*
    Mid Term Exam #1  CS224 OOP
    Thursday 21/09/2017   1100hrs - 1230hrs. Viva 1230hrs onward.
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
    Question no. 1: Write a structure named Rectangle which should have two attributes to store
    the height and width of the rectangle.
    - Add two constructors: one that doesn't take any argument and the other should take the
    values of height and width as arguments. You may check for any invalid arguments.
    - Add a function draw() to your structure that should "draw" your rectangle as height*width
    '*' characters,  i.e. Rect r(3,4); r.draw(); should produce
        [****
         ****
         ****] . Use [] to delimit your rectangle.
*/

/*
    Question no. 2: Write a function called "draw_rectangles" which receives
    an array of Rectangle types defined in Question 1 and draws all the
    Rectangle objects in that array by calling their draw() functions.
    You are  to figure out the number and types of arguments required  and
    the return type of the function.
*/

/*
    Question no. 3: write the Joiner function that takes two C-style strings
    and joins them together. It should return the new string.
    Remember, a string in C is a series of characters delimited by NULL char.
    Use the prototype:
    char* Joiner(char a[], char b[]);   //Joins two strings together
*/
char* Joiner(char a[], char b[]);   //Joins two strings together

int main()
{
    /* Example code when handling strings */
    char text1[] = "hello ";
    char text2[] = "world!";



    // Joiner function  should work as follows:
    //char* ptr;
    //ptr =  Joiner(text1, text2);
    //cout<<ptr;  //Should produce "hello world!" on screen.


    return 0;
}
