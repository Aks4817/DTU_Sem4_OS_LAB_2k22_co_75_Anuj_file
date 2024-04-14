#include <bits/stdc++.h>
using namespace std;

#define NUM_VERTICES 5

int minKey(int weight[], bool included[])
{
	int min_weight = INT_MAX, min_index;

	for (int v = 0; v < NUM_VERTICES; v++)
		if (included[v] == false && weight[v] < min_weight)
			min_weight = weight[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int graph[NUM_VERTICES][NUM_VERTICES])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < NUM_VERTICES; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}

void primMST(int graph[NUM_VERTICES][NUM_VERTICES])
{
	int parent[NUM_VERTICES];
	int weight[NUM_VERTICES];
	bool included[NUM_VERTICES];

	for (int i = 0; i < NUM_VERTICES; i++)
		weight[i] = INT_MAX, included[i] = false;

	weight[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < NUM_VERTICES - 1; count++) {
		int u = minKey(weight, included);
		included[u] = true;

		for (int v = 0; v < NUM_VERTICES; v++)
			if (graph[u][v] && included[v] == false
				&& graph[u][v] < weight[v])
				parent[v] = u, weight[v] = graph[u][v];
	}

	printMST(parent, graph);
}

int main()
{
	int graph[NUM_VERTICES][NUM_VERTICES] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	primMST(graph);

	return 0;
}
