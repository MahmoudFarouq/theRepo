#include <iostream>
#include <bitset>
#include "BigDecimalInt.h"
using namespace std;

int main()
{
    BigDecimalInt x("-1000000");
    BigDecimalInt y("-123456789");
    BigDecimalInt z;
    z = x - y;
    cout << z << endl;
    cout << -1000000 - -123456789 << endl;
    return 0;
}
