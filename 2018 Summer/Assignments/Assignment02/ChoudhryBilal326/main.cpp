/*
Habib University, Summer Semester 2018,
Object Oriented Programming & Design Methodologies(CS224),
Assignment # 02; Text Based Adventure Game.
Instructor: Dr. Umair Azfar Khan,
TA: Ahmed Ali(aa02190),
Choudhry Bilal Mazhar (cm00326)
*/

#include <iostream>
#include<stdio.h>
#include<time.h>
#include <stdlib.h>

using namespace std;

int health = 20;//initial & max health of rastan
int days = 1;//number of days the game is played starting from day 1
int food_supplies = 10;//initial gameplay food supply for Rastan
int tracks = 0;//initial number of found carvan tracks to Persia by Rastan
int arrows = 0;//initial number of arrows in Rastan's stock

bool bow = false;//availability of bow(bool is either true or false)

void movement(); // function defined later in the code; specified her due to other functions definitions in which this is called before and defined later.

void days_passed()//number of days in gameplay increment
{
    days = days +1;
}

void give_up()//function call when the user decides to give up playing the game
{
    string give_up[5] = {"Death by starvation!\n", "Death by disease!\n", "Death by dehydration!\n", "Death by avada kadavera!\n", "Death by snake bite!\n"};
    srand (time(NULL));
    int random1 = rand() % 5;
    cout << "\n\nRastan has decided to give up!" <<endl;
    cout << "\n" << give_up[random1] <<endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    cout << "                                                GAME OVER" <<endl;
    cout << "                                               YOU LOST!!!" <<endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    exit(0);
}

void food_add()//function called when Rastan comes accross food supplies
{
    food_supplies = food_supplies + 5;
    cout <<"\nFood supplies for 5 more days!" <<endl;
}

void food_left()//function to keep a track of Rastan's food supply
{
    food_supplies = food_supplies - 1;
    if (food_supplies == 0)
    {
        cout << "Rastan has run out of food supplies!" <<endl;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout << "                                                GAME OVER" <<endl;
        cout << "                                               YOU LOST!!!" <<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    	exit(0);
    }
}

void carvan_tracks()//function to keep a record of carvan tracks leading the way to Persia
{
    tracks = tracks + 1;
    cout << "\nCarvan Tracks = " << tracks <<endl;
    if(tracks==6)
    {
        cout << "\nRastan has reached Persia!" <<endl;
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout << "                                               GAME END" <<endl;
        cout << "                                              YOU WON!!!" <<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        exit(0);
    }
}

void healer()//function called when Rastan comes across a healer when moving in the forward direction
{
    health = 20;
    cout << "\nRastan's health restored!\nRastan's Health = 20" <<endl;
}

void health_status()//function called to keep a track of Rastan's health
{
	if (health==0)
    {
		cout << "\nRastan has run out of health!" <<endl;
        cout << "\nRastan Died!";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout << "                                                GAME OVER" <<endl;
        cout << "                                               YOU LOST!!!" <<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    	exit(0);
	}
}

void combat()//function to execute the combat between Rastan and the three bandits
{
    int enemies = 3;
    int hit_strength = 0;
	if ((bow == true) && (arrows > 0))
    {
        cout << "\nRastan's weapon: Bow and " << arrows << " Arrows!"<< endl;
        hit_strength = 75;
    }
	else
    {
        cout << "\nRastan's weapon: Dagger!" << endl;
        hit_strength = 40;
    }
    while (enemies > 0 || health > 0)
    {
	    for (int a = 0; a < enemies; a = a + 1)
	    {
	    	cout << "\nRastan's turn to attack." << endl;
		    if (hit_strength == 40)
		    {
		        string attempt[5] = {"Rastan hit an enemy!", "Rastan hit an enemy!", "Rastan missed!", "Rastan missed!", "Rastan missed!"};
		        srand (time(NULL));
		        int random4 = rand() % 5;
		        cout << "\n" << attempt[random4] << endl;
		    	if (random4 < 2)
		    	{
		    		enemies = enemies - 1;
		    	}
		    }
			if (hit_strength == 75)
			{
		        string attempt[4] = {"Rastan hit an enemy!", "Rastan hit an enemy!", "Rastan hit an enemy!", "Rastan missed!"};
		        srand (time(NULL));
		        int random4 = rand() % 4;
		        cout <<"\n" << attempt[random4]<< endl;
		        arrows = arrows -1;
		        cout << "\nRastan has " << arrows << " arrows left!"<< endl;
		     	if (random4 < 3)
		     	{
		        	enemies = enemies - 1 ;
		        }
		        if (arrows < 1)
		        {
		        	cout<< "Rastan is out of arrows!\n ---> Rastan's weapon is now a dagger!"<< endl;
		        	hit_strength = 40;
		        }

		    }
		    cout<< "\n - Enemies left: " << enemies << endl;
		}
		if (enemies == 0)
        {
			movement();
		}
		for (int b = 0; b < enemies; b = b + 1)
		{
			cout<< "\nEnemies turn to attack" << endl;
			string attempt[20] = {"Enemy hit Rastan!", "Enemy hit Rastan!", "Enemy hit Rastan!", "Enemy hit Rastan!", "Enemy hit Rastan!", "Enemy hit Rastan!", "Enemy hit Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!", "Enemy missed Rastan!"};
		    srand (time(NULL));
		    int random4 = rand() % 20;
		    cout <<"\n" << attempt[random4]<< endl;
		    if (random4 < 7)
		    {
		    	health = health - 1;
		    	health_status();
		    	cout << "Rastan's health: " << health << "/20." <<endl;
		    }
		}
	}
}

