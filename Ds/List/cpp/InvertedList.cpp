#include <iostream>
#include <vector>
using namespace std;

struct Container
{
	string key;
	int goToIndex=-1;
};
int Search(vector<Container>& vec, string id);

int main()
{
	vector<string> names = {"mohamad", "ahmad", "mohamad", "mahmoud", "ahmad", "mohamad"};
	vector<string> ids = {"10","20","30","40","50", "60"};
	
	vector<Container> NamesList;
	vector<Container> InverList;
	int sz = 6;
	for(int i = 0; i < sz; i++)
	{
		int posInNames = Search(NamesList, names[i]);
		if(posInNames == -1)  //that name Doesnt Exist in NamesList
		{
			Container temp1, temp2;
			temp1.key = names[i]; temp1.goToIndex = InverList.size();		//to put in NamesList
			temp2.key = ids[i];	  temp2.goToIndex = -1;						//to put in InvList
			NamesList.push_back(temp1);
			InverList.push_back(temp2);
			
		}else{				//that name Exists in NamesList, find the last inserted id with the same name, and attach tne new one
			
			int posInInvList = NamesList[posInNames].goToIndex;  //THE First Occurance in INverted List
			
			while(InverList[posInInvList].goToIndex != -1){
				posInInvList = InverList[posInInvList].goToIndex;
				cout << "I'm Is The While Loop :p" << endl;
			}
			//NOW we have the index of the last Inserted element, note that posInInvList cant be -1, wont get to that
			InverList[posInInvList].goToIndex = InverList.size();
			Container temp; temp.key = ids[i]; temp.goToIndex = -1;
			InverList.push_back(temp);
		}
	}
	//to test
	cout << "Names" << endl;
	for(unsigned i = 0; i < NamesList.size(); i++)
	{
		cout << i << " --> " <<  NamesList[i].key << " -> " << NamesList[i].goToIndex << endl;
	}
	cout << "InvertedList" << endl;
	for(unsigned i = 0; i < InverList.size(); i++)
	{
		cout << i << " --> " <<  InverList[i].key << " -> " << InverList[i].goToIndex << endl;
	}
	
}

int Search(vector<Container>& vec, string name)
{
	int len = vec.size();
	for(int i = 0; i < len; i++){
		if(vec[i].key == name ) return i;
	}
	return -1;
}



