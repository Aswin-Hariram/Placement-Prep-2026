#include <bits/stdc++.h>
using namespace std;

// Create adjacency list for undirected graph
vector<vector<int>> createGraph(vector<pair<int,int>> &edges, int V){
    vector<vector<int>> adjList(V);  // 0-based indexing

    for(auto &[u, v] : edges){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

// DFS Utility function to detect cycle
bool isCycleDFSUtil(vector<vector<int>> &adjList, int node, int parent, vector<bool> &visited){
    visited[node] = true;

    for(int nei : adjList[node]){
        if(!visited[nei]){
            if(isCycleDFSUtil(adjList, nei, node, visited))
                return true;
        }
        else if(nei != parent){
            return true;  // back-edge found → cycle
        }
    }
    return false;
}

// Main DFS cycle check (for disconnected graph)
bool DFSCycleCheck(vector<vector<int>> &adjList, int V){
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            if(isCycleDFSUtil(adjList, i, -1, visited))
                return true;
        }
    }
    return false;
}

int main(){
    int V, E;
    cin >> V >> E;

    vector<pair<int,int>> edges;
    edges.reserve(E);

    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    cout << "Creating Undirected Graph...\n";

    vector<vector<int>> adjList = createGraph(edges, V);

    // Printing adjacency list
    for (int i = 0; i < V; i++){
        cout << i << " -> ";
        for (int v : adjList[i]){
            cout << v << " ";
        }
        cout << "\n";
    }

    cout << "Created Undirected Graph...\n\n";
    cout << "Detecting Cycle Using DFS...\n";

    bool isCycle = DFSCycleCheck(adjList, V);

    if(isCycle)
        cout << "Cycle Detected..\n";
    else
        cout << "No Cycle Detected...\n";

    cout << "Cycle Detection Completed...\n";
    return 0;
}
