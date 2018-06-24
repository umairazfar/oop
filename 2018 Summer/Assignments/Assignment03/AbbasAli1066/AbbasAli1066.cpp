#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Truck
{
    // Access specifier
    public:

      Truck()
    {

    }

    int litresPetrol = 50; // maximum storage of petrol for the truck
    double costPerliter = 2.73; // cost of petrol per liter
    int totalFunds;
    int emptyTruck; // km per liter when the truck is empty
    int fullTruck; //km per liter when the truck is loaded
    string name;
    int litresContain; // liters reserved in truck



    void CalculateLitres(){ // calculating the cost of the trip
        double totalRoute = (((60/emptyTruck)*costPerliter) + ((60/fullTruck)*costPerliter));
        cout<<"Total Cost of Litre "<<totalRoute<<endl;

    }


    void LoadTruck(){

        while(litresContain<50){
                if(totalFunds <= 0){
                    break;

                }
                totalFunds = totalFunds - costPerliter;
                litresContain++;

        }
        cout<<"Truck loaded to "<< litresContain<<endl;

    }


};

class Boxes{
    public:
    int length;
    int width;
    int height;

    Boxes(){
    }

    void VolumeSize(){
    int volume = length * width * height; // calculating the volume of box
    cout<<"Volume of box is "<< volume<<endl; //printing the volume of box

    }


};



int main()
{
  string line; // read data from file Drivers.txt and

  ifstream myfile ("Drivers.txt");
  int length = 0;

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      //cout << line << '\n';

      length++; // calculating the total lines in the file

    }

  }

  else cout << "Unable to open file";

    //cout<<aNumOfLines<<endl;
    cout << "Lines in file: " << length << std::endl;

    myfile.close();

    int entries = length / 5; // 5 lines for each entry so divided by 5 the total lines of file
    //cout<<entries<<endl;
    Truck *trucks = new Truck [entries]; // create truck object with total number of entries in the file

     ifstream myfile2 ("Drivers.txt"); // Now reading the file
    int counter = 0; // the counter is used to shift from one entry to another entry
    int entry = 0; // used for changing Truck object index
     if(myfile2.is_open()){
         while ( getline (myfile2,line) )
            {


              if(counter == 0){
                trucks[entry].name = line; // for saving the name of each entry
              }
              else if(counter ==1){
                trucks[entry].litresContain =  atoi(line.c_str()); // for saving the litresContain of each entry
              }
              else if(counter == 2){
                trucks[entry].totalFunds = atoi(line.c_str()); // for saving the total funds value of each entry
              }
              else if(counter  == 3){
                trucks[entry].emptyTruck = atoi(line.c_str()); // for saving the empty truck value of each entry
              }
              else if(counter == 4){
                trucks[entry].fullTruck = atoi(line.c_str()); // for saving the full truck value of each entry
                counter =-1; // it will set to -1 when one entry is completed
                 entry++; // increment the entry to to get the another index of object
              }

              counter++;



            }// while loop for reading file

     }
      double fullCost = 0;
      //fullCost = 60 + 60 * 2.73;

    //cout<<trucks[1].emptyTruck<<endl;

     myfile2.close();


      Boxes *box;
     for(int i=0; i<entry; i++){ // loop creating a random number of packages for each trucks
    int packageRange = rand() % 8 + 12; // random number of packages
    trucks[i].LoadTruck();
    trucks[i].CalculateLitres();

    box = new Boxes [packageRange]; //
    for(int j=0; j<packageRange; j++){
       int dimensionRangeLength = rand() % 30 + 5; //Getting random length range from 5 to 30
       int dimensionRangeWidth = rand() % 30 + 5; //Getting random width range from 5 to 30
       int dimensionRangeHeight = rand() % 30 + 5; // Getting random height from 5 to 30
       box[j].length = dimensionRangeLength; //
       box[j].height = dimensionRangeHeight;
       box[j].width = dimensionRangeWidth;

        box[j].VolumeSize();



        }//j loop ends here
         cout<<"--------------------"<<endl;

     }

     delete trucks;
     delete box;

    cout<<"---------------"<<endl;
    cout<<"Deallocated the array of boxes"<<endl;
    cout<<"---------------"<<endl;
    cout<<"Deallocated the array of truck"<<endl;




  return 0;
}


