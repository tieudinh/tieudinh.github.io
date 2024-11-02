 #include <bits/stdc++.h>
using namespace std;

// Structure to represent a weighted
// edge in graph
struct Edge {
	int src, dest, weight;
};

// Structure to represent a directed
// and weighted graph
struct Graph {

	// V -> Number of vertices,
	// E -> Number of edges
	int V, E;

	// Graph is represented as an
	// array of edges
	struct Edge* edge;
};

// Creates a new graph with V vertices
// and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[graph->E];
	return graph;
}

vector<int> vis;
// Function runs Bellman-Ford algorithm
// and prints negative cycle(if present)
void NegCycleBellmanFord(struct Graph* graph,
						int src)
{
	int V = graph->V;
	int E = graph->E;
	int dist[V];
	int parent[V];

	// Initialize distances from src
	// to all other vertices as INFINITE
	// and all parent as -1
	for (int i = 0; i < V; i++) {

		dist[i] = INT_MAX;
		parent[i] = -1;
	}
	dist[src] = 0;
	vis[src] = 0;
	// Relax all edges |V| - 1 times.
	bool flg = true;
	for (int i = 1; i <= V - 1; i++) {
	if(flg==false)
			break;
	flg=false;
		for (int j = 0; j < E; j++) {

			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;

			if (dist[u] != INT_MAX
				&& dist[u] + weight < dist[v]) {
				flg = true;
				vis[v] = 1;
				dist[v] = dist[u] + weight;
				parent[v] = u;
			}
		}
	}

	// Check for negative-weight cycles
	int C = -1;
	for (int i = 0; i < E; i++) {

		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;

		if (dist[u] != INT_MAX
			&& dist[u] + weight < dist[v]) {

			// Store one of the vertex of
			// the negative weight cycle
			C = v;
			break;
		}
	}

	if (C != -1) {

		for (int i = 0; i < V; i++)
			C = parent[C];

		// To store the cycle vertex
		vector<int> cycle;
		for (int v = C;; v = parent[v]) {

			cycle.push_back(v);
			if (v == C
				&& cycle.size() > 1)
				break;
		}

		// Reverse cycle[]
		reverse(cycle.begin(), cycle.end());

		// Printing the negative cycle
		for (int v : cycle)
			cout << v << ' ';
		cout << endl;
	return;
	}
}

// Driver Code
int main()
{
	// Number of vertices in graph
	int V = 5;

	// Number of edges in graph
	int E = 5;

	struct Graph* graph = createGraph(V, E);
	vis.resize(V,0);
	// Given Graph
	graph->edge[0].src = 1;
	graph->edge[0].dest = 0;
	graph->edge[0].weight = 1;

	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	graph->edge[1].weight = 2;

	graph->edge[2].src = 2;
	graph->edge[2].dest = 3;
	graph->edge[2].weight = 3;

	graph->edge[3].src = 3;
	graph->edge[3].dest = 4;
	graph->edge[3].weight = -3;

	graph->edge[4].src = 4;
	graph->edge[4].dest = 1;
	graph->edge[4].weight = -3;

	graph->edge[5].src = 5;
	graph->edge[5].dest = 6;
	graph->edge[5].weight = -1;

	graph->edge[6].src = 6;
	graph->edge[6].dest = 7;
	graph->edge[6].weight =-1;

	graph->edge[7].src = 7;
	graph->edge[7].dest = 5;
	graph->edge[7].weight =-1;

	// Function Call
	for(int src = 0;src<V;src++)
	{
	if(vis[src]==0)
		NegCycleBellmanFord(graph, src);
	} 
		cout << "-1\n";
	return 0;
}
