// http://www.practice.geeksforgeeks.org/problem-page.php?pid=1246

//nice problem


#include <iostream>
#include <cmath>
using namespace std;
long long product(long long array[], int len);
int findMin(long long array[], int len);
long long GCD(long long array[], int len);
long long getModulo(long long num);
int main() 
{
	int t;
	cin >> t;
	long long *array = new long long[t];
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		long long *secArray = new long long[n];
		for(int j = 0; j < n; j++)
		{
			cin >> secArray[j];
		}
		array[i] = getModulo(pow(product(secArray, n), GCD(secArray, n)));
	}
	for(int i = 0; i < t; i++)
	{
		cout << array[i] << endl;
	}
	
}


long long product(long long array[], int len)
{
	long long res = 1;
	for(int i = 0; i < len; i++)
	{
		res = getModulo(array[i]*res);
	}
	return res;
}

long long GCD(long long array[], int len)
{
	bool bol = true;
	int start = findMin(array, len);
	for(int i = start; i > 0; i--)
	{
		for(int j = 0; j < len; j++)
		{
			if(array[j]%i == 0) bol = true;
			else
			{
				bol = false;
				break;
			}
		}
		if(bol == true) return i;
	}
	
	return 0;
}

int findMin(long long array[], int len)
{
	int min = 10000000;
	for(int i = 0; i < len; i++)
	{
		min = (array[i] < min ? array[i]:min);
	}
	return min;
}

long long getModulo(long long num)
{
	return num%1000000007;
}


