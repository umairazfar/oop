#include <iostream>
#include "Derived3.h"

Derived3::Derived3()
{
    std::cout << "Derived Object created" << std::endl;
}

void Derived3::PrintBase()
{
    std::cout << "I am also a base object" << std::endl;
}

void Derived3::PrintDerived1()
{
    std::cout << "I am also a derived1 object" << std::endl;
}

void Derived3::PrintDerived2()
{
    std::cout << "I am also a derived2 object" << std::endl;
}

void Derived3::PrintDerived3()
{
    std::cout << "I am a derived3 class and has defined all the functions" << std::endl;
    PrintBase();
    PrintDerived1();
    PrintDerived2();

}
