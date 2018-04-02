#include <iostream>
#include <fstream>


using namespace std;


int main()
{

    /*
    *   Task 1
    *   * write in a file
    */
    char const * filename = "dummy.txt";
    /*ofstream ofs;
// . . . ifs >> foo; // won’t succeed: no file opened for ifs
    ofs.open(filename,ios_base::out);
    ofs <<"Hello world";
// open file named name for reading
    ofs.close(); // close file
    */



    /*
    *   Task 2
    *   * read from a file
    */

    //ifstream ifs;
    ////ifs >> foo; // won’t succeed: no file opened for ifs
    //ifs.open(filename,ios_base::in); // open file named name for reading

    //int i=0;

    /*char c = '\0';
    while (! ifs.eof()) {
        ifs.get(c);
        cout <<c;
        i++;
    }
    cout << "read "<<i<<"characters from file"<<endl;
    */

    /*char line[100];
    i=0;
    while (! ifs.eof()) {
        ifs.getline(line, sizeof(line));
        cout <<line;
        i++;
    }
    cout << "read "<<i<<"lines from file"<<endl;
    */

    //ifs.close(); // close file

    cout << "Hello world!" << endl;
    return 0;
}
