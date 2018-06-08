#ifndef FRACTIONCALCULATOR_H
#define FRACTIONCALCULATOR_H
#include "Fraction.h"
#include <iostream>
using namespace std;

class FractionCalculator
{
    public:
        FractionCalculator(string n);
        virtual ~FractionCalculator();

        void Intro();
        void Calculate(int x);

    protected:

    private:
        string name;
        Fraction *ans;
};

#endif // FRACTIONCALCULATOR_H
