//Header file declarations

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>

//Text based adventure game

using namespace std;

//Global variable and array declarations and initializations are as follows

string outcomesGiveUP[5] = {"Death by starvation", "Death by disease", "Death by dehydration", "Death by avada kadavera", "Death by snake bite" };
int food_AndWaterSupplies = 10; // Food and water supplies are set for 10 days initially
string outcomesMoveForward[5] = {"Food and water", "Hidden chest", "3 bandits", "Healer", "Caravan"};
int Bow = 0; //Stores the quantity of bows received
int Arrows = 0; //Stores the quantity of arrows received
string Weapon = "Dagger"; //Stores the weapon currently in use
int Health = 20; //Stores the health of Rastan
int Bandits = 3; //Number of Bandits Rastan will encounter will be 3 each time
int hitChanceRastan = 40; //Stores Rastan's hit chance with a Dagger by default which is set to 40 percent
int hitChanceEnemy = 35; //Stores the hit chance of a Bandit which is set to 35 percent
bool isGameRunning = true; //A variable that keeps the gameloop / While loop in main running until its value id changed to false
char decision; //Stores the decision made by Rastan, Move forward or Give up
int tracks = 0; //Keeps a track of the number of times Rastan received a caravan
string consequenceMoveForward; //Stores a value from the array outcomes move forward

//Function declarations are as follows

void combatWithBandits (int*/*Health*/, int*/*Bandits*/, int*/*hitchanceRastan*/, int*/*hitchanceEnemy*/,int*/*Arrows*/, string* /*Weapon*/, bool*/*isGameRunning*/, int*/*Bow*/);
void weaponChanger(int*/*Bow*/, int*/*Arrow*/, string */*Weapon*/, int*/*hitChanceRastan*/);
void Healer(int*/*Health*/);
void supplyReplensher(int*/*food_AndWaterSupplies*/);
void tracksCounter(int*/*tracks*/, bool*/*isGameRunning*/);

int main()
{
    cout << "Welcome to the text based adventure game" << endl;
    cout << endl; //for spacing
    cout << "You are playing Rastan who is on his way to Persia from Delhi, you have been separated from your caravan, and are only armed with a dagger, you can either move forward or give up. Find the caravan 6 times in order to win the game" << endl;
    cout << endl; //for spacing

    while(isGameRunning) //When it receives a value false the loop terminates
    {
        cout << "Health = " << Health << endl << "Weapon = " << Weapon << endl << "Bow = " << Bow << endl << "Arrows = " << Arrows << endl << "Food and Water Supplies = " << food_AndWaterSupplies << endl << "Tracks = " << tracks << endl; //Main stats of game will be printed every time this loop runs
        cout << endl; //for spacing
        srand(time(NULL)); //seed is set in main so that whenever rand() is used a different random number is generated
        cout << "Make your decision, type F to move forward or G to give up" << endl;
        cin >> decision;
        if (decision != 'F' && decision != 'G') //It is a check to see if the user has entered a character besides F and G
        {
            cout << "You have entered an incorrect command" << endl;
            continue;
        }
        if (food_AndWaterSupplies == 0) //Game ends if food and water supplies end
        {
            cout << "Your water and food supplies have exhausted" << endl << "Death due to starvation and dehydration" << endl;
            break;
        }
        if (decision == 'F')
        {
            food_AndWaterSupplies--; //For each decision to move forward, supplies are decremented by one
            int r_and = rand() % 5; //Generates random number in the range 0-4 inclusive
            consequenceMoveForward = outcomesMoveForward[r_and]; //Stores a possible outcome from the array of outcomes at random

            if (consequenceMoveForward == "Food and water")
            {
                cout << "You have come across food and water, your supplies will be replenished for 5 more turns" << endl;
                supplyReplensher(&food_AndWaterSupplies); //Function called
            }
            else if (consequenceMoveForward == "Hidden chest")
            {
                cout << "You have come across a hidden chest" << endl;
                weaponChanger(&Bow, &Arrows, &Weapon, &hitChanceRastan); //Function called
            }
            else if (consequenceMoveForward == "3 bandits")
            {
                cout << "PREPARE FOR BATTLE" << endl;
                combatWithBandits(&Health, &Bandits, &hitChanceRastan, &hitChanceEnemy, &Arrows, &Weapon, &isGameRunning, &Bow); //Function called
                Bandits = 3; //Amount of bandits is once again set to 3 after a possible chance due to the execution of the function above
            }
            else if (consequenceMoveForward == "Healer")
            {
                cout << "you have come across a healer, your health loss will now be recovered" << endl;
                Healer(&Health); //Function called
            }
            else if (consequenceMoveForward == "Caravan")
            {
                cout << "You have come across a caravan, you have completed one track, you need to complete a total of 6 tracks to reach Persia" << endl;
                tracksCounter(&tracks, &isGameRunning); //Function called
            }

        }
        else if (decision == 'G')
        {
            int random = rand() % 5; //Random number in the range 0-4 is generated
            cout << outcomesGiveUP[random] << endl; //Any one of the possible reasons for death will be printed
            cout << "You Loose" << endl;
            isGameRunning = false; //While loop terminates
        }
    }
    return 0;
}

