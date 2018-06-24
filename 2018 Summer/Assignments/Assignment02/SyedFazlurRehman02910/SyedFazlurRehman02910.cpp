
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

enum {FORWARD =0, GIVE_UP =1};

enum {starvation,  disease, dehydration, avadaKadavera,  snakeBite,BANDITS =10, healer =11,  caravanTracks=12, WEAPONS = 13, FOOD =14};

bool alive = true;  //Keeps check on Rastan's life
int health = 20;    //Keeps check on Rastan's health i.e. 20 max
int tracks = 0;     //Number of caravan tracks encountered
bool dagger = true;

bool bow = false;   //Useful when a weapon is generated only when both of bow and arrow is true according to given condition
bool arrow = false;
int ArrowS = 0;
int currentWeapons;


bool HitChance(int weaponact) //either fighting with dagger or bow and arrow
{

    bool bandit_dead = false;
    int rand_weapon = rand()%100;
    if ( weaponact == 0)
    {
        cout << "Rastan's fighting with a dagger"<< endl;
        if (rand_weapon <= 40)
        {
            bandit_dead = true;

        }
    }

    else if ( weaponact == 1)
    {
        cout << "Rastan's fighting with a bow and arrow"<<endl;
        if (rand_weapon < 75)
        {
            bandit_dead = true;
        }
    }


    return bandit_dead;
}
void Bandits_act() // encountering bandits
{
    int encounter = 0;
    int banditCheck = 0;
    int random_bandits = rand()%3 + 1;  //encountering 1 to 3 bandits randomly
    cout << "Number of banditss " << random_bandits << endl;

    for (int i = 0; i<random_bandits; i++)
    {

        banditCheck = banditCheck + 1;

    }
    while (banditCheck != 0)//combat goes on till all the bandits are dead
    {

        for ( int i = 0; i < random_bandits; i++)
        {
            if (banditCheck == 1)
            {
                bool result = HitChance(currentWeapons);
                if (result == true)
                {
                    cout << "Bandit " << i+1 << "is dead" << endl;
                    banditCheck = banditCheck - 1;

                }
                else
                {
                    cout << "Bandit " << i+1 << " survived" << endl;
                }
            }

        }
        //strategy for Rastan's combat with the bandits:
        for (int i = 0; i < banditCheck; i++)
        {
            if (banditCheck == 1) // if enemy is alive
            {
                int random = rand()%100;
                if (random < 35)
                {
                    health = health - 1;
                    cout << "Rustan got hit by fighting enemy " << i <<  endl;
                }
                else
                {
                    cout << "Rastan is safe" << endl;
                }
            }
            encounter++;

        }

        cout << "Encounter "<< encounter << " with bandits!" <<  endl;

    }

}



int Weaponry()
{
    int weapon = rand()%8;
    if ((weapon == 0) || ( weapon >= 4 && weapon < 6 ))//For bow&arrow
    {
        bow = true;
        cout << "You got a bow!" << endl;
    }

    else if ((weapon == 1) || (weapon >= 6 && weapon <8)) // arrow
    {
        arrow = true;
        ArrowS = rand()%6 + 5;
        cout << "Rastan has " << ArrowS << " arrows" <<endl;
    }



    if ((bow == true) && (arrow == true) && (ArrowS > 0))
    {
        currentWeapons = 1;
    }

    if (ArrowS < 0)
    {
        cout << " No more arrows left" << endl;
    }

    return currentWeapons;
}
void game()
{
    int tracks;
    int scenario;
    int days = 0;
    int supply = 10; //for food & water

    do
    {
        cout<<"Do you want to move Rastan forward = 0 or give up = 1 ?"<<endl;
        cin>>scenario;

        if (scenario == GIVE_UP)
        {
            srand(time(NULL));
            int death = rand()% 5 +1; //for random death

            switch(death)
            {
            case starvation:
                cout<<"Rastan died by starvation"<<endl;
                alive = false;
                break;
            case disease:
                cout<<"Rastan died by a disease"<<endl;
                alive = false;
                break;
            case dehydration:
                cout<<"Rastan died by dehydration"<<endl;
                alive = false;
                break;

            case avadaKadavera:
                cout<<"Rastan died by avada kadavera"<<endl;
                alive = false;
                break;
            case snakeBite:
                cout<<"Rastan died by snake bite"<<endl;
                alive = false;
                break;
            }
        }
        if (scenario == FORWARD)
        {
            srand(time(NULL));
            int random_move = rand()% 5 +10; //things Rastan will come across in future

            switch(random_move)
            {
            case BANDITS:
                Bandits_act();
                break;
            case healer:
                cout<<"Rastan is now healed!"<<endl;
                health = 20;
                break;
            case caravanTracks:
                cout<<"Rastan came across caravan tracks."<<endl;
                tracks = tracks +1;
                break;
            case WEAPONS:
                cout << Weaponry(); //other weapon have priority over dagger
                dagger = false;
                break;
            case FOOD:
                cout<<"Rastan now has food and water."<<endl;
                supply = supply +5;

            }
            supply--; //food and water supply decreases by 1, everyday
            if(tracks==6)
            {
                cout<<"Rastan is in Persia now."<<endl;
            }
            cout << endl<< endl;
            cout<<"Stats:"<<endl;
            cout << "\nRastan has spent " << days <<" alone!"<< endl;
            cout << "Health: " << health << endl;
            cout << "Food supply remaining for " << supply<< "days" << endl;
            cout << "Arrows remaining: " << ArrowS << endl;
        }
    }
    while(alive==true);

}

int main()
{
    game();
}
