#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int parent, int timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> adj,  unordered_map<int, bool> visited){
    visited[i] = 1;

    disc[i] = low[i] = timer++;

    for(auto neighbour: adj[i]){
        if(neighbour==parent){
            continue;
        }
        if(!visited[neighbour]){
            dfs(neighbour, i, timer, disc, low, result, adj, visited);
            low[i] = min(low[i], low[neighbour]);

            if(low[neighbour]>disc[i]){
                vector<int> ans;
                ans.push_back(i);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else{
            low[i] = min(low[i], disc[neighbour]);
        }
    }

}

int main(){

    cout<<"Enter no. of nodes and Edges: ";
    int n, m;
    cin >> n >> m;

    unordered_map<int, list<int>> adj(n);

    cout<<"Enter edges: ";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer =0;
    vector<int> disc(n);
    vector<int> low(n);
    int parent = -1;
    unordered_map<int, bool> visited(n);

    for(int i=0; i<n; i++){
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, result, adj, visited);
        }
    }

    return 0;
}