void Healer(int* ptr1/*points to Health*/)
{
    if (*ptr1 < 20)
    {
        *ptr1 = 20; //If health is less than 20 the healer will make it 20 again
    }
}

void supplyReplensher(int* ptr2/*points to food_AndWaterSupplies*/)
{
    *ptr2 = *ptr2 + 5; //Existing supplies are incremented by 5 whenever this function is called
}

void tracksCounter(int* ptr3/*points to tracks*/, bool* ptr4/*points to isGameRunning*/)
{
    *ptr3 = *ptr3+1; //The variable tracks is incremented by 1 each time a caravan is found
    if (*ptr3 == 6)  //if a total of 6 caravans are found, the journey comes to an end and the while loop in main terminates
    {
        cout << "Congratulations, you have reached your destination PERSIA" << endl;
        cout << "You win" << endl;
        *ptr4 = false;
    }
}

void weaponChanger(int* ptr5/*points to Bow*/, int* ptr6/*points to Arrows*/, string* w_EAPON/*points to Weapon*/, int* ptr7/*hitChanceRastan*/)
{
    string arr[2] = {"Bow", "Arrow"}; //Rastan could either receive a Bow or an Arrow when this function is called at random
    int NumRand = rand() % 2; //Stores a random number in the range 0-1 inclusive
    string Wep = arr[NumRand]; //Wep stores anything that comes up at random, a Bow or an Arrow
    if (Wep == "Bow")
    {
        *ptr5 = *ptr5 + 1; //Quantity of Bow is incremented by 1
        cout << "You have received a Bow" << endl;
    }
    else if (Wep == "Arrow")
    {
        int NumberRand = (rand() % 6) + 5; //Stores a random number in the range 5-10
        *ptr6 = *ptr6 + NumberRand; //Arrows can be from 5 to 10 inclusive
        cout << "You have received " << NumberRand << " Arrows" << endl;
    }
    if ((*ptr5 >= 1)&&(*ptr6 > 0)) //If there is a minimum of 1 Bow and 1 Arrow
    {
        cout << "You have received a new weapon" << endl;
        *w_EAPON = "Bow and Arrow"; //Weapon is changed to a Dagger
        *ptr7 = 75; //hitChanceRastan is assigned with a value of the hit chance of a Bow and Arrow
    }
    else if (!((*ptr5 >= 1)&&(*ptr6 > 0))) //Bow and arrow can only be used if there is a minimum of 1 Bow and one Arrow, otherwise a Dagger will be used during combat
    {
        *w_EAPON = "Dagger"; //Weapon is changed to a Dagger
        *ptr7 = 40; //hitChanceRastan is assigned with a value of the hit chance of a Dagger
        cout << "You have not received a Bow and Arrow" << endl;
    }
}

