
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class person {
public:
    person(){}
    person(string n, string c, int d):name(n), cnic(c), yob(d){}

    int get_age(int cur_year){return cur_year-yob;}
    void print_info(){
        cout<<"name: "<<name<<endl;
        cout<<"cnic: "<<cnic<<endl;
        cout<<"dob:  "<<yob<<endl;
    }

    private:
    string name, cnic;
    int yob;  // year  of birth
};

class student : public person {

public:
    student(string n, string c, int d, string i, int gd):person(n,c,d),id(i), grad_date(gd){}
    void print_info(){cout<<"hello"<<endl;}
private:
    string id;
    int grad_date;
};

/*
 *  Task 1:
 *  a.  Move the classes person & student to their separate files and use them in main().
 *  b.  Modify the constructor of student so that it can be called with 1-5 arguments.
 *  c.  Rewrite the function print_info() in student to print all info about the student.
 *  d.  Write the calc_tax() for student class which says that students are exempted from tax.
 */

 /*
 *  Task 2:
 *  a.  Derive a class faculty from person. Add the attributes: joining date, salary, taxrate (default 10%),list of courses(3)
 *  b.  Modify the constructor and print info function accordingly.
 *  d.  Write the calc_tax() for faculty class which calculates and return the tax for the full year.
 */

 /*
 *  Task 3:
 *  a.  Derive a class staff from person. Add the attributes: joining date, salary, taxrate (default 15%)
 *  b.  Modify the constructor and print info function accordingly.
 *  d.  Write the calc_tax() for staff class which calculates and return the tax for the full year.
 */

 /*
 *  Task 4:
 *  a.  Derive a class manager from staff. Add the attributes: subordinates
 *  b.  Modify the constructor and print info function accordingly.
 */

  /*
 *  Task 5:
 *  a.  Derive a class program_director. Add the attributes: program, subordinates
 *  b.  Modify the constructor and print info function accordingly.
 */

  /*
 *  Task 6:
 *  a.  In main() access all the above objects via their pointers
 *  b.  In mian() copy derived class objects into base class objects and then use the result
 *  c.  In main() access the derived class objects via base-class pointers.
 *  d.  store different derived objects in one array and call their print_info()s in a loop
 */

int main(){

    person b("john", "00123",2000);
    student s("johnny", "000011", 1999, "st00012", 2020);
    person *p = &s;
    //s=b;
    p->person::print_info();
}
