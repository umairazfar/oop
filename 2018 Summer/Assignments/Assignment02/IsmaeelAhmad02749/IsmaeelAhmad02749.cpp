#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<random>
#include<conio.h>
#include<windows.h>
#include<iomanip>


using namespace std; //for cin and cout

int currentHealth = 20;
int food = 10;
int caravanTracksCount = 0;
bool bow = false;
bool alive = true;
int arrows = 0;
bool daggerUse = true;
int banditCount = 3;

//ways to die
void starvation()
{
    alive = false;
    cout<<"Rastam has died of starvation"<<endl;
}
void snakebite()
{
    alive = false;
    cout<<"Rastam has died of snakebite"<<endl;
}
void dehydration()
{
    alive = false;
    cout<<"Rastam has died of dehydration"<<endl;
}
void avadakedavra()
{
    alive = false;
    cout<<"Rastam has died of avadakedavra"<<endl;
}
void disease()
{
    alive = false;
    cout<<"Rastam has died of disease"<<endl;
}

//die function, decides how exactly you die.
void giveUp()
{
    int fateMaking = rand() % 5;
    if (fateMaking == 0)
    {
        starvation();
    }
    else if (fateMaking == 1)
    {
        snakebite();
    }
    else if (fateMaking == 2)
    {
        dehydration();
    }
    else if (fateMaking == 3)
    {
        avadakedavra();
    }
    else if (fateMaking == 4)
    {
        disease();
    }

}

//move forward options.
//1
void healer()
{
    currentHealth = 20; //restores health to 20
    cout<<"Health restored."<<endl;
}
//2
void hiddenChest()
{
    cout<<"hidden chest found"<<endl;

    int fateMaking = rand() % 2; //what comes out of chest

    if (fateMaking == 0)
    {
        cout<<"Bow found"<<endl;
        bow = true;
    }
    if (fateMaking == 1)
    {
        cout<<"Arrows found"<<endl;
        arrows = arrows + 5;
        if (food < 5)
        {arrows = arrows + 10;}
    }
    if (bow == true && arrows > 0 ) //so that only bow arrow used when dagger both are present
    {                               //dagger is lost.
        daggerUse = false;
    }
}
//3
void caravanTracks() //wins if gets it 6 times
{
    caravanTracksCount++;
    cout<<"caravan tracks achieved "<<caravanTracksCount<<" times"<<endl;
    if (caravanTracksCount == 6)
        cout<<"congratz you won"<<endl;
        Sleep(1000); //so that player notices this more.
}
//4
void foodwater()
{
    food = 10; //food restored to 10
    cout<<"Food Restored."<<endl;
}
//bandit attack
void banditAttack() //bandith attack
{
    for (int i = 0; i < banditCount; i++) //every bandith attacks once
    {
        cout<<"Bandith Attack"<<endl;
        if (rand() % 100 < 35) //effectiveness is only 35 perc
        {
            currentHealth--;
        }
    }
}
//rastan attacks
void rastanAttack()
{
        for (int i = 0; i < banditCount; i++)
        {
            if (daggerUse == false && arrows > 0)//when both arrows nd bow are present
            {
                if (rand() % 100 < 75) //arrow bow has 75% effectiveness
                {
                    banditCount--;
                    cout<<"One Bandith Killed by bow & Arrow. "<<banditCount<<" Bandits left!!"<<endl;
                }
                arrows--; //arrow is lost despite it hits bandith or not
            }
            else if (rand() % 100 < 40) //dagger attack, effectivess = 40 perc
            {
                banditCount--;
                cout<<"One bandith killed by dagger. "<<banditCount<<" Bandits left!!"<<endl;
            }
        }

}
//war function, happens when he faces bandits
void combat()
{
    while (banditCount > 0)
    {
        cout<<"Fighting. "<<banditCount<<" Bandits left!!"<<endl; //announces start of combat
        rastanAttack();
        banditAttack();
    }


}
//5
void bandits()
{
    banditCount = 3;
    cout<<"BANDITHS HERE!!"<<endl;
    combat();
}

//moving forward function, decides what happens when he moves forward....
void movesForward()
{
    int forwardchoice = rand() % 5;
    if (forwardchoice == 0)
    {
         hiddenChest();
    }
    if (forwardchoice == 1)
    {
         healer();
    }
    if (forwardchoice == 2)
    {
         foodwater();
    }
    if (forwardchoice == 3)
    {
        bandits();
    }
    if (forwardchoice == 4)
    {
        caravanTracks();
    }

}

//how his day goes function, whether he moves forward or gives up....
void day()
{
    food--;
    int keyPressed;
    do
    {
        cout<<"----------------------------------------------------------------------"<<endl;
        cout<<"press y or enter to continue "<<endl;
        cout<<"press g if you want Rastan to give up"<<endl;
        cout<<"press q to quit"<<endl;
        cout<<"----------------------------------------------------------------------"<<endl;
        if (food < 0  || currentHealth <= 0)
        {
            alive = false;
            break;
        }
        keyPressed = getch();
        if (keyPressed == 113 || keyPressed == 81)
        {
            exit(0);
        }
        if (keyPressed == 13 || keyPressed == 121 || keyPressed == 89)
        {
            movesForward();
            break;
        }
        else if (keyPressed == 103 || keyPressed == 71)
        {
            giveUp();
            break;
        }
        else
        {
            cout<<"please type the appropriate letter"<<endl;
        }
    }
    while (keyPressed != 13 && keyPressed && 121 && keyPressed != 89 && keyPressed != 103 || keyPressed != 71);


}

void gameStart()
{
    int turn = 1; //day1
    while (alive == true && caravanTracksCount < 6)
    {
        day();
        cout <<left
        << "|Day ="<<turn<<"\t"<<endl;
        if (alive != false)
        {
            cout<< "|food remaining ="<<food<<"\t"
            << "|Current Power ="<<currentHealth<<"\t"
            << "|Bow Present ="<<bow<<"\t"
            << "|Arrows ="<<arrows<<"\t"
            << endl;
            turn++;
        }

    }
    if (alive == false)
    {
        cout<<"----------------------------------------------------------------------"<<endl;
        cout<<"No day: "<<turn<<" for Rastan."<<endl;
        if (food < 0)
        {
            cout<<"Starvation"<<endl;
        }
        if (currentHealth <= 0)
        {
            cout<<"killed in combat"<<endl;
        }
        cout<<"game OVER, RASTAN HAS DIED"<<endl;
        Sleep(1000);
    }


}

int main()
{
    cout<<"Welcome to Rastan Adventure Game.\n"
    <<"Rastan has to find caravan tracks 6 times to win.\n"
    <<"Rastan can also find a hidden chest which will contain weapons,\n"
    <<"or a Healer, who will heal him to full power,\n"
    <<"or a food reservoir, which will fill his food storage,\n"
    <<"or Bandiths, who will fight to death to stop Rastan from moving forward.\n"
    <<"best of luck !!"<<endl;
    srand(time(NULL));
    gameStart();
    return 0;
}



