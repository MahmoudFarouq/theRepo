#include <iostream>

using namespace std;

int CollatzConjecture(int n, int counter = 0){
	if(n == 1)
		return counter;
	if(n%2 == 0)
		return CollatzConjecture(n/2, counter+1);
	return CollatzConjecture(3*n+1, counter+1);
}

int main()
{
	
	cout<< CollatzConjecture(50) << endl;
	
	
}
