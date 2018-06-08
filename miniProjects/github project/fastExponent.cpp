#include <iostream>
#include <math.h>
using namespace std;

string DecimalTo(int n){
	return (n == 0 ? "":DecimalTo(n/2) + (n%2 == 0 ? "0":"1"));
}

unsigned long long FastExponent(int a, int b)
{
	unsigned long long res = 1;
	string binary = DecimalTo(b);
	int len = binary.length();
	for(int i = len-1; i >= 0; i--){
		if(binary[i] == '1'){
			res *= pow(a, pow(2, len-1-i));
		}
	}
	return res;
}

int main()
{
	cout << FastExponent(10, 13) << endl;
}
