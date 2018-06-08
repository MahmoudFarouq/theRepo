#include "Fraction.h"

Fraction::Fraction()
{
    Numerator = 0;
    Dumenator = 0;
}
Fraction::Fraction(int n, int d)
{
    Numerator = n;
    Dumenator = d;
    Normalize();
}
int Fraction::getDumenator(){return Dumenator;}
int Fraction::getNumerator(){return Numerator;}
float Fraction::getRealValue(){return RealValue;}
void Fraction::setDumenator(int D){Dumenator = D;}
void Fraction::setNumerator(int N){Numerator = N;}
void Fraction::setRealValue(float R){RealValue = R;}

Fraction& Fraction::operator+(Fraction& second)
{
    Fraction temp;
    temp.setNumerator( Numerator*second.getDumenator() + Dumenator*second.getNumerator() );
    temp.setDumenator( Dumenator * second.getDumenator() );
    temp.Normalize();
    return temp;
}
Fraction& Fraction::operator-(Fraction& second)
{
    Fraction temp;
    temp.setNumerator( Numerator*second.getDumenator() - Dumenator*second.getNumerator() );
    temp.setDumenator( Dumenator * second.getDumenator() );
    temp.Normalize();
    return temp;
}
Fraction& Fraction::operator*(Fraction& second)
{
    Fraction temp;
    temp.setNumerator( Numerator * second.getNumerator() );
    temp.setDumenator( Dumenator * second.getDumenator() );
    temp.Normalize();
    return temp;
}
Fraction& Fraction::operator/(Fraction& second)
{
    Fraction temp;
    temp.setNumerator( Numerator * second.getDumenator() );
    temp.setDumenator( Dumenator * second.getNumerator() );
    temp.Normalize();
    return temp;
}

bool Fraction::operator==(Fraction& second){ return (Numerator == second.getNumerator() && Dumenator == second.getDumenator()); }
bool Fraction::operator!=(Fraction& second){ return !(Numerator == second.getNumerator() && Dumenator == second.getDumenator()); }
bool Fraction::operator>=(Fraction& second){ return (RealValue >= second.getRealValue());}
bool Fraction::operator<=(Fraction& second){ return (RealValue <= second.getRealValue());}
bool Fraction::operator>(Fraction& second) { return (RealValue > second.getRealValue());}
bool Fraction::operator<(Fraction& second) { return (RealValue < second.getRealValue());}

void Fraction::Normalize()
{
    int divisor = gcd(Numerator, Dumenator);
    Numerator /= divisor;
    Dumenator /= divisor;
    RealValue = Numerator/Dumenator;
}
int Fraction::gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ostream& operator << (ostream& out, Fraction& b)
{
    out << b.getNumerator() << "/" << b.getDumenator();
}
istream& operator >> (istream& in, Fraction& b)
{
    string n, d;
    in >> n;
    if(n == "ans"){
        b.Dumenator = -1;
        b.Numerator = -1;
    }else{
        in >> d;
        b.Numerator = Fraction::ToInt(n);
        b.Dumenator = Fraction::ToInt(d);
    }
    return in;
}
int Fraction::ToInt(string x)
{
	int len = x.length();
	int result = 0;
	for(int i = 0; i < x.length(); i++)
	{
        result *= 10;
        result += (int) x[i] - 48;
	}
	return result;
}