void combatWithBandits(int* ptr8/*points to Health*/, int*ptr9/*points to Bandits*/, int* ptr10/*points to hitChanceRastan*/, int* ptr11/*points to hitChanceEnemy*/, int* ptr12/*points to Arrows*/, string* ptr13/*points to Weapon*/, bool* ptr14/*points to isGameRunning*/, int* ptr15/*points to Bow*/)
{
    while((*ptr9 > 0)&&(*ptr8 > 0)) //This loop will continue to run until either the Health of Rastan becomes 0 or all the Bandits die
    {
        if (*ptr12 <= 0)  //If Arrows are less than or equal to 0 Weapon is changed to a Dagger and hitChance Rastan gets a value of 40 percent
        {
            *ptr10 = 40;
            *ptr13 = "Dagger";
            int Ban = *ptr9; //It stores the number of Bandits remaining
            for (int i = 0; i < Ban; i++) //Runs for the number of Bandits present to fight, Rastan gets his strikes in a row
            {
                int val = rand() % 100;
                int Chance1 = 0; //Stores the value of 1 if the random number in val is less than 40
                if (val < *ptr10)
                {
                    Chance1 = 1;
                }
                if (Chance1 == 1)
                {
                    *ptr9 = *ptr9 - 1; //Bandits decremented by 1 upon being shots
                    cout << "You shot a bandit with a Dagger" << endl;
                }
                else if (Chance1 != 1)
                {
                    cout << "You have missed your target" << endl;
                }
                cout << "Bandits = "<< *ptr9 << endl;
            }
            if(*ptr9 <= 0) //Checks if the number of Bandits is less than or equal to 0, in that case this while loop breaks
            {
                break;
            }
            else
            {
                for (int j = 0; j < *ptr9; j++) //Runs for the number of Bandits available, now the remaining number of Bandits get their turns against Rastan in a row
                {
                    int VAL = rand() % 100;
                    int Chance2 = 0; //Stores the value of 1 if the random number in val is less than 35
                    if (VAL < *ptr11)
                    {
                        Chance2 = 1;
                    }
                    if (Chance2 == 1)
                    {
                        *ptr8 = *ptr8 - 1; //Health of rastan is decremented by 1
                        cout << "You have been shot by a Bandit" << endl;
                    }
                    else if (Chance2 != 1)
                    {
                        cout << "You have dodged a shot from a Bandit" << endl;
                    }
                    cout << "Health = " << *ptr8 << endl;
                }
            }
        }
        else if ((*ptr12 > 0)&&(*ptr15 >= 1)) //If Arrows are greater than or equal to 1 and Bows are greater than 1, Weapon is changed to a Bow and Arrow and hitChance Rastan gets a value of 75 percent
        {
            int Ban = *ptr9;
            for (int i = 0; i < Ban; i++)  //This process is the same as described above
            {
                int val = rand() % 100;
                int Chance1 = 0;
                if (val < *ptr10)
                {
                    Chance1 = 1; //Stores the value of 1 if the random number in val is less than 35
                }
                if (Chance1 == 1)
                {
                    *ptr9 = *ptr9 - 1;
                    *ptr12 = *ptr12 - 1; //Each time a Bow and Arrow is used, the amount of Arrows is decremented by 1
                    cout << "You shot a bandit with a Bow and Arrow" << endl;
                }
                else if (Chance1 != 1)
                {
                    *ptr12 = *ptr12 - 1; //The amount of Arrows is decremented by 1
                    cout << "You have missed your target" << endl;
                }
                cout << "Bandits = "<< *ptr9 << endl;
            }
            if (*ptr9 <= 0)
            {
                break;
            }
            else
            {
                for (int j = 0; j < *ptr9; j++) //Same process as described above
                {
                    int VAL = rand() % 100;
                    int Chance2 = 0;
                    if (VAL < *ptr11)
                    {
                        Chance2 = 1;
                    }
                    if (Chance2 == 1)
                    {
                        *ptr8 = *ptr8 - 1;
                        cout << "You have been shot by a Bandit" << endl;
                    }
                    else if (Chance2 != 1)
                    {
                        cout << "You have dodged a shot from a Bandit" << endl;
                    }
                    cout << "Health = " << *ptr8 << endl;
                }
            }
        }
    }
    if (*ptr8 <= 0) //This is a check after the loop ends, If health is less than or equal to 0, "you have been killed" message is displayed
        {
            cout << "You have been killed" << endl;
            *ptr14 = false;
        }
    else if (*ptr9 <= 0) //Else if Bandits are less than or equal to 0
        {
            cout << "You have killed all three bandits" << endl;
        }
}
