#include <iostream>
#include<stdlib.h>//For random numbers
#include<time.h>

using namespace std;
void chance(int &, int &, int &, int &, int &,int &);
void circumstances(int &, int &, int &, int &, int &, int &);
void moveforward(int &, int &, int &, int &, int &, int &);
void hiddenchest(int &, int &, int &, int &, int &, int & );
void bandit(int &, int &, int &, int &, int &, int &);

int main()
{
    int day = 0;                                             // initilization of the variable day.
    int supply = 10;                                         // initilization of the variable supply.
    int arrow = 0;                                           // initilization of the variable arrow.
    int bow= 0;                                              // initilization of the variable bow.
    int health = 20;                                         // initilization of the variable health.
    int caravan = 0;                                         // initilization of the variable caravan.
    chance(supply,arrow,bow,health,caravan,day);             // The function chance is called, which takes in six arguements.
    return 0;
}

void chance(int & supply, int & arrow, int & bow, int & health, int & caravan, int & day)    //chance function, which asks the user to tell whether to give up or move forward.
{
    cout<<"Report:"<<endl;//day report
    cout<<"Food count:"<<supply<<endl;  //report of each things, on the start of day.
    cout<<"Days:"<<day<<endl;
    cout<<"health:"<<health<<endl;
    cout<<"The number of bows :"<<bow<<endl;
    cout<<"no_of_arrows = "<< arrow<<endl;
    cout<<"Tracks found: "<<caravan<<" times"<<endl;

    srand (time(NULL));                                                                                 //random number is generated.
    cout<<"do you want to move forward or give up. type 1 for forward and type 0 for give up"<<endl;    //output is showed, which ask the user either to type 1 or 0.
    int option = 0;                                                                                     //initilization of the variable option.
    cin >> option;                                                                                      //input from the user is taken, and stored in option variable.
    if (option == 0)                                                                                    //condition is applied, whether to check what the user has typed.
    {
        cout << "Give up" << endl;                                                                      //output is generated.
        srand (time(NULL));                                                                             //random number is generated.
        int Death = 0;                                                                                  //initilization of the variable Death.
        Death = rand() % 5;                                                                             //4 random numbers are generated.
        cout << Death << endl;
        if (Death == 0)                                                                                 //at each random number there is a different cause of death.
        {
            cout << "Died due to starvation" << endl;
        }
        else if (Death == 1)
        {
            cout << "Died due to disease" << endl;
        }
        else if (Death == 2)

            cout << "Died due to dehydration" << endl;
        }
        else if (Death == 3)
        {
            cout << "Died due to avada kedabra" << endl;
        }
        else if (Death == 4)
        {
            cout << "Died due to snake bite" << endl;
        }

    }
    else if (option == 1)                                                                    //if the number 1 is typed it moves forward, and the function circumstances is called.
    {
        circumstances(supply, arrow, bow, health, caravan, day);
    }
}
void moveforward(int & supply, int & arrow, int & bow, int & health, int & caravan, int & day)  //move forward function takes in 6 reference variable as an arguement.
{
    day = day + 1;                                                                               //day is incremented here, after each turn.
    cout << "Day = " << day << endl;                                                             //current day is outputed.
    srand (time(NULL));                                                                           //random number is generated.
    supply = supply - 1;                                                                          //supply is decremented at each turn.
    cout << "supply consumed, your supply left is = " << supply << endl;                          //remaining supply is outputed.

    //cout<<"food:"<<supply<<endl;
    int Awards = 0;                               // initilization of the variable Awards.
    Awards = rand() % 5;                          //random number generated is stored in a variable.
    if (Awards == 0)                              //each random number, has a different condition.
    {
        cout << "Found supply" << endl;
        supply = supply + 5;                      //supply is incremented.
        cout << "your new supply is = " << supply << endl; //remaining supply is outputed.

        //cout<<"repl:"<<supply<<endl;
        chance(supply, arrow, bow, health, caravan, day); //function chance is called after condition 1 finishes.
    }

    else if (Awards == 1)
    {
        cout << "Found Hidden chest" << endl;
        hiddenchest(supply,arrow,bow,health,caravan,day); //in second condition function hidden chest is called.
        chance(supply, arrow, bow, health, caravan, day); //than function chance is called.
    }
    else if (Awards == 2)
    {
        cout << "3 bandits ahead" << endl;
        bandit(supply, arrow, bow, health, caravan, day); //in third condition function bandit is called.
        chance(supply, arrow, bow, health, caravan, day); //than function chance is called.
    }
    else if (Awards == 3)
    {
        cout << "Time to heal" << endl;
        health = 20;                         //in fourth condition, the health is rest to default which is equal to 20.
        cout << "your new health is = " << health << endl; //health is outputed.
        chance(supply, arrow, bow, health, caravan, day); //function chance is called.
    }
    else if (Awards == 4)
    {
        caravan = caravan + 1;                                                 //in fifth condition, caravan is incremented.
        cout << "you found the tracks, Tracks found = " << caravan << endl;
        if (caravan < 6)
        {
            //a condition is applied that if he finds caravan 6 times than he reaches Persia, or he will move forward or give up until he finds caravan 6 times.
            chance(supply, arrow, bow, health, caravan, day); //function chance is called.
        }
        else
        {
            cout << "You are in Persia, congratulations" << endl; //game finishes, and this is outputed.
        }
    }

}
void hiddenchest(int & supply, int & arrow, int & bow, int & health, int & caravan, int & day)  //hidden chest function takes in six reference variables as an arguement.
{
    srand (time(NULL));                                                   //random number is generated.
    int weapon = 0;                                                      // initilization of the variable weapon.
    weapon = rand() % 3;                                                 //random numbers are generated, and stored in a variable, each number applies to a different condition.
    if (weapon == 0)                                                     //condition applied here.
    {
        srand (time(NULL));                                              //random number is generated.
        int sum = 0;                                           //initialization of sum.
        sum = rand() % 5 + 5;                    //arrows can range from 5 to 10.
        arrow = arrow + sum;                     //first condition increments arrow.
        cout << "arrow found, arrow = " << arrow << endl;                //number of arrows are outputed.
    }
    else if (weapon == 1)
    {
        bow = bow + 1;                                                   //in second condition number of bows is incremented.
        cout << "bow found, bow = " << bow << endl;                      //number of bows are outputed.
    }
    else if (weapon == 2)
    {
        cout << "nothing found" << endl;                                 //in third condition, nothing is found, and that is outputed.
    }
}

