#include <iostream>

using namespace std;

int fibonacci_rec(int n);
int fibonacci_dp(int n);

int main()
{
	int n;
	cin >> n;
    cout << fibonacci(n);
}

int fibonacci_rec(int n)
{
    if (n == 0 || n == 1){
        return 1;
    } else {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

int fibonacci_dp(int n)
{
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2; i <= n; i++)
    {
    	arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n+1];
}