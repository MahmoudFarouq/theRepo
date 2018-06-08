#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cmath>
using namespace std;
class Fraction
{
private:
    int Dumenator; //mqam
    int Numerator; //bast
    float RealValue = 0;
public:
    Fraction();
    Fraction(int n, int d);
    int getDumenator();
    int getNumerator();
    float getRealValue();
    void setDumenator(int D);
    void setNumerator(int N);
    void setRealValue(float R);
    Fraction& operator+(Fraction& second);
    Fraction& operator-(Fraction& second);
    Fraction& operator*(Fraction& second);
    Fraction& operator/(Fraction& second);
    bool operator==(Fraction& second);
    bool operator!=(Fraction& second);
    bool operator>=(Fraction& second);
    bool operator<=(Fraction& second);
    bool operator>(Fraction& second);
    bool operator<(Fraction& second);
    void Normalize();
    friend ostream& operator << (ostream& out, Fraction& b);
    friend istream& operator >> (istream& in, Fraction& b);
    static int ToInt(string x);
    int gcd(int a, int b);
};


#endif // FRACTION_H
