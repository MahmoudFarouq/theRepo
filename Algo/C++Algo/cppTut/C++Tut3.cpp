#include <iostream>
#include <typeinfo>

using namespace std;

class Num{
public:

	int val = 0;
	//post-increment
	Num& operator++(){
		val++;
		return *this;
	}
	//pre-increment
	Num operator++(int){
		Num temp; temp.val = this->val;
		val++;
		return temp;
	}
};

template<class lhsT,typename rhsT>
auto sum(lhsT lhs, rhsT rhs) -> decltype(lhs+rhs) {
	return lhs+rhs;
}



typedef int(*fnc) (int x, int y);
int fun(int x, int y){
	return x*y;
}
int test(int x, int y, fnc fn){
	return fn(x, y);
}


int main(void)
{
	cout << sum(5, 4) << endl;
	cout << test(5, 6, fun) << endl;
	return 0;
}
