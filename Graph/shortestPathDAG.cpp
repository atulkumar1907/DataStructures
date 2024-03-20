#include<bits/stdc++.h>

using namespace std;



void topSort(int i, unordered_map<int, bool> &visited, unordered_map<int, list<pair<int, int>>> &adj, stack<int> &s){
    visited[i] = 1;

    for(auto j: adj[i]){
        if(!visited[j.first]){
            topSort(j.first, visited, adj, s);
        }
    }

    s.push(i);
}

void shortestPathDAG(){

}

int main(){

     int n, m;
    cin>>n>>m;

    unordered_map<int, list<pair<int, int>>> adj;

    for(int i=0; i<m; i++){
        int u, v, w;
        pair<int, int> p = make_pair(v, w);

        adj[u].push_back(p);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    stack<int> s;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            topSort(i, visited, adj, s);
        }
    }

     int src = 1;

    vector<int> dist(n);

    for(int i=0; i<n; i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

     while(!s.empty()){
       int top = s.top();
        s.pop();

        if(dist[top]!=INT_MAX){
            for(auto i: adj[top]){
                if(dist[top]+  i.second < dist[i.first]){
                    dist[i.first] = dist[i.first] + i.second;
                }
            }
        }
    }
     
}