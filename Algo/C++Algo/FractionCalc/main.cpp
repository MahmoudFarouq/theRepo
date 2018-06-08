#include <iostream>
#include "Fraction.h"
#include "FractionCalculator.h"
#include <map>
using namespace std;


int main()
{
    string name;
    cout << "Please Enter Your Name: ";
    cin >> name;
    FractionCalculator fc(name);
    return 0;
}
