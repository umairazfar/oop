#ifndef DERIVED2_H
#define DERIVED2_H
#include "Derived1.h"

class Derived2 : public Derived1
{
    public:
        Derived2();
        virtual void PrintDerived2() = 0;


};

#endif // DERIVED2_H
