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
struct rectangle{
    int height, width;
    rectangle(){height=0;width=0;}
    rectangle(int h, int w){
        if (h<0||w<0)
            {cout <<"Invalid values. Resorting to default"<<endl; height=0;width=0;}
        else {height =h; width = w;}
    }
    void   draw(){
        cout<<"[";
        for (int i=0; i< height;i++){
            for (int j=0; j< width;j++)
            cout<<"*";
            if(i<height-1)cout<<endl<<" ";else{cout<<"]"<<endl;}
        }
    }

};
/*
    Question no. 2: Write a function called "draw_rectangles" which receives
    an array of Rectadngle types defined in Question 1 and draws all the
    Rectangle objects in that array by calling their draw() functions.
    You are  to figure out the number and types of arguments required  and
    the return type of the function.
*/
void draw_rectangles(rectangle a[], int size){
    for (int i=0; i<size; i++)
        a[i].draw();
}
/*
    Question no. 3: write the Joiner function that takes two C-style strings
    and joins them together. It should return the new string.
    Remember, a string in C is a series of characters delimited by NULL char.
    Use the prototype:
    char* Joiner(char a[], char b[]);   //Joins two strings together
*/
char* Joiner(char a[], char b[]){   //Joins two strings together
  int cnt1 = 0; int cnt2 = 0;
  char *p = a;   while (*p++) cnt1++;
        p = b; while(*p++) cnt2++;

  cout <<cnt1<<" "<<cnt2<<endl;
  char* newstr = new char[cnt1+cnt2+1];
  char* p2 = newstr;

  p = a; while (*p)  *p2++ = *p++;
  p = b; while (*p)  *p2++ = *p++;
  *p2 = '\0';

  return newstr;
}


int main()
{


    rectangle r(3,4); r.draw();


    /* Example code when handling strings */
    char text1[] = "hello ";
    char text2[] = "world!";



    // Joiner function  should work as follows:
    char* ptr;
    ptr =  Joiner(text1, text2);
    cout<<ptr<<endl;  //Should produce "hello world!" on screen.


    return 0;
}
