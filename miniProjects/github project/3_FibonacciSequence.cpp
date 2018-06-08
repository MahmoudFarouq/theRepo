#include <iostream>

using namespace std;

void FibonacciSequence(int n)
{
	if(n <= 0) return;
	else if(n == 1){
		cout << 0 << endl;
	}else if(n == 2){
		cout << 0 << " " << 1 << endl;
	}else{
		unsigned long long *lst = new unsigned long long[n];
		lst[0] = 0; lst[1] = 1;
		
		for(int i = 2; i < n; i++){
			lst[i] = lst[i-1] + lst[i-2];
		}
		for(int i = 0; i < n; i++){
			cout << lst[i] << " ";
		}
	}
}



int main()
{
	int n;
	cin >> n;
	
	FibonacciSequence(n);
}
