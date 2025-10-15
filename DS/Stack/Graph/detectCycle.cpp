#include<iostream>
#include<queue>
#include<list>
#include<unordered_map>

bool isCycle(int src,  unordered_map<int, list<int>> adj, unordered_map<int, bool> &visited){
     unordered_map<int, int> parent;

     visited[src] = 1;
     parent[src] = -1;

     queue<int> q;
     q.push(src);

     while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour: adj[src]){
            if(visited[neighbour] && neighbour !=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
     }
    return false;
}

using namespace std;

int main(){

    int n,m; cin>>n>>m;

    unordered_map<int, list<int>> adj;

    for(int i=0; i<m; i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    unordered_map<int, bool> visited(false);
   
    for(int i=0; i<n; i++){
        if(!visited[i]){
             bool cycle = isCycle(i, adj, visited);
             if(cycle==true){
                return true;
             }
        }
    }

    return 0;
}