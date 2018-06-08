#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;
string fun(string array[], int len, int value);
void func(string s);
int main() 
{
	int t;
	cin >> t;
	char* *dodo = new char*[t];
	for(int i = 0; i < t; i++)
	{
		int value;
		string array[2] = {"2", "3"};
		cin >> value;
		
		string a7a = fun(array, 2, value);
		dodo[i] = new char[a7a.length()+1];		
		
		for(unsigned j = 0; j < a7a.length(); j++)
		{
			dodo[i][j] = a7a[j];
		}
	}
	
	for(int i = 0; i < t; i++)
	{
		cout << dodo[i] << endl;
	}
}
string fun(string array[], int len, int value)
{
	if(value == 1) return "2";
	else if(value == 2) return "3";
	else
	{
		static int counter = 2;
		string* secArray = new string[len*2];
		int j = 0;
		for(int i = 0; i < len*2; i+=2)
		{
			secArray[i] = array[j];
			secArray[i+1] = array[j];
			j++;
		}
		for(int i = 0; i < len*2; i++)
		{
			if(i%2 == 0) secArray[i] += "2";
			else secArray[i] += "3";
		}
		if(len*2+counter > value)
		{
			value -= counter;
			return secArray[value-1];
		}
		else
		{
			counter+= len*2;
			return fun(secArray, len*2, value);
		}
	}
}
