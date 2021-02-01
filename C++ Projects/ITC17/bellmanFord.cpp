#include <bits/stdc++.h> 
using namespace std; 

void BellmanFord(vector<vector<int>> graph, int V, int E, int src) 
{ 
	int distance[V]; 
	for (int i = 0; i < V; i++) 
		distance[i] = INT_MAX; 

	distance[src] = 0; 
 
	for (int i = 0; i < V - 1; i++)
    { 
		for (int j = 0; j < E; j++)
        {
				distance[graph[j][1]] = min(distance[graph[j][1]], distance[graph[j][0]] + graph[j][2]);
		} 
	} 
 
	for (int i = 0; i < E; i++)
    { 
		int x = graph[i][0]; 
		int y = graph[i][1]; 
		int weight = graph[i][2]; 
		if (distance[x] != INT_MAX && 
				distance[x] + weight < distance[y]) 
			cout << "Graph contains negative weight cycle"<< endl; 
	} 

	cout << "Vertex Distance from Source (Node " <<src<<")"<<endl; 
	for (int i = 0; i < V; i++) 
		cout << i << "\t\t" << distance[i] << endl; 
} 
 
int main() 
{ 
	int V = 5;
	int E = 8;

    // Initialized as (fromNode, toNode, edgeWeight)
	vector<vector<int>> graph = { { 0, 1, -1 },
                                  { 0, 2, 4 }, 
					              { 1, 2, 3 },
                                  { 1, 3, 2 }, 
					              { 1, 4, 2 }, 
                                  { 3, 2, 5 },
                                  { 3, 1, 1 },
                                  { 4, 3, -3 } }; 

	BellmanFord(graph, V, E, 0); 
	return 0; 
} 
