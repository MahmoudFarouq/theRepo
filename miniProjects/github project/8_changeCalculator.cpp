#include <iostream>

using namespace std;

int main()
{
	float cost, money;
	cout << "The Cost: "; cin >> cost;
	cout << "The Money: "; cin >> money;
	
	float change = money-cost;
	float changeNum = change*100;
	
	
	cout << "The Change is: " << change << "$"   << endl;
	cout << "The Quarters are: " << changeNum/25 << "$" << endl;
	cout << "The Dimes are: " 	 << changeNum/10 << "$" << endl;
	cout << "The Nickles are: "  << changeNum/5  << "$" << endl;
	cout << "The Pennies are: "  << changeNum	 << "$" << endl;
	
}
