// GROUP:   4
// ID:      20150239
// Assign:  06
// Assign:  Prim
// UVA:     534
// Name1:   mahmoud reda farouk
// UVA Username: mahmoudFarouk

#include <stdio.h>
#include <limits.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int VERTICES_COUNT = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class Value>
struct Array
{
	int  n, sz;
	Value* arr;

	void Initialize(int n = 20){
		arr = new Value[n];
		sz = 0;
		this->n = n;
	}
	void Destroy(){
		delete arr;
	}
	void AddLast(Value v){
		if(sz == n)
			return;
		arr[sz++] = v;
	}
	void RemoveLast(){
		if(sz == 0)
			return;
		sz--;
	}
	Value& operator[](int i){
		if(i >= sz){
			throw "IndexOutOfBounds";
		}
		return arr[i];
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Edge
{
	int		v;  // id of the adjacent node
	double	w;  // edge weight = distance between the two nodes
};

struct Node
{
	Array<double> adj;
	void Initialize(int n){
		adj.Initialize(n);
	}
	void Destroy(){
		adj.Destroy();
	}
	double& operator[](int x){
        return adj[x];
	}
};

struct Graph
{
	int n;
	Node* nodes;

	void Initialize(int _n){
		n = _n;
		nodes = new Node[n];
		for(int i = 0; i < n; i++){
            nodes[i].Initialize(n);
		}
	}
	void Destroy(){
		for(int i = 0; i < n; i++){
			nodes[i].Destroy();
		}
		delete nodes;
	}
	Node& operator[](int x){
        return nodes[x];
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////
double Sqrt(double v, int n=100){
    double lo = 0, hi = v, mid;
    for(int i = 0 ; i < n ; i++){
    mid = (lo+hi)/2;
    if(mid*mid == v) return mid;
        if(mid*mid > v){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    return mid;
}

double Power(int x){
    return x*x;
}
double distance(int xs, int xe, int ys, int ye){
    return Sqrt( Power(xs-xe) + Power(ys-ye) );
}

int minWeight(Edge *edges, bool set[]){
	double min = INT_MAX, minIndex;
	for (int v = 0; v < VERTICES_COUNT; v++){
		if (!set[v] && edges[v].w < min){
			min = edges[v].w;
			minIndex = v;
		}
	}
	return minIndex;
}

static void Prim(int &cases, Graph graph)
{
	Edge *edges = new Edge[VERTICES_COUNT];
	bool *mstSet= new bool[VERTICES_COUNT]{false};
	for(int i = 0; i < VERTICES_COUNT; i++) edges[i].w = INT_MAX;
	edges[0].w = 0;
	edges[0].v = -1;

	for (int _ = 0; _ < VERTICES_COUNT; _++){
		int u = minWeight(edges, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < VERTICES_COUNT; v++){
			if (graph[u][v] && !mstSet[v] && graph[u][v] < edges[v].w){
				edges[v].v = u;
				edges[v].w = graph[u][v];
			}
		}
	}
	double max = 0;
	int fionnaIndex = 1;
	while(fionnaIndex != 0){
        if(edges[fionnaIndex].w > max){
            max = edges[fionnaIndex].w;
        }
        fionnaIndex = edges[fionnaIndex].v;
	}
	printf("Scenario #%d\n", cases++);
	printf("Frog Distance = %0.3f\n\n", max);
}
int main()
{
    int n;
    int cases = 1;
    while(cin >> n && n){
        VERTICES_COUNT = n;
        int *x = new int[n];
        int *y = new int[n];
        for ( int i = 0; i < n; i++ ) cin >> x[i] >> y[i];
        Graph g; g.Initialize(n);
        for(int i = 0; i < n; i++){
            g.nodes[i].adj.sz = n;
            for(int j = 0; j < n; j++){
                g[i][j] = distance(x[i], x[j], y[i], y[j]);
            }
        }
        Prim(cases, g);
        delete x; delete y;
        g.Destroy();
    }
	return 0;
}
