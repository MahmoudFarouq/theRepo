#include <iostream>
#include <math.h>

using namespace std;

void DecimalTo(int n, int base = 2){
	
	if(n == 0) return;
	DecimalTo(n/base, base);
	cout << (n%base == 0 ? 0:n%base);
}

void ToDecimal(string x, int dev = 2)
{
	int len = x.length();
	int result = 0;
	for(int i = len-1; i >= 0; i--)
	{
		result += pow(dev, len-1-i) * ((int)x[i]-48);
	}
	cout << result << endl;
}

int main()
{	
	cout << "1) toBinary -------- 2) toDecimal" << endl;
	int _;
	cin >> _;
	
	switch(_){
		
		case 1:
			{int bin; cin >> bin;
			DecimalTo(bin);	break;}
		case 2:
			{string dec;
			cin >> dec;
			ToDecimal(dec); 
			break;}
		default:
			{cout << "wrong Input" << endl; break;}
	}
	
}
