#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

float* DataAnalyzer(float* allData, int totalValues);

int main()
{
    srand (time(NULL));

    int totalValues = 5 + rand() % 6;
    float* allData = new float[totalValues];

    for (int i = 0; i<totalValues; i++)
    {
        allData[i] = (10 + rand()% 10) + ((float)(rand()%10)/10);   //Q1: What is happening here?
    }

    allData = DataAnalyzer(allData, totalValues);

    //Q2: What should we write in the cout lines? Students cannot add any variable in main function
    cout<<"The sum of all the values is: "<<allData[totalValues]<<endl; //allData[totalValues] will be hidden
    cout<<"The square of the sum of all the values is: "<<allData[totalValues+1];   //allData[totalValues+1] will be hidden

    delete[] allData;
    return 0;
}

float* DataAnalyzer(float* allData, int totalValues)
{
    float* temp = new float[totalValues];

    for(int i = 0;i <totalValues; i++)
    {
        temp[i] = allData[i];
    }

    delete[] allData;   //Q3: Check if they are deallocating memory

    allData = new float[totalValues + 2];   //Q4: Check if they are declaring a longer array

    allData[totalValues] = 0;
    for(int i=0; i<totalValues; i++)    //Q5: Check how they are saving sums
    {
        allData[i] = temp[i];
        allData[totalValues] = allData[totalValues] + temp[i];

    }
    delete[] temp;

    //Q6: Check how they are saving square of sums
    allData[totalValues+1] = 0;
    allData[totalValues+1] = allData[totalValues] * allData[totalValues];
    return allData;
}
