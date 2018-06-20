//include header files from Standard Library
#include <iostream>
#include <stdlib.h> //For random numbers
#include <time.h> //For generating a new random seed
#include <conio.h> //It contains functions for console input/output
#include <cstdlib> //Standard General Utilities Library

using namespace std;//required for using cin and cout commands

//Function Headers
void Game();
void Forward(int*,int*,bool*,int*,int*,int*);
void GiveUp();
void Combat(int*,int*,bool*,int*);

int main()
{
    cout<<"A young man named Rastan got separated from his caravan on his way to Persia.\n"
        <<"Armed only with a dagger, He has nowhere to go except to move forward.\n"
        <<"But his path is laden with awards and mischief. To help him find his caravan: \n"
        <<"PLAY the game as if you were in place of Rastan.\n"
        <<"If you are able to find caravan tracks 6 times you will reach Persia!!.\n";
    cout << "\n----------------------Press any key to continue----------------------" << endl;
    getch();
    system("cls"); //Clears the Screen
    Game();
    return 0;
}
void Game()
{
    int Food = 10;
    int Health = 20;
    int Arrows = 0;
    bool Bow = false;
    int Bandits = 0;
    int Tracks =0;
    int Choice = 0;
    int Day=0;
    int exit = 0; //0 to continue, something else to exit the game
    do
    {
        cout << "# Its a New Day. What would you like to do?" << endl;
        cout<<"\t >> Enter '1' to move Forward?"<<endl<<"\t >> Enter '2' to Give Up?"<<endl;
        retry:
        cout << "\nEnter your choice: ";
        cin>>Choice;
        if (Choice == 1)
        {
            Day=Day+1;//To count turns taken by the user
            cout << "\n!!!----------------------Day "<<Day<<"----------------------!!!" << endl;
            cout<<"Health="<<Health<<" & Food="<<Food<<" days"<<" & Tracks="<<Tracks<<endl<<endl;
            Forward(&Food,&Arrows,&Bow,&Health,&Bandits,&Tracks);
            Food=Food-1; //Food is consumed for one day
            cout << "\n---------------Press any key to continue---------------" <<endl<<endl;
            getch();  //To take user input, any key
            if (Tracks==6) //Winning Condition
            {
                exit=1; //Exits the loop, To Finish the Game
                cout<<"Rastan found the Tracks 6 Times thus He reached Persia"<<endl;
                cout<<"YOU WON"<<endl;
            }
            if (Food==0)
            {
                exit=1; //Exits the loop, To Finish the Game
                cout<<"Death as no Food Left"<<endl;
            }
            if (Health<=0)
            {
                exit=1; //Exits the loop, To Finish the Game
                cout<<"Death due to 0 Health"<<endl;
            }
        }
        else if (Choice == 2)
        {
            GiveUp(); //Results in Rastan's death
            exit=1;
        }
        else
        {
            cout<<"In-valid Number entered!"<<endl;
            goto retry; //Make sure correct number is entered
        }
    }
    while(exit==0);//...and will execute again and again until exit != 0
}

void Forward(int* Food,int* Arrows,bool* Bow,int* Health,int* Bandits,int* Tracks)
{
    srand (time(NULL)); //For Generating Random number
    int cases = rand() % 5; //Random numbers from 0 to 4 Generated, for 5 Cases
    if (cases == 0)
    {
        cout<<"You comes across food and water and replenishes your supplies for 5 more days"<<endl;
        *Food=*Food + 5;
    }

    else if (cases == 1)
    {
        int random = rand() % 2; //Random numbers from 0 to 1 Generated
        if (random == 0)
        {
            cout<<"You comes across a hidden chest that contains a weapon(Bow)."<<endl;
            *Bow=true;
        }
        else
        {
            cout<<"You comes across a hidden chest that contains arrows."<<endl;
            int radom=rand() % 6; //The number of arrows found can range from 5 to 10, so 6 cases generated
            if (radom==0)
            {
                *Arrows= *Arrows+5;
            }
            else if (radom==1)
            {
                *Arrows= *Arrows+6;
            }
            else if (radom==2)
            {
                *Arrows= *Arrows+7;
            }
            else if (radom==3)
            {
                *Arrows= *Arrows+8;
            }
            else if (radom==4)
            {
                *Arrows= *Arrows+9;
            }
            else if (radom==5)
            {
                *Arrows= *Arrows+10;
            }
            cout<<"Now you have "<<*Arrows<<" Arrows"<<endl;
        }
    }

    else if (cases == 2)
    {
        cout<<"You comes across 3 bandits."<<endl;
        *Bandits=3; //Always 3 Bandits
        Combat(Health,Arrows,Bow,Bandits); //Separate Function for Combat against Bandits
    }
    else if (cases == 3)
    {
        cout<<"You comes across a healer who heals you completely."<<endl;
        *Health=20; //Health Points are maximized
    }
    else if (cases == 4)
    {
        cout<<"You comes across caravan tracks."<<endl;
        *Tracks=*Tracks+1; //Counter for keeping track how many times tracks are found
    }
}

