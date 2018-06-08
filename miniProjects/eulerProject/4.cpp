#include <iostream>
#include <sstream>
using namespace std;

bool isPalindrome(int n){
	string s = to_string(n);
	int len = s.length();
	for(int i = 0; i < len; i++){
		if( s[i] != s[len-i-1] )
			return false;
	}
	return true;
}

int main()
{
	int max = 0;
	int x = 999;	
	while(x){
		int y = 999;
		while(y){
			if(isPalindrome(x*y)){
				if(x*y > max) max = x*y;
			} y--;
		}x--;
	}
	cout << max << endl;
}

