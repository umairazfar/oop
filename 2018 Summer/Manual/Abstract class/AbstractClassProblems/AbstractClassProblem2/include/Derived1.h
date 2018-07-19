#ifndef DERIVED1_H
#define DERIVED1_H
#include "Base.h"

class Derived1 : public Base
{
    public:
        Derived1();
        virtual void PrintDerived1() = 0;

    protected:

    private:
};

#endif // DERIVED1_H
