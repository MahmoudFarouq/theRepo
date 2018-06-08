//https://www.mathsisfun.com/prime-factorization.html

#include <iostream>

using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i+=6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    return true;
}

int findNextPrime(int n){
	while(true){
		if(isPrime(++n))
			return n;
	}
}
int main()
{
	int counter = 1;
	int firstPrime = 2;
	int _;
	do{
		cout << "Prime " << counter++ << ": " << firstPrime << endl;
		cout << "1) next 		---------        2) stop" << endl;
		cin >> _;
		firstPrime = findNextPrime(firstPrime);
	}while(_ != 2);
	
}
