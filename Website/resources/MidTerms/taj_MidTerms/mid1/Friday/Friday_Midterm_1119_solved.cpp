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

bool is_leap (int year){
return ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0));
}

bool date_is_valid(int d, int m, int y){
    if((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>31)
        return false;
    else if((m==4||m==6||m==9||m==11)&&d>30)
        return false;
    else if (m==2)
        if (is_leap(y) && d>29)
            return false;
        else if (!is_leap(y) && d>28)
            return false;
    else
        return true;
}

class Date {

    public:
    Date(){day=1;month=1;year=1970;}
    Date (int d, int m, int y){
        if(date_is_valid(d, m, y)){
            day = d; month = m; year = y;
        }
        else {
            cout <<"Invalid values passed for Date. Resorting to default"<<endl;
            day = 1; month = 1; year = 1970;
        }
    }

    void increment(){
        day++;
        if((month==1||month==3||month==5||month==7||month==8||month==10)&&day>31)
        {
            month++; day=1;
        }
        else if ((month==4||month==6||month==9||month==11)&&day>30)
        {
            month++; day=1;
        }
        else if (month==12&&day>31)
        {
            year++;month=1;day=1;
        }
        else if (month==2)
            if (is_leap(year)&&day>29)
            {
                month++;day=1;
            }
            else if (!is_leap(year)&&day>28){
                month++; day=1;
            }
    }


    void show_british(){cout <<day<<"/"<<month<<"/"<<year;}
    void show_american(){cout <<month<<"/"<<day<<"/"<<year;}
private:
    int day;
    int month;
    int year;
};
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

int * find_occurrences (int a[], int a_size, int &new_size)
{

    int * new_array = new int [a_size*2];
    int nums_done = 0;

    for (int i=0; i<a_size; i++)
    {// for each element in array

        // check if it's already done
        bool b_done = false;
        for (int k=0; k<nums_done; k = k+2)
            if (a[i]==new_array[k]) b_done = true;

        // if it's not done
        if (!b_done){
            int count = 1;
            for  (int j=i+1; j<a_size; j++){ //find its occurrences in the rest of array
                if (a[i]==a[j]) count ++;
            }

            //store the occurrence
            new_array[nums_done++] = a[i];
            new_array[nums_done++] = count;
        }
    }

    new_size = nums_done;
    return new_array;
    /* The array being returned may be larger than necessary
    but it doesnt' matter as the size returned is correct.
    If you wnat to be proper you can allocate an array of exact
    size and then copy the data before returning it. i.e. replace last line with:
    int *n = new int [nums_done];
    for  (int i=0;i<nums_done; i++) n[i] = new_array[i];
    delete [] new_array;
    return n;
    */
}
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

    Date x(29,2,2004);
    x.show_british();
    x.increment();
    x.show_british();

    int a[10]={2,3,5,5,2,5,5,5,5,2};
    int size = 0;
    int *p = find_occurrences(a, 10, size);
    show_occurrences(p, size);
    return 0;
}