void Combat(int* Health,int* Arrows,bool* Bow,int* Bandits)
{
    srand (time(NULL)); //For Generating Random Numbers
    if (*Health > 0) //Can Only Fight if Health Points are available
    {
        for(int a=0 ; a<3; ++a) //This loop works 3 times as First Rastan will attack 3 Bandits, each separately
        {
            cout<<"To attack a Bandit Press Enter"<<endl;
            getch();
            int Hitchance= rand() % 100; //Generates 0-99 Random Numbers
            if ((*Bow==true ) && (*Arrows > 0)) //Bow and Arrows Both must be present, to hit using Arrows
            {
                cout<<"You used Bow and Arrows";
                *Arrows=*Arrows-1; //One Arrows thrown towards Bandit, So number of decremented
                if (Hitchance < 75)
                {
                    cout<<" to kill Bandit"<<endl; //The hit chance of Bow and Arrow is 75%
                    *Bandits=*Bandits-1; //Number of Bandits decremented
                }
                else
                {
                    cout<<" But it didn't hit the Bandit"<<endl; //Remaining 25% Chance for not Hitting
                }
            }
            else //By Default Dagger is used to attack if no Bow and Arrow are found
            {
                cout<<"You used the Dagger";
                if (Hitchance < 40) //The hit chance of the dagger is 40% only, otherwise he will miss
                {
                    cout<<" to kill Bandit"<<endl;
                    *Bandits=*Bandits-1; //Number of Bandits decremented
                }
                else
                {
                    cout<<" But it didn't hit the Bandit"<<endl;
                }
            }
        }
    cout<<*Bandits<<" Bandits are Left"<<endl; //Number of Bandits left and each of them will attack now.
    }
    cout<<"If you wanna move Forward after attacking Bandits Press Enter"<<endl;
    getch();
    while(*Bandits>0) //Number of Bandits left takes their turn one by one.
    {
        cout<<"Bandit Attacked you";
        int EnemyHitchance= rand() % 100;
        if(EnemyHitchance<35)
        {
            cout<<" and you loses 1 Health Point"<<endl; //The enemies have a hit chance of 35%
            *Health=*Health-1; //Health Points decremented
        }
        else
        {
            cout<<" But unable to hit you."<<endl;
        }
        *Bandits=*Bandits -1; //Counter for Bandits
        if (*Bandits>0) //This Condition has been made so that after attack of each Bandit, some user input is taken
        {
            cout<<"If you wanna try to escape again Press Enter"<<endl;
            getch();
        }
    }
}

void GiveUp()
{
    srand (time(NULL)); //For Generating Random Numbers
    int random = rand() % 5; //Random Numbers from 0-4 are generated.
    if (random == 0)
    {
        cout<<"Death by starvation"<<endl;
    }
    if (random == 1)
    {
        cout<<"Death by disease"<<endl;
    }
    if (random == 2)
    {
        cout<<"Death by dehydration"<<endl;
    }
    if (random == 3)
    {
        cout<<"Death by avada kadavera"<<endl;
    }
    if (random == 4)
    {
        cout<<"Death by snake bite"<<endl;
    }
}
