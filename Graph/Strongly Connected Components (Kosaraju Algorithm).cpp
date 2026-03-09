#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>> &adj, stack<int> &st, vector<bool> &visited){
    visited[node] = true;

    for(int nei : adj[node]){
        if(!visited[nei])
            dfs1(nei, adj, st, visited);
    }

    st.push(node);
}

void dfs2(int node, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = true;
    cout << node << " ";

    for(int nei : adj[node]){
        if(!visited[nei])
            dfs2(nei, adj, visited);
    }
}

int main(){

    int V,E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    while(E--){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);   // directed
    }

    stack<int> st;
    vector<bool> visited(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i])
            dfs1(i,adj,st,visited);
    }

    vector<vector<int>> rev(V);

    for(int i=0;i<V;i++){
        for(int nei:adj[i]){
            rev[nei].push_back(i);
        }
    }

    fill(visited.begin(),visited.end(),false);

    cout<<"Strongly Connected Components:\n";

    while(!st.empty()){
        int node = st.top();
        st.pop();

        if(!visited[node]){
            dfs2(node,rev,visited);
            cout<<endl;
        }
    }
}
