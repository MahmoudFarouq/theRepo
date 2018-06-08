#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void print_square(int i)
{
    cout << i*i << " ";
}
string Binary_Decimal(int dec)
{
    string x = "";
    while(dec != 0)
    {
        if(dec%2 == 0)
            x += "0";
        else
            x += "1";
        dec /= 2;
    }
    return x;
}
int Decimal_Binary(string bin)
{
    int x = 0;
    int len = bin.length();
    for(int i = len-1; i >= 0; i--)
    {
        if(bin[i] == '1')
            x += pow(2, i);
    }
    return x;
}

int main()
{
    int ary[]={1,2,3,4,5};
    for_each(ary,ary+5,print_square);
    cout << Decimal_Binary(Binary_Decimal(15)) << endl;
    return 0;
}
