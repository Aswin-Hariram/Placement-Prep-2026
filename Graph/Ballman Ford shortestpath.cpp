#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> createGraph(vector<tuple<int, int, int>> edges, int V) {
    vector<vector<pair<int, int>>> adjList(V);
    for (auto &[u, v, wt] : edges) {
        adjList[u].push_back({v, wt});
    }
    return adjList;
}

void printGraph(vector<vector<pair<int,int>>> &adjList,int V) {
    for (int u = 0; u < V; u++) {
        cout << u << " -> ";
        for (auto &[v, wt] : adjList[u]) {
            cout << "(" << v << "," << wt << ") ";
        }
        cout << "\n";
    }
}

void calShortest(int src, vector<int> &dist, vector<vector<pair<int,int>>> &adjList,int V,vector<tuple<int, int, int>> edges){
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        for(auto &[u,v,wt]:edges){
            if(dist[u]!=1e8&&dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < E; i++) {   
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    cout << "Creating Directed Weighted Graph...\n";
    vector<vector<pair<int,int>>> adjList = createGraph(edges, V);

    cout << "Graph Representation:\n";
    printGraph(adjList, V);

    cout << "Calculating shortest path from 1 to all nodes...\n";
    vector<int> dist(V, 1e8);
    calShortest(1, dist, adjList,V,edges);

    for(int i = 0; i < V; i++){
        cout << i << " => " << dist[i] << endl;
    }
}
