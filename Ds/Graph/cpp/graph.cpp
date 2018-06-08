#include <stdio.h>
#include <queue>
using namespace std; 

#define MAXV 1000					/* maximum number of vertices */

struct edgeNode{		 			/* edge node in an adjacency list graph */
	int y;							/* adjacency info */
	int weight;						/* edge weight, if weighted graph */
	edgeNode* next;					/* the next edge */
};

enum State{UnDiscovered, Discovered, Processed};	/* the states of each nodes on traversing the graph */

class AdjListGraph{
	edgeNode** nodes;			/* adj list nodes (array)*/ 
	int		*  degree;			/* how many edges are connected to this node? (array) */
	int 	   nVerticies;		/* #Verticies */
	int 	   nEdges;			/* #Edges */
	bool	   directed;		/* is it Directed */
	

	int *parent;
	State *state;	/* the state for every Node */
	int* entry;
	int* exit;
	
public:
	AdjListGraph(bool dir = false){		/* ctor */
		nodes  = new edgeNode*[MAXV+1]{nullptr};	/* initialize all with nulls*/
		degree = new int[MAXV+1]{0};				/* initialize all with'5 */
		nVerticies = 0;
		nEdges     = 0;
		directed   = dir;
		initializeGraph();
	}
	~AdjListGraph(){
		for(int i = 1; i <= nVerticies; i++)
			delete nodes[i];
		delete[] degree;
		delete[] parent;
		delete[] state;
		delete[] entry;
		delete[] exit;
	}
	void initializeGraph(){
		int i;			/* counter */
		int m; 			/* num of Edges */
		int x, y;		/* nodes x and y */
		scanf("%d %d", &nVerticies, &m);	/* get #verticies and edges */
		for (i = 1; i <= m; i++){	
			scanf("%d %d",&x,&y);			/* get connections */
			if((y > nVerticies || y < 1) || (x > nVerticies || x < 1)){
				printf("wrong Input\n");
				i--;
				continue;
			}else{
				printf("Done Inserting\n");
				insertEdge(x,y, directed);		/* insert Edges */
			}
		}
	}
	void insertEdge(int& x, int& y, bool directed){
		edgeNode* temp = new edgeNode{y, 0, nodes[x]};		/* new node with y the distination, 0 initial weight, nodes[x] the next */
		nodes[x] = temp;									/* replace with temp */
		degree[x]++;										/* increase the degree */
		if(!directed){										/* if undirected, connect y to x too */
			insertEdge(y, x, true);
		}else{
			nEdges++;										/* this line is executed one no matter dir or not */
		}
	}
	void printGraph(){
		int i;   						/* counter */
		edgeNode* p;					/* temp node */
		for(i = 1; i <= nVerticies; i++){
			printf("Vertix %d : ", i);
			p = nodes[i];
			while(p){
				printf("%d ", p->y);
				p = p->next;
			}
			printf("\n");
		}
	}
	
	void _BFS(int s){	 								/* s == start node, end node, parents array */
		state[s] = Discovered;							/* mark source as discovered */
		queue<int> Q;									/* the Queue holds the nodes that are dicovered but not yet processed */
		Q.push(s);										
		while(Q.size()){								/* while the queue is not empty, if empty then all nodes are processed */
			int u = Q.front(); Q.pop();					/* remove the first to process it */
			processVertixEarly(u);
			edgeNode* p;								/* temp node */
			p = nodes[u];
			while(p){									/* push all the children of u into the queue for processing */
				int temp = p->y;
				if(state[temp] == UnDiscovered){
					processEdge(u, temp);
					Q.push(temp);
					state[temp]  = Discovered;
					parent[temp] = u;
				}
				p = p->next;
			}
			processVertixLate(u);
			state[u] = Processed;
		}
		delete[] state;
	}
	void BFS(int start){	
		_BFS(start);
	}
	
	void DFS(int s){
		int time = 0;
		entry  = new int[nVerticies+1];
		exit   = new int[nVerticies+1];
		_DFS(s, time);
	}
	void _DFS(int u, int time){
		state[u] = Discovered;
		processVertixEarly(u);
		entry[u] = time;
		time++;

		edgeNode* p = nodes[u];						/* temp node */
		while(p){									/* push all the children of u into the queue for processing */
			int temp = p->y;
			processEdge(u, temp);
			if(state[temp] == UnDiscovered){
				parent[temp] = u;
				_DFS(temp, time);
			}
			p = p->next;
		}
		state[u] = Processed;
		exit[u]  = time;
		time++;
	}
	
	void findPath(int start, int end){
		parent = new int[nVerticies+1];
		state  = new State[nVerticies+1]; 	
		for(int i = 1; i <= nVerticies; i++){			/* mark all as UnDiscovered	*/
			state[i]  = UnDiscovered;
			parent[i] = -1;
		}
		
		DFS(start);
	
		int *path = new int[nVerticies+1];
		int counter = -1;
		while(end != -1){
			path[++counter] = end;
			end = parent[end];
		}
		for(int i = counter; i >= 0; i--)
			printf("% d -> ", path[i]);
	}	
	
	//TODO
	void processVertixEarly(int x){};
	void processVertixLate (int x){};
	void processEdge(int x, int y){};
};

int main(void)
{	
	AdjListGraph *n = new AdjListGraph();
	n->findPath(1, 4);
}
//6 7 1 5 1 6 1 2 5 4 4 3 3 2 2 5
