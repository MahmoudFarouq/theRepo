
#include <iostream>

using namespace std;

int main()
{
	uint64_t n = 28;
	int c = 0;
	for(uint64_t i = 1; i <= n; i++){
		if(n%i == 0){
			c++;
		}
	}
	cout << c << endl;
}
