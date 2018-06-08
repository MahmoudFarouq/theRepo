#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;
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
	int n = 10001 ;
	int curPrime = 0;
	while(n){
		curPrime = findNextPrime(curPrime);
		n--;
	}
	cout << curPrime << endl;
	
}


