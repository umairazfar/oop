/*
    Mid Term Exam #1  CS224 OOP
    Friday 22/09/2017   1100hrs - 1230hrs. Viva 1230hrs onward.
*/


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
    (50% marks)
    Question no. 1: Write a structure named Date which should save the date as day, month and the year.
    - Add two constructors: one that doesn't take any argument and the other should take the
    values of day, month, and year as arguments. You may check for any invalid arguments.
    - Add function show_british() and show_american which should display the date as dd/mm/yyyy
	and mm/dd/yyyy respectively
	- Add a function increment(), which should add a day in the value currently stored in that
	Date object to calculate the next date. Next date should be a valid date!

	- In main() create objects of Date using both constructors
	- Display the dates, increment them and then  display the incremented values.
*/

/*
    (50% marks)
    Question no. 2: Write a function called "find_occurrences" which receives
    an array of integers and it's size.
	For each integer in it's argument array, the function should calculate how many times that
	integer occurs in that array.
	This function should return an array containing the number-of-occurrences for each integer
	i.e. {num1, num1_occurrences, num2, num2_occurrences, ...}.

	You have to figure out the total number and types of arguments that will be needed for this
	function, as well as it's return type.

	Example: When calling your function find_occurrences() in main(), if I pass it an array
	which I declared as int a[10]={2,3,5,5,2,5,5,5,5,2}, it should return me an array containing
	{2,3,3,1,5,6}, i.e., telling me that 2 occurred thrice, 3 once and 5 occurred six times in the
	original array.

	You can then pass the array returned by the find_occurrences() function in main() to the 
	show_occurrences() function below  to display them.

*/

void show_occurrences(int a[], int size){

	if(size%2 != 0){	//always check for consistencies on your data
		cout<<"Error: There's something wrong with  your array"<<endl;
		return;
	}

	for (int i=0; i<size; i=i+2)
		cout<<"The number "<<a[i]<<" occurred "<<a[i+1]<<" times"<<endl;
}

int main()
{

    return 0;
}
