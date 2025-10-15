#include<bits/stdc++.h>
using namespace std;

void topSort(int i, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s){
    visited[i] = 1;

    for(auto j: adj[i]){
        if(!visited[j]){
            topSort(j, visited, adj, s);
        }
    }

    s.push(i);
}

void dfs(int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    
    visited[parent] = 1;

    for (auto i : adj[parent])
    {
        if (!visited[i])
        {
            dfs(i, adj, visited);
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
    }

     unordered_map<int, bool> visited;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            topSort(i, visited, adj, s);
        }
    }

    unordered_map<int, list<int>> transpose;
    for(int i=0; i<n; i++){
        visited[i] =0;
        for(auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    int count=0;
    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(!visited[top]){
            count++;
            dfs(top, transpose, visited);
        }
    }

    return 0;
}