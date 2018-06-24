#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <string.h>

using namespace std;

//Initializing global variables as they are used in various functions;
int sword = 0;
int bow = 0;
int knife = 0;
int arrow = 0;
int tracks = 0;
int health = 20;
int dagger = 1;
int food = 10;
int bandits;

//Case-I (i.e. if Rastan decides to give up)
void giveup()
{
    int possibilities;
    srand(time(NULL));
    possibilities = rand() % 5 + 1; //Generating random numbers between 1 and 5, since Rastan may die from any of the five possibilities.
    if (possibilities == 1)
    {
        cout<<"Rastan is died due to starvation"<<endl;
    }
    else if (possibilities == 2)
    {
        cout<<"Rastan is died due to disease"<<endl;
    }
    else if (possibilities == 3)
    {
        cout<<"Rastan is died due to dehydration"<<endl;
    }
    else if (possibilities == 4)
    {
        cout<<"Rastan is died due to avada kadavera"<<endl;
    }
    else if (possibilities == 5)
    {
        cout<<"Rastan is died due to snake bite"<<endl;
    }
}

//If Rastan decides to move forward, then this 'weapon()' function will execute if Rastan comes across a hidden chest
//Refer to line number 243
int weapons()
{
    int option;
    option = rand() % 4 + 1;        //Random between 1 and 4.
    if (option == 1)
    {
        arrow = rand() % 6 + 5;     //Random between 5 and 10.
        cout<<arrow<<" "<<"arrow(s) collected"<<endl;
        knife = 0;
        sword = 0;
        dagger = 0;
    }
    else if (option == 2)
    {
        bow = 1;
        knife = 0;
        dagger = 0;
        sword = 0;
        cout<<bow<<" "<<"bow collected"<<endl;
    }
    else if (option == 3)
    {
        sword = 1;
        knife = 0;
        dagger = 0;
        bow = 0;
        cout<<sword<<" "<<"sword collected"<<endl;

    }
    else if (option == 4)
    {
        knife = 1;
        bow = 0;
        sword = 0;
        dagger = 0;
        cout<<knife<<" "<<"knife collected"<<endl;
    }
    return 0;
}

//Hit chances of Rastan's weapons (refer to line number 185)
int chances()
{
    int c;               //To keep check if Rastan's attempt is successful or not
    int hit_chance = rand() % 100 + 1;
    //cout<<"hit_chance: "<<hit_chance<<endl;
    if (sword == 0 && knife == 0 && bow == 0)
    {
        dagger = 1;
        //cout<<"Rastan is attacking with dagger"<<endl;
        if (hit_chance <= 40)
        {
            //cout<<"Rastan's attempt is successful, one enemy died"<<endl;
            bandits--;
            c = 1;
        }
        else
        {
            c = 0;
        }
    }
    else if (bow > 0 && arrow > 0)
    {
        //cout<<"Rastan is attacking with bow&arrow"<<endl;
        if (hit_chance <= 75)
        {
            //cout<<"Rastan's attempt is successful, one enemy died"<<endl;
            bandits--;
            arrow--;
            c = 1;
        }
        else
        {
            arrow--;
            c = 0;
        }
    }
    if (bow > 0 && arrow < 1)
    {
        //cout<<"Rastan can't use a bow without an arrow"<<endl;
        dagger = 1;
        c = 0;
    }
    else if (sword > 0)
    {
        dagger = 0;
        knife = 0;
        //cout<<"Rastan is attacking with sword"<<endl;
        if (hit_chance > 0 && hit_chance <= 75)
        {
            //cout<<"Rastan's attempt is successful, one enemy died"<<endl;
            bandits--;
            c = 1;      //assigning 1 to c if Rastan's attempt is successful; else 0.
        }
        else
        {
            c = 0;
        }
    }

    else if (knife > 0)
    {
        sword = 0;
        dagger = 0;
        //cout<<"Rastan is attacking with knife"<<endl;
        if (hit_chance > 0 && hit_chance <= 75)
        {
            //cout<<"Rastan's attempt is successful, one enemy died"<<endl;
            bandits--;      //Every time the enemy dies, 'bandits' gets decremented.
            c = 1;
        }
        else
        {
            c = 0;
        }
    }
    return c;
}

