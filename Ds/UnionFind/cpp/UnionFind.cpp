// GROUP:   4
// ID:      20150239
// Assign:  02
// Assign:  DisjointSets
// UVA:     10608
// Name:    Mahmoud reda farouk

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct DisjointSets
{
	int n;
	int* parent;
	int* num_nodes;

	void Initialize(int _n){
		n = _n;
		parent = new int[n];
		num_nodes = new int[n];
		for (int i = 0; i < n; i++) {
			parent [i] = i;
			num_nodes [i] = 1;
		}
	}
	void Destroy(){
		delete parent;
		delete num_nodes;
	}
	int Find(int i){
		while (i != parent [i]) {
			i = parent [i];
		}
		return i;
	}
	bool Union(int p, int q){
		int i = Find (p);
		int j = Find (q);
		if (i == j)
			return false;
		//find the maximum tree size and add the minimum to it, making a small trees
		if(num_nodes[i] > num_nodes[j])
			{parent [i] = j; num_nodes [j] += num_nodes [i];}
		else
			{parent [j] = i; num_nodes [i] += num_nodes [j];}
		return true;
	}
	int BiggestSize(){
		int sz = 0;
		for(int i = 0; i < n; i++){
			if(num_nodes[i] > sz){
				sz = num_nodes[i];
			}
		}
		return sz;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	int cases;
	cin >> cases;
	int* results = new int[cases];
	for(int i = 0; i < cases; i++){
		int n, m;
		cin >> n >> m;
		DisjointSets ds; ds.Initialize(n);
		for(int j = 0; j < m; j++){
			int a, b;
			cin >> a >> b;
			ds.Union(a, b);
		}
		results[i] = ds.BiggestSize();
		ds.Destroy();
	}
	for(int i = 0; i < cases; i++){
		cout << results[i] << endl;
	}
	delete results;
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
