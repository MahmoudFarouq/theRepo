#include <iostream>
#include <map>
#include <vector>
#include <string> 
using namespace std;

map<string, string> myDic;
void SayPart(vector<string>& vec, string num, int index);
void Process(vector<string>& vec, string num);
string Solve(string num);
void PrepareAll();

int main()
{
	PrepareAll();
	int count = 0;
	for(int i = 1; i <= 1000; i++){
		string s = to_string(i);
		string text = Solve(s);
		cout << text << endl;
		int len = text.length();
		count += len;
	}
	cout << count << endl;
}



string Solve(string num){
	vector<string> vec;
	Process(vec, num);
	string res = "";
	for(unsigned i = 0; i < vec.size(); i++){
		res += vec[i];
	}
	return res;
}


bool hasOnlyZeroes(string s){
	
	for(int i = 0; i < 3; i++){
		if(s[i] != '0')
			return false;
	}
	return true;
}


void Process(vector<string>& vec, string num){
	
	int len = num.length();
	int numOfParts = len/3;
	int unCompletePart = len%3;
	
	if(unCompletePart != 0){
		SayPart(vec, num.substr( 0, unCompletePart ), numOfParts+1);
	}
	for(int i = numOfParts; i > 0; i--){
		SayPart(vec, num.substr( len-i*3, 3 ), i); 
	}
	
}

void SayPart(vector<string>& vec, string num, int index){
	
	if(hasOnlyZeroes(num)) return;
		
	string s = "";
	
	if(num.length() == 3){
		s = num[0];
		vec.push_back(myDic[ s ]);
		if(num[0] != '0'){
			vec.push_back(myDic["1h"]);
			if( num[1] != '0' || num[2] != '0' )
				vec.push_back("and");
		}
		if(num[1] == '1'){
			s = num[1]; s += num[2];
			vec.push_back(myDic[ s ]); 
		}else{
			s = num[1]; s += "0";
			vec.push_back(myDic[ s ]);
			s = num[2];
			vec.push_back(myDic[ s ]);
		}
	}else if(num.length() == 2){
		if(num[0] == '1'){
			s = num[0]; s += num[1];
			vec.push_back(myDic[ s ]); 
		}else{	
			s = num[0]; s += "0";
			vec.push_back(myDic[ s ]); 
				
			s = num[1];	
			vec.push_back(myDic[ s ]); 
		}	
	}else if(num.length() == 1){
		s = num[0];	
		vec.push_back(myDic[ s ]); 
	}
	
	switch (index){
		case 2:
			vec.push_back(myDic["1k"]); break;
		case 3:
			vec.push_back(myDic["1m"]); break;
		case 4:
			vec.push_back(myDic["1b"]); break;
		case 5:
			vec.push_back(myDic["1t"]); break;
		break;
	}
}


void PrepareAll(){
	myDic["1"] = "one";
	myDic["2"] = "two";
	myDic["3"] = "three";
	myDic["4"] = "four";
	myDic["5"] = "five";
	myDic["6"] = "six";
	myDic["7"] = "seven";
	myDic["8"] = "eight";
	myDic["9"] = "nine";
	myDic["10"] = "ten";
	myDic["11"] = "eleven";
	myDic["12"] = "twelve";
	myDic["13"] = "thirteen";
	myDic["14"] = "fourteen";
	myDic["15"] = "fifteen";
	myDic["16"] = "sixteen";
	myDic["17"] = "seventeen";
	myDic["18"] = "eighteen";
	myDic["19"] = "nineteen";

	myDic["20"] = "twenty";
	myDic["30"] = "thirty";
	myDic["40"] = "forty";
	myDic["50"] = "fifty";
	myDic["60"] = "sixty";
	myDic["70"] = "seventy";
	myDic["80"] = "eighty";
	myDic["90"] = "ninety";
	
	
	myDic["1h"] = "hundred";
	myDic["1k"] = "thousand";
	myDic["1m"] = "million";
	myDic["1b"] = "billion";
	myDic["1t"] = "trillion";	
}