void treasure_chest()//function called when Rastan comes across treasure chest
{
	string chest[7] = {"Rastan found a bow!", "Rastan found 5 arrows!", "Rastan found 6 arrows!", "Rastan found 7 arrows!", "Rastan found 8 arrows!", "Rastan found 9 arrows!", "Rastan found 10 arrows!"};
    srand (time(NULL));
    int random2 = rand() % 7;
    cout << "\n" << chest[random2]<< endl;
    if (random2 == 0)
    {
    	bow = true;
    }
    if (random2 == 1)
    {
    	arrows = arrows + 5;
    }
    if (random2 == 2)
    {
    	arrows = arrows + 6;
    }
    if (random2 == 3)
    {
    	arrows = arrows + 7;
    }
    if (random2 == 4)
    {
    	arrows = arrows + 8;
    }
    if (random2 == 5)
    {
    	arrows = arrows + 9;
    }
    if (random2 == 6)
    {
    	arrows = arrows + 10;
    }
}

void move_forward()//function called when the user instructs Rastan to move forward
{
    string forward[5] = {"Rastan comes across food and water!", "Rastan comes across a hidden chest that contains a weapon or arrows!", "Rastan has crossed paths with 3 bandits!", "Rastan comes across a healer who heals him!", "Rastan comes across caravan tracks!"};
    srand (time(NULL));
    int random3 = rand() % 5;
    cout <<"\n" << forward[random3]<< endl;
    if (random3==0)
    {
        food_add();
    }
    if (random3==1)
    {
		treasure_chest();
    }
    if (random3==2)
    {
		combat();
    }
    if (random3==3)
    {
        healer();
    }
    if (random3==4)
    {
        carvan_tracks();
    }
}

void movement()
{
    cout << "\n                                     ***Rastan's Health: " << health << "/20***" << endl;
    cout << "                             ***Rastan's food supply will last for " << food_supplies << " days***" << endl;
    if (tracks>0)
    {
        cout << "                                    ***Carvan tracks found: " <<tracks << "***"<<endl;
    }
    cout << "\n                                                  |\n                                                  |\n                                                  V";
    cout << "\nx..................................................................................................x";
    cout << "                                                                    Day: "<< days;
    cout << "\nx..................................................................................................x" <<endl;
    cout << "\nEnter 'F' to move forward or 'G' to give up    --->    ";
    char userinput; // case sensitive
    cin >> userinput;
    if (userinput=='F')
    {
        cout << "\n\n\nRastan has consumed food supply for a day." << endl;
        days_passed();
        food_left();
        cout << "Enough food left for: " << food_supplies << " days." << endl;
        move_forward();
    }
    else if (userinput=='G')
    {
        give_up();
    }
    else
    {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout << "                                          INVALID INSTRUCTION!" <<endl;
        cout << "                                               TRY AGAIN!!!" <<endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" <<endl;
        movement();
    }
    cout << "\nx------------------------------------------------X------------------------------------------------x" <<endl;
    cout << "x------------------------------------------------X------------------------------------------------x" <<endl;
    if(health >> 0 || food_supplies >> 0);
    {
        movement();
    }
}

int main()
{
    cout << "                                           ADVENTURE GAME!\n"<< endl;
    cout << "\nPlot: \n\n'A young man Rastan was on his way to Persia from Delhi before he got separated from his caravan." <<endl;
    cout << "Armed only with a dagger, Rastan has nowhere to go except to move forward." <<endl;
    cout << "But his path is laden with awards and mischief. \nHe does not know what he will encounter across the next corner." <<endl;
    cout << "After a good nights rest, he chooses to move forward and brace himself for the things to come.'" << endl;
    cout << "\nRastan's Initial Status: Rastan's Health = 20, Food Supplies = 10 days, Carvan Tracks = 0" <<endl;
    cout << "\nx-------------------------------------------------X-------------------------------------------------x" <<endl;
    movement();
    return 0;
}