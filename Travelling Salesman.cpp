#include <bits/stdc++.h>
using namespace std;

int travellingSalesmanProblem(vector<vector<int>> &graph, int s, int V)
{
    vector<int> vertex;

    // Store all vertices except source
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;

    // Generate all permutations
    do {
        int current_pathweight = 0;
        int k = s;

        // Calculate current path cost
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }

        // Return to starting city
        current_pathweight += graph[k][s];

        // Update minimum cost
        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main()
{
    int V;

    cout << "Enter number of cities: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter cost adjacency matrix:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
        }
    }

    int s;
    cout << "Enter starting city (0 to " << V-1 << "): ";
    cin >> s;

    int result = travellingSalesmanProblem(graph, s, V);

    cout << "\nMinimum travelling cost: " << result << endl;

    return 0;
}