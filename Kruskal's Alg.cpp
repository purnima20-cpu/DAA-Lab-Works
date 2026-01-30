// C++ program for Kruskal's Algorithm with user input
#include <bits/stdc++.h>
using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    Edge* edge;
};

// Structure for Union-Find
struct subset {
    int parent;
    int rank;
};

// Find function with path compression
int find(subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union by rank
void Union(subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare edges by weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Kruskal's Algorithm
void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];  
    int e = 0; 
    int i = 0;

    sort(graph->edge, graph->edge + graph->E, compareEdges);

    subset* subsets = new subset[V];
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }

    cout << "Following are the edges in the constructed MST\n";
    for (i = 0; i < e; ++i)
        cout << result[i].src << " -- " 
             << result[i].dest << " == " 
             << result[i].weight << endl;
}

// Driver Code
int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> graph->edge[i].src 
            >> graph->edge[i].dest 
            >> graph->edge[i].weight;
    }

    KruskalMST(graph);
    return 0;
}