void bandit( int & supply, int & arrow, int & bow, int & health, int & caravan, int & day )  //bandit function takes in six reference variable as an in put.
{
    int enemy = 3;                // initilization of the variable enemy.
    if (arrow > 0 && bow > 0)                                //condition is applied if arrow and bow is greater than 0 than only it will use arrow as a weapon, or it will use dagger as a weapon.
    {
        cout << "You have arrow and bow" << endl;
        while(enemy != 0)                                     //a while loop is inserted so that the whole combat goes on until all the bandits are not dead.
        {
            cout << "Rastan is fighting with bandits" << endl;
            srand (time(NULL));         //random number is generated.
            int HitMiss = 0;            //initilization of the variable HitMiss.
            HitMiss = rand() % 20;                    //below different conditions is applied, each condition has a different output, if any number 0-13 is generated than Rastan will kill bandit, if any number is generated from 16-19 than Rastan will miss the bandit.
            if (HitMiss == 0 || HitMiss == 1 || HitMiss == 2 || HitMiss == 3 || HitMiss == 4 || HitMiss == 5 || HitMiss == 6 || HitMiss == 7 || HitMiss == 8 || HitMiss == 9 || HitMiss == 10 ||HitMiss == 11 || HitMiss == 12 || HitMiss == 13 || HitMiss == 14)  //15 numbers are there because the probability of hit is 75%.
            {
                cout << "Rastan kills 1 bandit" << endl;
                enemy = enemy - 1;             //enemy is decremented.
                cout << "Bandits remaining = " << enemy << endl;
                arrow = arrow - 1;             //arrow is also decremented.
                cout << "one arrow used in killing the bandit, remaining arrow = " << arrow <<endl;
            }
            else if (HitMiss == 15 || HitMiss == 16 || HitMiss == 17 || HitMiss == 18 || HitMiss == 19)  //if  these number come than Rastan will miss the bandit.
            {
                cout << "Rastan fails to kill bandit" << endl;
                arrow = arrow - 1;       //arrow is decremented.
                cout << "one arrow used in trying to kill the bandit, remaining arrow = " << arrow <<endl;
            }
            if (enemy != 0)                  //after rastan gets a chance, now bandits have turn to attack Rastan, they will only attack if bandit is greater than 0, condition applied here that if enemy is greater than 0, than only bandits are there to attack Rastan.
            {
                srand (time(NULL));          //random number is generated.
                int strike = 0;              //initilization of the variable strike.
                strike = rand() % 20;
                if (strike == 0 || strike ==  1 || strike ==  2 || strike ==  3 || strike ==  4 || strike ==  5 || strike ==  6)  // Bandits have 35% probability of hitting Rastan, if they hit Rastan health is decremented, if any of this random comes, than it will hit Rastan.
                {
                    cout << " Now Bandit attacks Rastan" << endl;
                    health = health - 1; //health is decremented in this condition.
                    cout << "Rastan loses one life, remaining health = " << health << endl; //remaining health is outputed.
                }
                else if (strike ==  7 || strike == 8 || strike ==  9 || strike ==  10 || strike ==  11 || strike ==  12 ||strike ==  13 || strike ==  14 ||strike ==  15 || strike ==  16 ||strike ==  17 || strike ==  18 || strike ==  19)  //Bandits have a probability of 65% of missing to hit Rastan, so thats why in this condition more probability is taken into consideration, that if any of this number comes it will miss Rastan.
                {
                    cout << "Bandit misses Rastan, Rastan survives" << endl;
                }
            }
            else
            {
                cout<< "all enemies dead" <<endl; //above we made a condition that if bandits are greater than 0 than only battle will take place, else enemy is dead will be outputed.
            }
        }
    }
    else
    {
        cout << "No arrow or no bow, time to use dagger" << endl; //now if he doesnt have arrow or bow, it will use dagger to kill its enemy.
        while(enemy != 0)                                         //same conditions will apply as when he had arrow and bow, but this time probability to kill with dagger is less. the loop will continue until all enemies are not dead.
        {
            cout << "Rastan is fighting with bandits" << endl;
            srand (time(NULL)); //random number is generated.
            int HitMiss2 = 0;   // initilization of the variable HitMiss2.
            HitMiss2 = rand() % 10;
            if (HitMiss2 == 0 || HitMiss2 == 1 || HitMiss2 == 2 || HitMiss2 == 3 )  // the probability to kill with dagger is 40%, so if any of these number come, he will kill the bandit.
            {
                cout << "Rastan kills 1 bandit" << endl;
                enemy = enemy - 1; //enemy is decremented.
                cout << "Bandits remaining = " << enemy << endl; //remaining bandits are outputed.


            }
            else if (HitMiss2 == 4 || HitMiss2 == 5 || HitMiss2 == 6 || HitMiss2 == 7 || HitMiss2 == 8 || HitMiss2 == 9)  //if these number come than he will miss the bandits, the probability of missing with dagger is 60%.
            {
                cout << "Rastan fails to kill bandit" << endl;
            }
            if (enemy != 0)   //condition is applied, that if enemy is not equal to zero the battle goes on, as the number of enemy is 0, the battle finishes.
            {
                srand (time(NULL)); //random number is generated.
                int strike2 = 0;     //initilization of the variable strike2.
                strike2 = rand() % 20;
                if (strike2 == 0 ||strike2 == 1 || strike2 == 2 || strike2 == 3 || strike2 == 4 || strike2 == 5 || strike2 == 6)  //Bandits have 35% probability of hitting Rastan, if they hit Rastan health is decremented, if any of this random comes, than it will hit Rastan.
                {
                    health = health - 1;
                    cout << "Bandit attack Rastan" << endl;
                    cout << "Rastan loses one life, remaining health = " << health << endl;
                }
                else if (strike2 ==  7 || strike2 == 8 || strike2 == 9 || strike2 == 10 || strike2 == 11 || strike2 == 12 || strike2 == 13 || strike2 == 14 || strike2 == 15 || strike2 == 16 || strike2 == 17 || strike2 == 18 || strike2 == 19)  //Bandits have a probability of 65% of missing to hit Rastan, so thats why in this condition more probability is taken into consideration, that if any of this number comes it will miss Rastan.
                {
                    cout << "Bandit misses Rastan, Rastan survives" << endl;
                }
            }
            else
            {
                cout<< "enemies dead" <<endl; //if enemy = 0, than the battle finishes.
            }
        }

    }


}
void circumstances(int & supply, int & arrow, int & bow, int & health, int & caravan, int & day)  //circumstances function takes in 6 reference variable as an input.
{
    if (supply > 0)                                                        //condition is applied that if supply is greater than zero.
    {
        if (health > 0)                                                    //and health is greater than zero.
        {
            moveforward(supply,arrow,bow,health,caravan,day);                 //than move forward function is called.
        }
        else
        {
            cout<< "No life left is Rastan, he is dead." <<endl;              //else Rastan dies because of no life or Rastan dies because he is out of food.
        }
    }
    else
    {
        cout<< "Out of supply, Rastan is dead." <<endl;
    }
}





