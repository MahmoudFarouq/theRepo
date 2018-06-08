#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H

#include <iostream>
using namespace std;

class BigDecimalInt
{
    public:
        BigDecimalInt(string v);
        BigDecimalInt();
        BigDecimalInt(BigDecimalInt& b);
        int size(){return value.length();}
        void GetComplement();
        void Simplify(BigDecimalInt& anotherDec, char opera);
        string getValue();
        string AddStrings(string first, string second);
        bool IsBigger (string first, string second);

        void setValue(string v);
        virtual ~BigDecimalInt();

        BigDecimalInt& operator- (BigDecimalInt& anotherDec);
        BigDecimalInt& operator= (BigDecimalInt& anotherDec);
        BigDecimalInt& operator+ (BigDecimalInt& anotherDec);
        friend ostream& operator << (ostream& out, BigDecimalInt& b);


    protected:

    private:
        string value;
        bool IsNeg = false;
        bool IsCompl = false;
};

#endif // BIGDECIMALINT_H
