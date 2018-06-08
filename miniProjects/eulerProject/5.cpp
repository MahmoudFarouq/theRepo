#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

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

void PrimeFactorization(int n, vector<int>& vec){
	if (n <= 1 || isPrime(n)) {vec.push_back(n); return;}
	while(!isPrime(n)){
		int factor = 2;
		while(true){
			if(n % factor == 0){vec.push_back(factor); n /= factor; break;}
			else
				factor = findNextPrime(factor);
		}
	}
	vec.push_back(n);
}

int main()
{
	int nth = 20;
	vector<int> array[nth+1];
	
	for(int i = 1; i <= nth; i++){
		PrimeFactorization(i, array[i]);
	}
	
	for(int i = 1; i <= nth; i++){
		copy(array[i].begin(), array[i].end(), ostream_iterator<int>(cout, " "));
		printf("\n");
	}
	
	int result = 1;
	for(int i = 1; i <= nth; i++){
		
		int m = 0;
		for(int j = 1; j <= nth; j++){
			vector<int> vec = array[j];
			int c = count(&vec[0], &vec[vec.size()], i);
			if(c > m ) m = c;
		}
		//cout << i << " appears " << m << endl;
		result *= (m == 0 ? 1:pow(i, m));
	}
	cout << result << endl;
}

