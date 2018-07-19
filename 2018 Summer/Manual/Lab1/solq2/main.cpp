#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using namespace std;

int main()
{
    int distanceFrogPrime = 0;
    int distanceFrogatron = 0;
    int chanceFP;
    int chanceFR;
    int turnCount = 0;
    srand(time(NULL));
    while (distanceFrogatron <= 1000 && distanceFrogPrime <= 1000)
    {
        chanceFP = rand() % 100;
        chanceFR = rand() % 100;
        if (chanceFP <= 1)
        {
            distanceFrogPrime += 4;
        }
        else
        {
            distanceFrogPrime += 3;
        }
        if (chanceFR <= 1)
        {
            distanceFrogatron += 4;
        }
        else{
            distanceFrogatron += 3;
        }

        turnCount += 1;
        if (turnCount % 50 == 0)
        {
            cout << "Distance covered by frogPrime: " << distanceFrogPrime << endl;
            cout << "Distance covered by frogatron: " << distanceFrogatron << endl;
        }
        if (distanceFrogatron >= 1000)
        {
            cout << "Frogatron won" << endl;
            cout << "Total jumps: "<< turnCount << endl;
        }
        else if (distanceFrogPrime >= 1000)
        {

            cout << "FrogPrime won" << endl;
            cout << "Total jumps: " << turnCount << endl;
        }
    }
    return 0;
}
