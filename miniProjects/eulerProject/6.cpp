#include <iostream>
using namespace std;
int main()
{
	
	int nth = 100;
	
	int sumOfSquares = 0;
	int squareOfSum = 0;
	for(int i = 1; i <= nth; i++){
		sumOfSquares += i*i;
		squareOfSum += i;
	}
	squareOfSum *= squareOfSum;
	
	cout << squareOfSum - sumOfSquares << endl;
	
	/*
	int n = 100;
	int squareOfSum = (n*(n+1)/2)*(n*(n+1)/2);
	int sumOfSquares = n * (n+1) * (2*n+1) * 1/6;
	cout << squareOfSum - sumOfSquares << endl;
	*/
	
}

