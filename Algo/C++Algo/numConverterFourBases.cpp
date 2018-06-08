#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
using namespace std;
string decimal_to(int x, int rem);
int to_decimal(string x, int dev);
int main()
{
	int last1;
	string last2;
	string num;
	int to,from;
	cout << "1) Decimal \n2) Binary \n3) Octal\n4) HexaDecimal \n\nfrom .. to ..  ";
	cin >> from >> to;
	cout << "Enter the number: ";
	cin >> num;
	switch(from)
	{
		case 1: last1 = to_decimal(num, 10); break;
		case 2: last1 = to_decimal(num,  2); break;
		case 3: last1 = to_decimal(num,  8); break;
		case 4: last1 = to_decimal(num, 16); break;
	}
	switch(to)
	{
		case 1: last2 = decimal_to(last1, 10); break;
		case 2: last2 = decimal_to(last1,  2); break;
		case 3: last2 = decimal_to(last1,  8); break;
		case 4: last2 = decimal_to(last1, 16); break;
	}
	cout << "You Entered: " << num << "\n" << "After Conversion: " << last2 << endl;
}
string decimal_to(int x, int rem)
{
	int len=0;
	int rem_ = rem;
	int x_ = x;
	while(x_ > 0)
	{
		x_ /= rem_;
		len++;
	}
	char array[len];
	int i = 0;
	while(x > 0)
	{
		int z = (x%rem);
		char c = (char)(z+48);
		if(z >= 10)
		{
			switch (z)
			{
				case 10: c = 'A';break;
				case 11: c = 'B';break;
				case 12: c = 'C';break;
				case 13: c = 'D';break;
				case 14: c = 'E';break;
				case 15: c = 'F';break;
			}
		}
		array[len-i-1] = c;
		x /= rem;
		i++;
	}
	array[len] = '\0';
	return array;
}
int to_decimal(string x, int dev)
{
	int len = x.length();
	int result = 0;
	for(int i = len-1; i >= 0; i--)
	{
		switch (x[i])
		{
			case 'A': result += pow(dev, len-1-i) * (10);break;
			case 'B': result += pow(dev, len-1-i) * (11);break;
			case 'C': result += pow(dev, len-1-i) * (12);break;
			case 'D': result += pow(dev, len-1-i) * (13);break;
			case 'E': result += pow(dev, len-1-i) * (14);break;
			case 'F': result += pow(dev, len-1-i) * (15);break;
			default : result += pow(dev, len-1-i) * ((int)x[i]-48); break;
		}
	}
	return result;
}
