
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
	int src, dest;
};


class Graph
{
public:

	int A, B;

	Edge* edge;
};

Graph* createGraph(int A, int B)
{
	Graph* graph = new Graph();
	graph->A = A;
	graph->B = B;

	graph->edge = new Edge[graph->B * sizeof(Edge)];

	return graph;
}

int find(int parent[], int i)
{
	if (parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void Union(int parent[], int x, int y)
{
	parent[x] = y;
}

int isCycle(Graph* graph)
{

	int* parent = new int[graph->A * sizeof(int)];

	memset(parent, -1, sizeof(int) * graph->A);

	for (int i = 0; i < graph->B; ++i) {
		int x = find(parent, graph->edge[i].src);
		int y = find(parent, graph->edge[i].dest);

		if (x == y)
			return 1;

		Union(parent, x, y);
	}
	return 0;
}

int main()
{

	int A = 4, B = 4;
	Graph* graph = createGraph(A, B);

	graph->edge[0].src = 1;
	graph->edge[0].dest = 2;

	graph->edge[1].src = 2;
	graph->edge[1].dest = 3;

	graph->edge[2].src = 1;
	graph->edge[2].dest = 2;

	if (isCycle(graph))
		cout << "graph contains cycle";
	else
		cout << "graph doesn't contain cycle";

	return 0;
}

