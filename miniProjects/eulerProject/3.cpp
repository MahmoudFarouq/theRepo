#include <iostream>
using namespace std;


bool isPrime(int n){
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

void PrimeFactorization(uint64_t n){
	if (n <= 1 || isPrime(n)) {cout << n << endl; return;}
	while(!isPrime(n)){
		int factor = 2;
		while(true){
			if(n % factor == 0){/*cout << factor << " ";*/ n /= factor; break;}
			else
				factor = findNextPrime(factor);
		}
	}
	cout << n << endl;
}
int main()
{
	uint64_t n;
	cin >> n;
	PrimeFactorization(n);
}

