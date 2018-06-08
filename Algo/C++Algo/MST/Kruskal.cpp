#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
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
            parent[i] = parent[parent[i]];
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

struct Edge{
	int u, v, w;
};

bool IsBeforeEdge(Edge& a, Edge& b)
{
	return a.w<b.w;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class Type>
void Merge(Type* array, long long n, bool (*IsBefore)(Type &a, Type &b)){
	Type* aux = new Type[n];
    for(long long i = 0; i < n; i++) {aux[i] = array[i];}

    long long leftIndex = 0;
    long long rightIndex= n/2;
    long long k = 0;

    while( leftIndex < n/2 && rightIndex < n )
    {
        if( IsBefore(aux[leftIndex], aux[rightIndex])){
            array [k++] = aux [leftIndex++];
        }
        else{
            array[k++] = aux[rightIndex++];
        }
    }
    while (leftIndex < n/2){
        array [k++] = aux [leftIndex++];
    }
    while (rightIndex < n){
        array[k++] = aux[rightIndex++];
    }
}

template<class Type>
void MergeSort(Type* a, long long n, bool (*IsBefore)(Type &a, Type &b)){
    if (n > 1) {
        int mid = n/2;
        MergeSort (a, mid, IsBefore);
        MergeSort (a+mid, n-mid, IsBefore);
        Merge (a, n, IsBefore);
    }
}

///////////////////////////////////////////////////////////////////////////

int main()
{
    long long m, n;
    while(cin >> m >> n){
        if(m ==0 && n == 0)  break;
        int wholeCost = 0, newCost = 0;
        Edge edges[n];
        for(int i = 0; i < n; i++){
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
            wholeCost += edges[i].w;
        }
        MergeSort(edges, n-1, IsBeforeEdge);
        //sort(edges, edges+n, IsBeforeEdge);
        DisjointSets ds; ds.Initialize(n+1);

        int selected = m - 1;
        for(int i = 0; i < n && selected; i++){
            if( ds.Union(edges[i].u, edges[i].v) ){
                newCost += edges[i].w;
                selected--;
            }
        }
        cout << wholeCost - newCost << endl;
        ds.Destroy();
    }
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
7  11
0  1  7
0  3  5
1  2  8
1  3  9
1  4  7
2  4  5
3  4  15
3  5  6
4  5  8
4  6  9
5  6  11
0  0
*/
