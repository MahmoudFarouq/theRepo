//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

#include <iostream>

using namespace std;

void SieveOfEratosthenes(int n)
{
	//create the so called table
	bool *table = new bool[n];
	
	//assign all it's values to true
	for(int i = 0; i < n; i++)
		table[i] = true;
	
	//go through all values starting from 2(the first prime num), if it's true,
	//make all it's multypliers false, so there is no any num dividable by 2 int  the table;
	for(int i = 2; i < n/2; i++){
		if(table[i]){
			for(int j = 2; j*i < n; j++){
				table[j*i] = false;
			}
		}
	}
	
	for(int i = 2; i < n; i++)
		if(table[i])
			cout << i << " ";
}


int main()
{
	
	int n;
	cin >> n;
	
	SieveOfEratosthenes(n);
}
