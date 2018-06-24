#include<iostream> //Similar to import command in Python
#include<stdio.h>
#include<stdlib.h> //For random numbers
#include<time.h>   //For generating a new random seed



using namespace std; //required for using cin and cout commands

void Rastan();                                   //calling the function
void combat(int*, int*, bool*, string*);         //calling the function

void Rastan()
{
    char choice;
    int food = 10;                               //declaring variables
    int health = 20;                             //declaring variables
    string weapon = "dagger";                    //declaring variables
    bool bow = false;                            //declaring variables
    int arrowCount = 0;                          //declaring variables
    int win = 0;                                 //declaring variables
    srand (time(NULL));                          //time operand to generate a random number
    cout<< "----------Welcome to Rastan way from Persia to Delhi----------"<< endl;
    while (win < 6 && health > 0 && food > 0)    //running a loop to check all the conditions are fulfilled to proceed
    {
        cout << "Enter choice? (y/n) ";
        cin >> choice;
        if (choice == 'y' || choice == 'n')                         //storing the input by the user in a variable
        {
            if (choice == 'n')
            {
                int option= rand() % 5;              //generating a random number to know about the cause of death
                win = 0;
                if (option == 0)
                {
                    cout<<"Death by stravation"<<endl;       //causes of death
                }
                if (option == 1)
                {
                    cout<< "Death by disease"<<endl;         //causes of death
                }
                if (option == 2)
                {
                    cout<< "Death by dehydration"<<endl;     //causes of death
                }
                if (option == 3)
                {
                    cout<< "Death by avada kavadera"<<endl;  //causes of death
                }
                if (option == 4)
                {
                    cout<< "Death by snake bite"<<endl;      //causes of death
                }
                health = 0;
            }
            else if(choice == 'y')
            {
                int option2= rand() % 5;                     //generating a random number

                food = food - 1;                             //a count maintained to deduct food on each day
                if (option2 == 0)
                {
                    cout<<"Food and water recieved"<<endl;
                    food= food + 5;                          //recieving food will increase it by 5
                    cout << "Food = " << food<<endl;
                }
                if (option2 == 1)
                {
                    cout<<"Hidden chest"<<endl;
                    int x = rand() % 2;                      //generating a random number either for having bow or arrow from chest

                    if (x == 0)
                    {
                        cout<<"Bow recieved"<<endl;
                        bow = true;                      //bow as bool operand
                    }
                    if (x == 1)
                    {
                        int arrows = (rand() % 6) + 5;       //generating a random number for number of arrows obtained from chest
                        cout<< arrows << " Arrows recieved "<<endl;
                        arrowCount = arrowCount + arrows;    //adding the number of arrows to the total
                        cout<< "Total Arrows = " << arrowCount << endl;
                    }



                }
                if (option2 == 2)
                {
                    cout<<"Bandits"<<endl;
                    combat(&health, &arrowCount, &bow, &weapon);     //calling the combat function when encountered with bandits
                    cout<< "Health reamining = " << health <<endl;

                }
                if (option2 == 3)
                {
                    cout<<"Healer recieved"<<endl;
                    health = 20;                                 //recieving healer with reset health to 20
                }
                if (option2 == 4)
                {
                    cout<<"Caravan"<<endl;
                    win = win + 1;                               //a count maintained to check the number of times he got the track

                }
            }
        }
        else
        {
            cout << "Retype the choice" <<endl;
        }
    }
    if (win == 6 && health > 0)                              //condition set to check for win
    {
        cout << " YOU WON " << endl;
    }
    if (health <= 0)                                        //condition set if health reduces
    {
        cout << "YOU LOST" << endl;
    }
    if (food == 0)                                         //condition set if run short of food
    {
        cout << "STARVATION" << endl;
        cout << "LOST" << endl;
    }
}
void combat(int* life, int* arrows, bool* bowPresent, string* currentWeapon)
{
    srand(time(NULL));                                    //generating a random number
    bool bandits[3] = {true, true, true};                 //using bandit as a bool
    if (*bowPresent == true && *arrows > 1)               //checking whether bow and arrow both is available
    {
        *currentWeapon = "Bow and Arrow";
    }
    else
    {
         cout << "using dagger" << endl;
    }
    while (bandits[0]==true || bandits[1]==true || bandits[2]==true)
    {
        for (int i = 0; i<3 ; i++)                        //running a loop for 3 bandits
        {
            if (bandits[i]==true)                         //checking if any of the bandit is alive
            {
                int x = rand()%100;                       //generating a random number for hit percentage
                if (*currentWeapon == "Bow and Arrow")
                {
                    cout << "using bow and arrow" << endl;
                    *arrows = *arrows - 1;                //reducing the number of arrows
                    if (x < 75)                   //condition to check if number is less than 75 so a hit and if not then a miss
                    {
                        bandits[i]= false;               //killing the bandit
                        cout << "bandit " << i+1 << " killed" << endl;
                    }
                    if (*arrows == 0)
                    {
                        *currentWeapon = "dagger";
                    }
            }
                else
                {

                    if (x < 40)                   //condition to check if number is less than 40 so a hit and if not then a miss
                    {
                        bandits[i]=false;         //killing the bandit
                        cout << "bandit " << i+1 << " killed" <<endl;
                    }
                }

            }
        }
        for (int i=0; i<3; i++)                   //running a loop for bandit attack
        {
            if (bandits[i]==true)                 //condition to check if bandit is alive
            {
                int x = rand()%100;               //generating a random number for bandit hit
                if (x < 35)             //condition to check if number is less than 35 so a hit by bandit and if not then a miss
                {
                    *life=*life - 1;              //reducing life by 1 if a hit
                    cout << "Bandit " << i+1 << " attacked" <<endl;
                    cout <<"Health remaining = " << *life  << endl;
                }
            }
        }
        if (*life<=0)                             //condition to check is the health falls to zero
        {
            cout << "Died" << endl;
            break;
        }
    }

}

int main()
{
    Rastan();                                    //calling the function
    return 0;
}