//This 'combat()' function will execute if Rastan face bandits upon his decision to move forward in each turn.
int combat()
{
    int hit = rand() % 35 + 1;
    int turn = 1;
    int counter = 1;
    //int x = 3;
    int x = bandits;
    for (int i = 0; i < x; i++)
    {
        if (bandits > 0)
        {

        //cout<<"Turn "<<turn<<endl;
            int s = chances();      //Upon facing bandits, the Rastan will attempt to kill bandits and the chances of bandit getting killed would be determined with this function.
            if (s == 1)
            {
                cout<<"Turn "<<turn<<": Rastan's attempt is successful, one enemy died"<<endl;

                if (bandits == 0)
                {
                    cout<<"Turn "<<turn<<": All bandits are dead"<<endl;
                }
            }
            else
            {
                cout<<"Turn "<<turn<<": Rastan's attempt is missed"<<endl;
            }

            cout<<"Bandits left: "<<bandits<<endl;

        }
        turn++;
    }
    for (int j = 0; j < bandits; j++)
    {
        if (hit <= 35)
        {
            if (bandits > 0)
            {
                health = health - 1;
                cout<<"Turn "<<counter<<": Bandit's attack is successful. Now Rastan's health is: "<<health<<endl;
                //cout<<"Rastan's health is: "<<health<<endl;
            }
        }
        else
        {
            cout<<"Turn "<<counter<<": Bandit's attack is missed and Rastan is safe"<<endl;
        }
        counter++;
    }
    return 0;
}

//Case-II (i.e. if Rastan decides to move forward)
int moveforward()
{
    int choice;
    srand(time(NULL));
    choice = rand() % 5 + 1;

    if (choice == 1)
    {
        cout<<"Rastan comes across food and water and replenishes his supplies for 5 more days"<<endl;
        food = food + 5;
        food--;
        cout<<"Food left for: "<<food<<" days"<<endl;

    }
    else if (choice == 2)
    {
        cout<<"Rastan comes across a hidden chest that contains a weapon or arrows"<<endl;
        weapons();      //Upon calling this function, Rastan will either get knife, arrow, bow, sword which is based on random number generation in 'weapons()' function above.
        food--;
        cout<<"Now Rastan has food stock of "<<food<<" days"<<endl;
    }
    else if (choice == 3)
    {
        bandits = 3;
        cout<<"Rastan comes across "<<bandits<<" bandits"<<endl;

        while (bandits > 0)
        {
            combat();          //If Rastan finds 3 bandits, this combat() function will run where Rastan and bandit would fight.
        }
        food--;
        cout<<"Now Rastan has food stock of "<<food<<" days"<<endl;
    }
    else if (choice == 4)
    {
        cout<<"Rastan comes across a healer who heals him"<<endl;
        health = 20;           //Health full
        cout<<"Rastan's health is "<<health<<endl;
        food--;
        cout<<"Now Rastan has food stock of "<<food<<" days"<<endl;

    }
    else if (choice == 5)
    {
        cout<<"Rastan comes across caravan tracks"<<endl;
        tracks = tracks + 1;
        cout<<"Tracks discovered: "<<tracks<<endl;
        food--;
        cout<<"Now Rastan has food stock of "<<food<<" days"<<endl;
    }
    return 0;
}

//This function will be executed to play the game
int playgame()
{
    char decision;
    cout<<"****************WELCOME TO THE ADVENTURE GAME****************"<<endl;
    while (true)
    {
        cout<<endl;
        cout<<"~~~~~~~~~~~~Type 'y' to move forward~~~~~~~~~~~~"<<endl;
        cout<<"~~~~~~~~~~~~~~Type 'n' to give up~~~~~~~~~~~~~~"<<endl;
        cin>>decision;
        if (decision == 'n' || decision == 'N')
        {
            giveup();       //If selected 'no', the game will quit.
            break;
        }
        if (decision == 'y' || decision == 'Y')
        {
            moveforward();
            if (tracks == 6)        //Upon getting caravan tracks 6 times, Rastan will reach Persia and game will end.
            {
                cout<<"Rastan has reached Persia, GAME IS OVER"<<endl;
                break;
            }
            else if (food == 0)
            {
                cout<<"Rastan's food stock is empty and he's dead now. . . GAME OVER"<<endl;
                break;      //If food = 0, Rastan will die and the game will be over
            }
            else if (health == 0)
            {
                cout<<"Rastan's health is zero and he is dead... GAME OVER"<<endl;
                break;      //If health = 0, Rastan will die and the game will be over
            }
        }
    }
}

int main()
{
    playgame();        //Actual playing function
}
