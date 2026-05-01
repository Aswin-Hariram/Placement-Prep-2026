#include <bits/stdc++.h>
using namespace std;

vector<bool> inCycle;

void checkCycle(int node, vector<bool> &vis, vector<bool> &recStack,
                vector<vector<int>> &adj, vector<int> &path){
    
    vis[node] = true;
    recStack[node] = true;
    path.push_back(node);

    for(int nei : adj[node]){
        if(!vis[nei]){
            checkCycle(nei, vis, recStack, adj, path);
        }
        else if(recStack[nei]){
            // cycle found → mark nodes in current path
            for(int i = path.size()-1; i >= 0; i--){
                inCycle[path[i]] = true;
                if(path[i] == nei) break;
            }
        }
    }

    path.pop_back();
    recStack[node] = false;
}

int main(){
    int V,E;
    cin >> V >> E;
    
    vector<vector<int>> adj(V);
    
    for(int i=0;i<E;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vector<bool> vis(V,false);
    vector<bool> recStack(V,false);
    inCycle.assign(V,false);

    vector<int> path;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            checkCycle(i, vis, recStack, adj, path);
        }
    }
    
    // print nodes having cycle
    for(int i=0;i<V;i++){
        if(inCycle[i]){
            cout << i << " ";
        }
    }
}
