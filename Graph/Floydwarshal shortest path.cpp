#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> createAdjMatrix(vector<tuple<int,int,int>> edges, int V) {
    vector<vector<long long>> adjMatrix(V, vector<long long>(V, -1));
    for (auto [u, v, wt] : edges) {
        adjMatrix[u][v] = wt;
    }
    return adjMatrix;
}

void FloydWarshall(vector<vector<long long>> &costMatrix, int V) {
    const long long INF = 1e15; // large enough to avoid overflow

    // Initialize graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (costMatrix[i][j] == -1) costMatrix[i][j] = INF;
            if (i == j) costMatrix[i][j] = 0;
        }
    }

    // Floyd–Warshall DP
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (costMatrix[i][k] < INF && costMatrix[k][j] < INF) {
                    costMatrix[i][j] = min(costMatrix[i][j], costMatrix[i][k] + costMatrix[k][j]);
                }
            }
        }
    }

    // Convert INF back to -1
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (costMatrix[i][j] == INF) costMatrix[i][j] = -1;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<tuple<int,int,int>> edges;

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    cout << "Creating Directed Graph AdjMatrix...\n";
    vector<vector<long long>> adjMatrix = createAdjMatrix(edges, V);

    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Created Directed Graph AdjMatrix...\n";

    cout << "Calculating shortest path using FloydWarshall..\n";
    FloydWarshall(adjMatrix, V);

    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int j = 0; j < V; j++) {
            if (adjMatrix[i][j] == -1) cout << "INF ";
            else cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Completed Calculating shortest path using FloydWarshall..\n";
}
