#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void printVertexCover() {
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                for (auto v : adj[u]) {
                    if (!visited[v]) {
                        visited[u] = true;
                        visited[v] = true;
                        break;
                    }
                }
            }
        }

        cout << "\nApproximate Vertex Cover: ";
        for (int i = 0; i < V; i++) {
            if (visited[i])
                cout << i << " ";
        }
        cout << endl;

        delete[] visited;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v) format:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printVertexCover();

    return 0;
}