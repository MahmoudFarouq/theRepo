#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(string v)
{
    setValue(v);
}
BigDecimalInt::BigDecimalInt(BigDecimalInt& b)
{
    setValue(b.getValue());
}

BigDecimalInt::BigDecimalInt()
{
    value = "0";
}
void BigDecimalInt::setValue(string v)
{
    IsNeg = (v[0] == '-' ? true:false);
    int len = v.length();
    int start = (IsNeg == true? 1:0);
    for(int i = start; i < len; i++)
    {
        if((int)v[i] < 48 || (int)v[i] > 57)
        {
            value = "0";
            return;
        }
    }
    if(IsNeg == false) {value = v;}
    else{
        value = v.substr(1, v.length()-1);
    }
}

void BigDecimalInt::GetComplement()
{
    int len = value.length();
    for(int i = len-1; i >= 0; i--)
    {
        value[i] = (char)(9-((int)value[i]-48)+48);
    }
    value = AddStrings(value, "1");
    IsCompl = !IsCompl;
}

void BigDecimalInt::Simplify(BigDecimalInt& anotherDec, char opera)
{
    if(IsNeg)
    {
        GetComplement();
    }
    if(anotherDec.IsNeg)
    {
        anotherDec.GetComplement();
    }
    if(opera == '-')
    {
        anotherDec.GetComplement();
    }
}
string BigDecimalInt::AddStrings(string first, string second)
{
    string result = "";
    string bigValue = (IsBigger(first, second) ? first:second );
    string smallValue = (IsBigger(first, second) ? second:first );
    if(smallValue.length() != bigValue.length())
        while( smallValue.length() < bigValue.length() )
        {
            smallValue.insert(0, "0");
        }
    int len = smallValue.length()-1;
    int rem = 0;
    for(int i = len; i >= 0; i--)
    {
        int sum = ((int)smallValue[i]-48) + ((int)bigValue[i]-48);
        sum += rem;
        if(sum <= 9)
        {
            string c = "";
            c += (char) sum+48;
            result.insert(0, c);
            rem = 0;
        }
        else
        {
            string c = "";
            c += (char) sum%10+48;
            result.insert(0, c);
            rem = 1;
        }
    }
    if(rem != 0){
        string c = "";
        c += (char) rem+48;
        result.insert(0, c);
    }
    return result;
}

BigDecimalInt& BigDecimalInt::operator+ (BigDecimalInt& anotherDec)
{
    string bigValue = (IsBigger(value, anotherDec.getValue()) ? value:anotherDec.getValue() );
    string smallValue = (IsBigger(value, anotherDec.getValue()) ? anotherDec.getValue():value );
    while( smallValue.length() < bigValue.length() )
    {
        smallValue.insert(0, "0");
    }
    BigDecimalInt *res = new BigDecimalInt();
    Simplify(anotherDec, '+');
    string StrRes = AddStrings(value, anotherDec.getValue());
    if(!IsNeg && !anotherDec.IsNeg)
    {
        res->setValue(StrRes);
    }
    else if(IsNeg && !anotherDec.IsNeg)
    {
        GetComplement();
        if(IsBigger(value, anotherDec.getValue()))
        {
            res->setValue(StrRes);
        }
        else
        {
            if(StrRes.length() > bigValue.length())
                StrRes = StrRes.substr(1, bigValue.length());
            res->setValue(StrRes);
        }
    }
    else if(!IsNeg && anotherDec.IsNeg)
    {
        anotherDec.GetComplement();
        if(!IsBigger(value, anotherDec.getValue()))
        {
            value = StrRes;
            GetComplement();
            res->setValue(value);
            res->IsNeg = true;
        }
        else
        {
            anotherDec.setValue(StrRes);
            anotherDec.GetComplement();
            StrRes = anotherDec.getValue();
        }
    }
    else if(IsNeg && anotherDec.IsNeg)
    {
        value = StrRes;
        GetComplement();
        if(value.length() > bigValue.length())
                value = value.substr(1, bigValue.length());
        res->setValue(value);
        res->IsNeg = true;
    }
    return *res;
}
BigDecimalInt& BigDecimalInt::operator- (BigDecimalInt& anotherDec)
{
    string bigValue = (IsBigger(value, anotherDec.getValue()) ? value:anotherDec.getValue() );
    string smallValue = (IsBigger(value, anotherDec.getValue()) ? anotherDec.getValue():value );

    while( smallValue.length() < bigValue.length() )
    {
        smallValue.insert(0, "0");
    }
    BigDecimalInt *res = new BigDecimalInt();
    Simplify(anotherDec, '-');
    string StrRes = AddStrings(value, anotherDec.getValue());

    if(!IsNeg && !anotherDec.IsNeg)
    {

        anotherDec.GetComplement();
        if(!IsBigger(value, anotherDec.getValue()))
        {
            value = StrRes;
            GetComplement();
            res->setValue(value);
            res->IsNeg = true;
        }
        else
        {
            anotherDec.setValue(StrRes);
            anotherDec.GetComplement();
            StrRes = anotherDec.getValue();
        }
    }
    else if(IsNeg && !anotherDec.IsNeg)
    {
        value = StrRes;
        GetComplement();
        if(value.length() > bigValue.length())
                value = value.substr(1, bigValue.length());
        res->setValue(value);
        res->IsNeg = true;
    }
    else if(!IsNeg && anotherDec.IsNeg)
    {
        res->setValue(StrRes);
    }
    else if(IsNeg && anotherDec.IsNeg)
    {
        GetComplement();
        if(IsBigger(value, anotherDec.getValue()))
        {
            res->setValue(StrRes);
        }
        else
        {
            if(StrRes.length() > bigValue.length())
                StrRes = StrRes.substr(1, bigValue.length());
            res->setValue(StrRes);
        }
    }
    return *res;
}
bool BigDecimalInt::IsBigger (string first, string second)
{
    if(first.length() > second.length())
        return true;
    if(first.length() < second.length())
        return false;
    for(int i = 0; i < first.length(); i++)
    {
        if(first[i] > second[i])
            return true;
        if(first[i] < second[i])
            return false;
    }
}
string BigDecimalInt::getValue()
{
    return value;
}
BigDecimalInt& BigDecimalInt::operator= (BigDecimalInt& anotherDec)
{
    value = anotherDec.getValue();
    IsNeg = anotherDec.IsNeg;
    return *this;
}
ostream& operator << (ostream& out, BigDecimalInt& b)
{
    out << (b.IsNeg == true ? "-":"") << b.getValue();
    return out;
}
BigDecimalInt::~BigDecimalInt()
{

}
