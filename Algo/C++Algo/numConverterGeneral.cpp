#include <iostream>
#include <cmath>
using namespace std;
string toCapital(string x);
string DecimalTo(int x, int rem);
int ToDecimal(string x, int dev);
int main()
{
	int input;
	string output;
	string num;
	int to,from;
	cout << "Enter the base you want to convert from and the base you want to convert to \n(\"separated by space\"): ";
	cin >> from >> to;
	cout << "Enter the number: ";
	cin >> num;
	num = toCapital(num);
    input = ToDecimal(num, from);
	output = DecimalTo(input, to);
	cout << "You Entered: " << num << "\n" << "After Conversion: " << output << endl;
}
string toCapital(string x)
{
    for(int i = 0; i < x.length(); i++){x[i] = toupper(x[i]);}return x;
}
string DecimalTo(int x, int rem)
{
	int len=0;
	int rem_ = rem;
	int x_ = x;
	while(x_ > 0){x_ /= rem_;len++;}
	char array[len];
	int i = 0;
	while(x > 0)
	{
		int z = (x%rem);
		char c = (char)(z+48);
		if(z >= 10){c = (char) z+55;}
		array[len-i-1] = c;
		x /= rem;
		i++;
	}
	array[len] = '\0';
	return array;
}
int ToDecimal(string x, int dev)
{
	int len = x.length();
	int result = 0;
	for(int i = len-1; i >= 0; i--)
	{
	    if((int)x[i]-48 < 10){result += pow(dev, len-1-i) * ((int)x[i]-48);}
        else{result += pow(dev, len-1-i) * ((int)x[i] - 55);}
	}
	return result;
}
