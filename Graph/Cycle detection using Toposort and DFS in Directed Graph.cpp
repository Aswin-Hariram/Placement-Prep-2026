// You are using GCC
// You are using GCC
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> create_adj(vector<pair<int,int>> &edges, int V) {
    vector<vector<int>> adj(V + 1);
    for (auto &[u, v] : edges) {
        adj[u].push_back(v);
    }
    return adj;
}
bool cycleUtil(vector<vector<int>> &adj,int node,vector<bool> &visited,vector<bool> &recStack){
    
    if(recStack[node]) return true;
    if(visited[node]) return false;
    
    
    visited[node] = true;
    recStack[node] = true;
    
    for(int nei:adj[node]){
        if(cycleUtil(adj,nei,visited,recStack)){
            return true;
        }
    }
    recStack[node] = false;
    return false;
    
}
bool checkCycle(vector<vector<int>> adj,int V){
    vector<bool> visited(V+1,false);
    vector<bool> recStack(V+1,false);
    
    for(int i=1;i<=V;i++){
        if(!visited[i]&&cycleUtil(adj,i,visited,recStack)){
            return true;
        }
    }
    return false;
}

bool checkCycleTopo(vector<vector<int>> adj,int V){
    
    vector<int> indegree(V+1,0);
    
    for(int i=1;i<=V;i++){
        for(int nei:adj[i]){
            indegree[nei]++;
        }
    }
    int visited = 0;
    queue<int> q;
    
    for(int i=1;i<=V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        visited++;
        int top = q.front();
        q.pop();
        for(int nei:adj[top]){
            indegree[nei]--;
            if(indegree[nei]==0){
                q.push(nei);
            }
        }
    }
    return (visited!=V);
    
    
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int,int>> edges;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    cout<<"Creating Directed Graph....\n";
    vector<vector<int>> adj = create_adj(edges, V);

    for (int i = 1; i <= V; i++) {
        cout << i << " -> ";
        for (int v : adj[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
    cout<<"Detecting Cycle in Directed Graph Using DFS....\n";
    bool isCycle = checkCycle(adj,V);
    if(isCycle){
        cout<<"Cycle found....\n";
    }
    else{
        cout<<"No Cycle found...\n";
    }
    cout<<"Cycle Detection in Directed Graph Completed....";
    
    
    cout<<"Detecting Cycle in Directed Graph Using Toposort....\n";
    isCycle = checkCycleTopo(adj,V);
    if(isCycle){
        cout<<"Cycle found....\n";
    }
    else{
        cout<<"No Cycle found...\n";
    }
    cout<<"Cycle Detection in Directed Graph Completed....";
    

    return 0;
}
