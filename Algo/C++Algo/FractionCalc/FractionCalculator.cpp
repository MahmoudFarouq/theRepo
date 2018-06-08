#include "FractionCalculator.h"

FractionCalculator::FractionCalculator(string n)
{
    ans = new Fraction(0, 1);
    name = n;
    cout << "Hi \"" << name << "\"" << endl;
    cout << "This is A Fraction Calculator, Please Choose from The next Options."<< endl;
    Intro();
}
void FractionCalculator::Intro()
{
    int choose;
    cout << "1) Adding Fractions." << endl;
    cout << "2) Subtracting Fractions." << endl;
    cout << "3) Multiplying Fractions" << endl;
    cout << "4) Fractions Division " << endl;
    STARTING_POINT:
    cout << "You Choose: ";
    cin >> choose;
    switch(choose)
    {
        case 1: Calculate(1); break;
        case 2: Calculate(2); break;
        case 3: Calculate(3); break;
        case 4: Calculate(4); break;
        default:
            cout << "Wrong Input, Retry";
            goto STARTING_POINT;
            break;
    }
}
void FractionCalculator::Calculate(int x)
{
    Fraction f, s;
    cout << "Enter First Fraction (Num then Dum): (Press Enter to Apply the operation to The Previous Answer.)";
    cin >> f;
    if( f.getDumenator() == -1 && f.getNumerator() == -1 ) f = *ans;
    cout << "Enter Second Fraction (Num then Dum): ";
    cin >> s;
    if( s.getDumenator() == -1 && s.getNumerator() == -1 ) s = *ans;
    switch(x)
    {
        case 1: *ans = f + s; cout << "Adding "; break;
        case 2: *ans = f - s; cout << "Subtracting "; break;
        case 3: *ans = f * s; cout << "Multiplying "; break;
        case 4: *ans = f / s; cout << "Division "; break;
    }
    cout << "The Result for " << f << " and " << s << " is: " << *ans << endl;
    Intro();
}

FractionCalculator::~FractionCalculator()
{
    //dtor
}
